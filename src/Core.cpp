/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(const std::string& lib)
{
    Library::getInstance(lib);
    this->_libIndex = 0;
    for (; this->_libIndex < Library::getInstance()->getLibs().size(); this->_libIndex++)
        if (Library::getInstance()->getLibs()[this->_libIndex] == lib)
            break;
    if (this->_libIndex == Library::getInstance()->getLibs().size())
        throw LibraryException("Library not found (" + lib + ")");
    this->_dm = Library::getInstance()->createDisplayModule();
    this->_state = Core::MENU;
    this->_newLib = lib;
    this->_rb = nullptr;
    this->_inputName = new EGE::Input(this->_dm, EGE::Vector<int>(5,6));
    this->initDrawable();
    this->initEvent();
    this->_gameIndex = 0;
    this->_state = Core::MENU;
    for (auto const& [key, value] : Library::getInstance()->getGameFunctions()) {
        EGE::IGameModule *game = value();
        game->load(this->_dm);
        this->_gamesNames.push_back(key);
        this->_games.push_back(game);
    }
}

Core::~Core()
{
    this->destroyDrawable();
    delete this->_inputName;
    Library::getInstance()->destroyDisplayModule(this->_dm);
    Library::deleteInstance();
}

void Core::loopGame()
{
    this->_games[this->_gameIndex]->getNextFrame();
}

void Core::loopMenu()
{
    for (auto &drawable : this->_drawables)
        drawable->draw(this->_dm->getWindow());
    this->_inputName->draw(this->_dm->getWindow());
}

void Core::loop()
{
    while (this->_dm->windowIsOpen()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 8));
        this->_dm->windowClear();
        this->_dm->windowPollEvent();
        this->chooseState();
        this->_dm->windowDisplay();
        this->switchLib();
    }
}

void Core::switchLib()
{
    Core::STATE_MACHINE state = this->_state;
    if (state == Core::RELOAD_MENU) {
        this->reloadMenu();
    } else if (state == Core::RELOAD_GAME) {
        this->reloadGame();
    } else if (state == Core::INIT_GAME) {
        this->initGame();
    } else if (state == Core::CHANGE_GAME) {
        this->_gameIndex = (this->_gameIndex + 1) % this->_games.size();
        this->_state = Core::RELOAD_GAME;
    }
}

void Core::chooseState()
{
    if (this->_state == Core::MENU) {
        this->loopMenu();
    } else if (this->_state == Core::GAME) {
        this->loopGame();
    } else if (this->_state == Core::EXIT) {
        this->_dm->windowClose();
    }
}

void Core::initEvent()
{
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Return, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_state = Core::INIT_GAME;
            std::string gameName = this->_rbg->getElements()[this->_rbg->getSelectedElement()]->getText();
            Library::getInstance()->setCurrentGameLib(gameName);
            this->_gameIndex = std::find(this->_gamesNames.begin(), this->_gamesNames.end(), gameName) - this->_gamesNames.begin();
            this->_newLib = this->_rb->getElements()[this->_rb->getSelectedElement()]->getText();
        });

    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::KeyUp, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_rb->selectPrevElement();
        }
    );

    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::KeyDown, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_rb->selectNextElement();
        }
    );
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::KeyLeft, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_rbg->selectPrevElement();
        }
    );

    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::KeyRight, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_rbg->selectNextElement();
        }
    );
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::BackSpace, EGE::Event::PRESSED),
        [&]() {
            this->_inputName->removeChar();
        }
    );

    for (EGE::Event::Keyboard key = EGE::Event::Keyboard::A; key <= EGE::Event::Keyboard::Z; key = static_cast<EGE::Event::Keyboard>(key + 1)) {
        this->_dm->bindKey(
            std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
                key, EGE::Event::JUST_PRESSED),
            [this, key]() {
                this->_inputName->addChar(static_cast<char>(key + 65));
            }
        );
    }
    for (EGE::Event::Keyboard key = EGE::Event::Keyboard::Num0; key <= EGE::Event::Keyboard::Num9; key = static_cast<EGE::Event::Keyboard>(key + 1)) {
        this->_dm->bindKey(
            std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
                key, EGE::Event::JUST_PRESSED),
            [this, key]() {
                this->_inputName->addChar(static_cast<char>(key + 22));
            }
        );
    }
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Space, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_inputName->addChar(' ');
        }
    );
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Escape, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_state = Core::EXIT;
        }
    );
}

void Core::initDrawable()
{
    int i = 1;
    this->_rb = new EGE::RadioButton();
    this->_rbg = new EGE::RadioButton();
    EGE::IText *textName = this->_dm->createText("Enter your name:", EGE::Vector<int>(5, 5), EGE::Color(255,255,255));
    this->_drawables.push_back(textName);

    EGE::IText *textLib = this->_dm->createText("Choose your game", EGE::Vector<int>(25, 0), EGE::Color(255, 255, 255, 255));
    this->_drawables.push_back(textLib);
    for (auto const& [key, value] : Library::getInstance()->getGameFunctions())
        this->_rbg->addElement(this->_dm->createButton(key, EGE::Vector<int>(25, i++)));
    this->_drawables.push_back(this->_rbg);
    i = 0;
    EGE::IText *text = this->_dm->createText("Choose your library", EGE::Vector<int>(0, i++), EGE::Color(255, 255, 255, 255));
    this->_drawables.push_back(text);
    for (auto const& [key, value] : Library::getInstance()->getFunctions())
        this->_rb->addElement(this->_dm->createButton(key, EGE::Vector<int>(0, i++)));
    this->_drawables.push_back(this->_rb);
}

void Core::initGameEvent()
{
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::KeyRight, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_state = Core::RELOAD_GAME;
            this->_libIndex += 1;
            if (Library::getInstance()->getLibs().size() == this->_libIndex)
                this->_libIndex = 0;
            this->_newLib = Library::getInstance()->getLibs()[this->_libIndex];
        }
    );
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::KeyLeft, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_state = Core::RELOAD_GAME;
            this->_libIndex -= 1;
            if (this->_libIndex < 0)
                this->_libIndex = Library::getInstance()->getLibs().size() - 1;
            this->_newLib = Library::getInstance()->getLibs()[this->_libIndex];
        }
    );
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::R, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_state = Core::INIT_GAME;
        }
    );
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Escape, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_state = Core::RELOAD_MENU;
        }
    );
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::KeyUp, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_state = Core::CHANGE_GAME;
        }
    );
    this->_dm->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::KeyDown, EGE::Event::JUST_PRESSED),
        [&]() {
            this->_state = Core::CHANGE_GAME;
        }
    );
}

void Core::initGame()
{
    this->_dm->windowClose();
    Library::getInstance()->destroyDisplayModule(this->_dm);
    Library::getInstance(this->_newLib, true);
    this->_dm = Library::getInstance()->createDisplayModule();
    this->initGameEvent();
    this->_games[this->_gameIndex]->load(this->_dm);
    this->_state = Core::GAME;
}

void Core::reloadMenu()
{
    this->destroyDrawable();
    this->_inputName->removeText();
    this->_dm->windowClose();
    Library::getInstance()->destroyDisplayModule(this->_dm);
    Library::getInstance(this->_newLib, true);
    this->_dm = Library::getInstance()->createDisplayModule();
    this->_inputName->reload(this->_dm, EGE::Vector<int>(5,6));
    this->initDrawable();
    this->initEvent();
    this->_state = Core::MENU;
}

void Core::reloadGame()
{
    this->_dm->windowClose();
    Library::getInstance()->destroyDisplayModule(this->_dm);
    Library::getInstance(this->_newLib, true);
    this->_dm = Library::getInstance()->createDisplayModule();
    this->initGameEvent();
    this->_games[this->_gameIndex]->reload(this->_dm);
    this->_state = Core::GAME;
}

void Core::destroyDrawable()
{
    for (EGE::IButton *elem : this->_rb->getElements())
        delete elem;
    for (EGE::IDrawable *drawable : this->_drawables)
        delete drawable;
    this->_rb->clearElements();
    this->_drawables.clear();
}

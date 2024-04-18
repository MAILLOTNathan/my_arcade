/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEEvent
*/

#include "NCURSEEvent.hpp"

Event::Event()
{
    this->_mouseEnabled = true;
    this->_keyboardEnabled = true;
    this->_initKeyboardTranslate();
}

Event::~Event()
{
}

void Event::bindMouseScroll(std::unique_ptr<EGE::IWindow> window, std::function<void(double, double)> func)
{
    this->_mouseScrollFunc = func;
}

void Event::unbindMouseScroll(void)
{
    this->_mouseScrollFunc = nullptr;
}

void Event::manageKeyboardEvent(EGE::IWindow *window)
{
    int key = getch();

    if (key == ERR)
        return;
    mvprintw(0,0,"[%d]\n", key);
    WINDOW *win = dynamic_cast<Window *>(window)->getWindow();
    std::uint8_t keyButtonType = 0;
    bool keyPressed = false;
    for (auto it = this->_keyMap.begin(); it != this->_keyMap.end(); it++) {
        keyButtonType = it->first->getType();
        keyPressed = it->first->isPressed();
        if (this->_keyboardTranslate[it->first->getTrigger()] == key && (!keyPressed || keyButtonType == EGE::Event::PRESSED)) {
            it->first->setPressed(true);
            if (keyButtonType <= EGE::Event::JUST_PRESSED)
                it->second();
        }
        it->first->setPressed(false);
        if (this->_keyboardTranslate[it->first->getTrigger()] == key && (keyPressed || keyButtonType == EGE::Event::RELEASED)) {
            it->first->setPressed(false);
            if (keyButtonType >= EGE::Event::RELEASED)
                it->second();
        }
    }
}

void Event::manageMouseEvent(EGE::IWindow *window)
{
    (void) window;
}

void Event::manageEvent(EGE::IWindow *window)
{
    if (this->_keyboardEnabled)
        this->manageKeyboardEvent(window);
}

std::uint32_t Event::keyboardTranslate(EGE::Event::Keyboard button)
{
    return this->_keyboardTranslate[button];
}

std::uint32_t Event::mouseTranslate(EGE::Event::Mouse button)
{
    return button;
}

void Event::_initKeyboardTranslate()
{
    this->_keyboardTranslate[EGE::Event::Keyboard::A] = 'a';
    this->_keyboardTranslate[EGE::Event::Keyboard::B] = 'b';
    this->_keyboardTranslate[EGE::Event::Keyboard::C] = 'c';
    this->_keyboardTranslate[EGE::Event::Keyboard::D] = 'd';
    this->_keyboardTranslate[EGE::Event::Keyboard::E] = 'e';
    this->_keyboardTranslate[EGE::Event::Keyboard::F] = 'f';
    this->_keyboardTranslate[EGE::Event::Keyboard::G] = 'g';
    this->_keyboardTranslate[EGE::Event::Keyboard::H] = 'h';
    this->_keyboardTranslate[EGE::Event::Keyboard::I] = 'i';
    this->_keyboardTranslate[EGE::Event::Keyboard::J] = 'j';
    this->_keyboardTranslate[EGE::Event::Keyboard::K] = 'k';
    this->_keyboardTranslate[EGE::Event::Keyboard::L] = 'l';
    this->_keyboardTranslate[EGE::Event::Keyboard::M] = 'm';
    this->_keyboardTranslate[EGE::Event::Keyboard::N] = 'n';
    this->_keyboardTranslate[EGE::Event::Keyboard::O] = 'o';
    this->_keyboardTranslate[EGE::Event::Keyboard::P] = 'p';
    this->_keyboardTranslate[EGE::Event::Keyboard::Q] = 'q';
    this->_keyboardTranslate[EGE::Event::Keyboard::R] = 'r';
    this->_keyboardTranslate[EGE::Event::Keyboard::S] = 's';
    this->_keyboardTranslate[EGE::Event::Keyboard::T] = 't';
    this->_keyboardTranslate[EGE::Event::Keyboard::U] = 'u';
    this->_keyboardTranslate[EGE::Event::Keyboard::V] = 'v';
    this->_keyboardTranslate[EGE::Event::Keyboard::W] = 'w';
    this->_keyboardTranslate[EGE::Event::Keyboard::X] = 'x';
    this->_keyboardTranslate[EGE::Event::Keyboard::Y] = 'y';
    this->_keyboardTranslate[EGE::Event::Keyboard::Z] = 'z';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num0] = '0';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num1] = '1';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num2] = '2';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num3] = '3';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num4] = '4';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num5] = '5';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num6] = '6';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num7] = '7';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num8] = '8';
    this->_keyboardTranslate[EGE::Event::Keyboard::Num9] = '9';
    this->_keyboardTranslate[EGE::Event::Keyboard::Escape] = 27;
    this->_keyboardTranslate[EGE::Event::Keyboard::Space] = ' ';
    this->_keyboardTranslate[EGE::Event::Keyboard::Return] = 10;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyUp] = KEY_UP;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyDown] = KEY_DOWN;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyLeft] = KEY_LEFT;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyRight] = KEY_RIGHT;
    this->_keyboardTranslate[EGE::Event::Keyboard::BackSpace] = KEY_BACKSPACE;
}

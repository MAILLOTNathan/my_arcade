/*
** EPITECH PROJECT, 2023
** etib-game-engine [SSH: 10.106.0.254]
** File description:
** Library
*/

#include "Library.hpp"

Library *Library::_instance{nullptr};
std::mutex Library::_mutex;

Library *Library::getInstance(const std::string& path, bool force)
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (_instance == nullptr) {
        _instance = new Library(path);
        _instance->init();
    }
    if (force) {
        _instance->setCurrentLib(path);
    }
    return _instance;
}

Library *Library::getInstance()
{
    std::lock_guard<std::mutex> lock(_mutex);
    if (_instance == nullptr)
        throw LibraryException("Library instance is not initialized");
    return _instance;
}

bool isGameModule(void *handle)
{
    return dlsym(handle, "createGameModule") != NULL;
}

bool isDisplayModule(void *handle)
{
    return dlsym(handle, "createDisplayModule") != NULL;
}

void Library::init()
{
    try {
        std::vector<std::string> files = Utils::getContentFolder("./lib");
        void *handle = NULL;

        for (const auto& path : files) {
            handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!handle)
                throw LibraryException(dlerror());
            this->_handles[path] = handle;
            if (isDisplayModule(handle)) {
                LOAD_SYM(this, _createFunctions[path], "createDisplayModule", EGE::IDisplayModule*(*)());
                LOAD_SYM(this, _destroyFunctions[path], "destroyDisplayModule", void(*)(EGE::IDisplayModule *));
                this->_libs.push_back(path);
            } else if (isGameModule(handle)) {
                LOAD_SYM(this, _createGameFunctions[path], "createGameModule", EGE::IGameModule *(*)());
                this->_gameLibs.push_back(path);
            } else
                throw LibraryException("Library is not a valid module");
        }
    } catch (const std::exception& e) {
        std::string message = "Library (init) \n\t";
        message += e.what();
        throw LibraryException(message);
    }
}

EGE::IGameModule *Library::createGameModule()
{
    return this->_createGameFunctions[this->_currentGameLib]();
}

void Library::destroyGameModule(EGE::IGameModule *gameModule)
{
    return this->_destroyGameFunctions[this->_currentGameLib](gameModule);
}

EGE::IDisplayModule *Library::createDisplayModule()
{
    return this->_createFunctions[this->_currentLib]();
}

void Library::destroyDisplayModule(EGE::IDisplayModule *displayModule)
{
    return this->_destroyFunctions[this->_currentLib](displayModule);
}

void Library::setCurrentLib(const std::string& lib)
{
    this->_currentLib = lib;
}

void Library::setCurrentGameLib(const std::string& lib)
{
    this->_currentGameLib = lib;
}

std::vector<std::string> Library::getLibs() const
{
    return this->_libs;
}

std::map<std::string,std::function<EGE::IDisplayModule*()>> Library::getFunctions() const
{
    return this->_createFunctions;
}

std::map<std::string, std::function<EGE::IGameModule*()>> Library::getGameFunctions() const
{
    return this->_createGameFunctions;
}

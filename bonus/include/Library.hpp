/*
** EPITECH PROJECT, 2023
** etib-game-engine [SSH: 10.106.0.254]
** File description:
** Library
*/

#ifndef LIBRARY_HPP_
#define LIBRARY_HPP_

#include "IDisplayModule.hpp"
#include "ADisplayModule.hpp"
#include "IGameModule.hpp"
#include "AGameModule.hpp"
#include <iostream>
#include <dlfcn.h>
#include <mutex>
#include <map>
#include <string>
#include <functional>
#include <memory>
#include <vector>
#include <exception>

#include "Error.hpp"
#include "Utils.hpp"

#define LOAD_SYM(lib, var, sym, type) \
    if ((type)dlsym(lib->_handles[path], sym) != NULL) \
        var = (type)dlsym(lib->_handles[path], sym); \

class LibraryException : public Error {
    public:
        LibraryException(const std::string &message) : Error(message) {}
        ~LibraryException() {}
};
class Library {
    public:
        Library(Library &other) = delete;
        void operator=(const Library &) = delete;
        static Library *getInstance(const std::string& path, bool force = false);
        static Library *getInstance();

        EGE::IDisplayModule *createDisplayModule();
        void destroyDisplayModule(EGE::IDisplayModule *displayModule);
        EGE::IGameModule *createGameModule();
        void destroyGameModule(EGE::IGameModule *gameModule);

        void setCurrentLib(const std::string &lib);
        void setCurrentGameLib(const std::string &lib);
        std::vector<std::string> getLibs() const;
        std::map<std::string,std::function<EGE::IDisplayModule*()>> getFunctions() const;
        std::map<std::string,std::function<EGE::IGameModule *()>> getGameFunctions() const;
    protected:
        Library(const std::string& path) : _currentLib(path) {}
        ~Library() {}
        void init();
        std::map<std::string, void *> _handles;
        std::string _currentLib;
        std::string _currentGameLib;


        // function ptrs
        std::vector<std::string> _libs;
        std::vector<std::string> _gameLibs;
        std::map<std::string,std::function<EGE::IDisplayModule*()>> _createFunctions;
        std::map<std::string,std::function<void(EGE::IDisplayModule*)>> _destroyFunctions;
        std::map<std::string,std::function<EGE::IGameModule*()>> _createGameFunctions;
        std::map<std::string,std::function<void(EGE::IGameModule*)>> _destroyGameFunctions;
    private:
        static Library *_instance;
        static std::mutex _mutex;
};

#endif /* !LIBRARY_HPP_ */

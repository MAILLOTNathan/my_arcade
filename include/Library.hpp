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

/// @brief Load symbols from .so file.
#define LOAD_SYM(lib, var, sym, type) \
    if ((type)dlsym(lib->_handles[path], sym) != NULL) \
        var = (type)dlsym(lib->_handles[path], sym); \

class LibraryException : public Error {
    public:
        LibraryException(const std::string &message) : Error(message) {}
        ~LibraryException() {}
};

/// @brief Class which load and store libraries from `.so` files.
class Library {
    public:
        Library(Library &other) = delete;
        void operator=(const Library &) = delete;

        /// @brief Return current instance of the library loaded from the `path`.
        /// @param path Path to the library you want to get.
        /// @param force Indicate if you want to change the current library used.
        static Library *getInstance(const std::string& path, bool force = false);

        /// @brief Return current instance of the library loaded from the `path`.
        static Library *getInstance();

        /// @brief Delete the current instance of the `Library`.
        static void deleteInstance();

        /// @brief Create a `Display Module` instance.
        EGE::IDisplayModule *createDisplayModule();

        /// @brief Destroy the display module passed as param.
        /// @param displayModule Display module to destroy.
        void destroyDisplayModule(EGE::IDisplayModule *displayModule);

        /// @brief Create a `Game Module` instance.
        EGE::IGameModule *createGameModule();

        /// @brief Destroy the game module passed as param.
        /// @param gameModule Game module to destroy.
        void destroyGameModule(EGE::IGameModule *gameModule);

        /// @brief Set the current instance of the `graphical library` loaded from the `path`.
        /// @param lib A path to the graphical library you want to load.
        void setCurrentLib(const std::string &lib);

        /// @brief Set the current instance of the `game library` loaded from the `path`.
        /// @param lib A path to the game library you want to load.
        void setCurrentGameLib(const std::string &lib);

        /// @brief Return all the `graphical libraries` loaded in current context.
        std::vector<std::string> getLibs() const;

        /// @brief Return a `map` which contains the graphical libraries `names` with the assiociated creators `functions`.
        std::map<std::string,std::function<EGE::IDisplayModule*()>> getFunctions() const;

        /// @brief Return a `map` which contains the game libraries `names` with the assiociated creators `functions`.
        std::map<std::string,std::function<EGE::IGameModule *()>> getGameFunctions() const;
    protected:
        Library(const std::string& path) : _currentLib(path) {}
        ~Library() {
            for (auto &handle : _handles)
                dlclose(handle.second);
        }

        /// @brief Initialize the libraries from the `./lib` directory.
        void init();

        std::map<std::string, void *> _handles;     // Handled libraries.
        std::string _currentLib;                    // Current `graphical` library.
        std::string _currentGameLib;                // Current `game` library.

        std::vector<std::string> _libs;             // List of `graphical` libraries.
        std::vector<std::string> _gameLibs;         // List of `game` libraries.
        std::map<std::string,std::function<EGE::IDisplayModule*()>> _createFunctions;       // `Graphical` creators functions.
        std::map<std::string,std::function<void(EGE::IDisplayModule*)>> _destroyFunctions;  // `Graphical` destructors functions.
        std::map<std::string,std::function<EGE::IGameModule*()>> _createGameFunctions;      // `Game` creators functions.
        std::map<std::string,std::function<void(EGE::IGameModule*)>> _destroyGameFunctions; // `Game` destructors functions.
    private:
        static Library *_instance;  // Current instance of the `library manager`.
        static std::mutex _mutex;   // Mutex.
};

#endif /* !LIBRARY_HPP_ */

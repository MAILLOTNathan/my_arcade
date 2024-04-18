/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Core
*/

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <chrono>
#include <thread>

#include "IWindow.hpp"
#include "IDisplayModule.hpp"
#include "Library.hpp"
#include "GUI/RadioButton.hpp"
#include "GUI/Input.hpp"
#include "IGameModule.hpp"

/// @brief Class which handles the `behaviour` of `main` arcade program.
class Core {
    public:
        /// @brief All the `states` which represent the state machine.
        enum STATE_MACHINE {
            MENU,           // Menu state.
            GAME,           // Game state.
            RELOAD_GAME,    // Reload game state.
            RELOAD_MENU,    // Reload menu state.
            INIT_GAME,      // Initialisation game state.
            CHANGE_GAME,    // Switching game in progress.
            EXIT            // Exiting the Core Program.
        };

        /// @brief Graphic and Game manager entity for the arcade project.
        /// @param lib Path to the graphic library file.
        Core(const std::string& lib);
        /// @brief Destructor for Core program.
        ~Core();

        /// @brief Loop which able the user to `choose` between the `games` and the `graphical libraries`.
        void loopMenu();

        /// @brief Loop on the `GAME` state.
        void loopGame();

        /// @brief Function that apply the `state machine`.
        void chooseState();

        /// @brief Main loop on which the arcade will loop.
        /// It's like the "graphical routine" (clear -> pollEvent -> draw -> display).
        void loop();

        /// @brief `Switch` graphical library in `real time`.
        void switchLib();

        /// @brief `Bind` keyboard events with actions.
        void initEvent();

        /// @brief Set core's menu items which represents the `.so` files graphical libraries you can load.
        void initDrawable();

        /// @brief Set core's menu items which represents the `.so` files games you can load.
        void initGameEvent();

        /// @brief `Initialize` the game loaded.
        void initGame();

        /// @brief `Reload` the menu (called after switching graphical library).
        void reloadMenu();

        /// @brief `Reload` the game (called after switching graphical library).
        void reloadGame();

        /// @brief Destroy core's menu items.
        void destroyDrawable();


    private:
        enum STATE_MACHINE _state;                  // Current `state` of the core program.
        EGE::IGameModule *_game;                    // Current `Game Module` loaded.
        EGE::IDisplayModule *_dm;                   // Current `Graphic Module` loaded.
        EGE::RadioButton *_rb;                      // Selector on graphics libraries.
        EGE::RadioButton *_rbg;                     // Selector on games libraries.
        int _libIndex;                              // Index of the graphic library in the list of libraries.
        std::string _newLib;                        // Name of the new library which will be loaded.
        std::vector<EGE::IDrawable *> _drawables;   // List of drawables for the main menu.
        EGE::Input *_inputName;                     // Input field which allows the user to set his username for the scoreboard.
        std::vector<EGE::IGameModule *>_games;      // All the games loaded
        std::vector<std::string> _gamesNames;       // All the games names loaded.
        int _gameIndex;                             // Index of the current Game library.
};

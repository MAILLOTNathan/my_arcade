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

class Core {
    public:

        enum STATE_MACHINE {
            MENU,
            GAME,
            RELOAD_GAME,
            RELOAD_MENU,
            INIT_GAME
        };

        Core(const std::string& lib);
        ~Core();

        void loopMenu();
        void loopGame();

        void loop();
        void switchLib();

        void chooseState();

        void initEvent();
        void initDrawable();

        void initGameEvent();
        void initGame();

        void reloadMenu();
        void reloadGame();

        void destroyDrawable();


    private:
        enum STATE_MACHINE _state;
        EGE::IDisplayModule *_dm;
        EGE::RadioButton *_rb;
        EGE::RadioButton *_rbg;
        int _libIndex;
        std::string _newLib;
        std::vector<EGE::IDrawable *> _drawables;
        EGE::Input *_inputName;
        EGE::IGameModule *_game;
};

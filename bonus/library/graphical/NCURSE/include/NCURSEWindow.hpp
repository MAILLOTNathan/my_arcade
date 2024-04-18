/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEWindow
*/

#pragma once

#include <iostream>
#include <memory>
#include <chrono>
#include <thread>

#include <ncurses.h>

#include "AWindow.hpp"
#include "NCURSEEvent.hpp"

#define BUTTON_NORMAL 1
#define BUTTON_HOVER 2
#define BUTTON_CLICKED 3

class Window : public EGE::AWindow {
    public:
        Window(const std::string &title, unsigned int x, unsigned int y);
        ~Window();

        bool isOpen() const override;
        void clear() override;
        void display() override;
        void close() override;
        void pollEvent() override;

        WINDOW *getWindow() const;

    protected:
    private:
        WINDOW *_window;
        bool _opened;
        std::string _title;
};
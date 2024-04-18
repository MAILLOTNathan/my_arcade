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


#define BUTTON_NORMAL 1     // Color pair id for the normal state of the button.
#define BUTTON_HOVER 2      // Color pair id for the hover state of the button.
#define BUTTON_CLICKED 3    // Color pair id for the clicked state of the button.

/// @brief NCURSE Window implementation.
class Window : public EGE::AWindow {
    public:
        /// @brief Creates a NCURSE window.
        /// @param title Title of the window.
        /// @param x Width of the window.
        /// @param y Height of the window.
        Window(const std::string &title, unsigned int x, unsigned int y);

        /// @brief Destroys a NCURSE window.
        ~Window();

        /// @brief Checks if the window is open.
        bool isOpen() const override;

        /// @brief Clears the window.
        void clear() override;

        /// @brief Displays the window.
        void display() override;

        /// @brief Closes the window.
        void close() override;

        /// @brief Polls the events.
        void pollEvent() override;

        /// @brief Returns the window stored.
        WINDOW *getWindow() const;

    protected:
    private:
        WINDOW *_window;    // The window of this window.
        bool _opened;       // The state of the window.
        std::string _title; // The title of the window.
};
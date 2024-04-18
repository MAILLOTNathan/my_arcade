/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Window
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <memory>
#include "AWindow.hpp"
#include "SDLEvent.hpp"

/// @brief Class representing a window in SDL2.
class Window : public EGE::AWindow {
    public:
        /// @brief Creates a new window.
        /// @param title Title of the window.
        /// @param x Width of the window.
        /// @param y Height of the window.
        Window(const std::string& title, unsigned int x, unsigned int y);

        /// @brief Destroys the window.
        ~Window();

        /// @brief Returns whether the window is currently open or closed.
        bool isOpen() const override;

        /// @brief Clears the window.
        void clear() override;

        /// @brief Displays the window.
        void display() override;

        /// @brief Close the window.
        void close() override;

        /// @brief `Catches` and `manages` events.
        void pollEvent() override;

        /// @brief Returns the SDL window stored.
        SDL_Window *getWindow() const;

        /// @brief Returns the SDL renderer stored.
        SDL_Renderer *getRenderer() const;

    protected:
    private:
        SDL_Window* _window;        // The SDL_Window of this window.
        SDL_Renderer* _renderer;    // The SDL_Renderer of this window.
};

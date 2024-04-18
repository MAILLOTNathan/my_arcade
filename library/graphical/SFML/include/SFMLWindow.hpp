/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Window
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <memory>
#include "AWindow.hpp"
#include "SFMLEvent.hpp"

/// @brief Class representing a window in SFML.
class Window : public EGE::AWindow {
    public:
        /// @brief Creates a new window.
        /// @param title Title of the window.
        /// @param x Width of the window.
        /// @param y Height of the window.
        Window(const std::string &title, unsigned int x, unsigned int y);

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

        /// @brief Returns the SFML window stored.
        sf::RenderWindow *getWindow() const;

    protected:
    private:
        sf::RenderWindow *_window;  // The SFML window of this window.
};

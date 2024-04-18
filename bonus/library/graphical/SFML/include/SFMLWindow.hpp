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

class Window : public EGE::AWindow {
    public:
        Window(const std::string &title, unsigned int x, unsigned int y);
        ~Window();

        bool isOpen() const override;
        void clear() override;
        void display() override;
        void close() override;
        void pollEvent() override;

        sf::RenderWindow *getWindow() const;

    protected:
    private:
        sf::RenderWindow *_window;
};

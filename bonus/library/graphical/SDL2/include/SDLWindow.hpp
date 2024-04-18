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

class Window : public EGE::AWindow {
    public:
        Window(const std::string& title, unsigned int x, unsigned int y);
        ~Window();

        bool isOpen() const override;
        void clear() override;
        void display() override;
        void close() override;
        void pollEvent() override;

        SDL_Window *getWindow() const;
        SDL_Renderer *getRenderer() const;

    protected:
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
};

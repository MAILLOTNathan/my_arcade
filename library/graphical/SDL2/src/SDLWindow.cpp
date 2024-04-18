/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Window
*/

#include "SDLWindow.hpp"
#include <iostream>

Window::Window(const std::string& title, unsigned int x, unsigned int y)
{
    this->_window = SDL_CreateWindow(title.c_str(), 0, 0, x, y, SDL_WINDOW_FULLSCREEN);
    this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 255, 255);
    this->_event = std::make_unique<Event>();
}

Window::~Window()
{
    
    // SDL_DestroyWindow(this->_window);
}

bool Window::isOpen()const
{
    return this->_window != nullptr;
}

void Window::clear()
{
    SDL_RenderClear(this->_renderer);
}

void Window::display()
{
    SDL_RenderPresent(this->_renderer);
}

void Window::close()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    this->_window = nullptr;
}

void Window::pollEvent()
{
    this->getEvent()->manageEvent(this);
}

SDL_Window* Window::getWindow() const
{
    return this->_window;
}

SDL_Renderer* Window::getRenderer() const
{
    return this->_renderer;
}

/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Window
*/

#include "SFMLWindow.hpp"

Window::Window(const std::string& title, unsigned int x, unsigned int y)
{
    this->_window = new sf::RenderWindow(sf::VideoMode(x, y), title, sf::Style::Titlebar | sf::Style::Close);
    this->_event = std::make_unique<Event>();
}

Window::~Window()
{
    delete this->_window;
}

bool Window::isOpen() const
{
    return this->_window->isOpen();
}

void Window::clear()
{
    this->_window->clear(sf::Color(255, 0, 255, 255));
}

void Window::display()
{
    this->_window->display();
}

void Window::close()
{
    this->_window->close();
}

void Window::pollEvent()
{
    this->getEvent()->manageEvent(this);
}

sf::RenderWindow* Window::getWindow() const
{
    return this->_window;
}

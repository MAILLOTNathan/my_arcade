/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEWindow
*/

#include "NCURSEWindow.hpp"

Window::Window(const std::string &title, unsigned int x, unsigned int y)
{
    initscr();
    this->_window = stdscr;
    this->_opened = true;
    this->_title = title;
    this->_event = std::make_unique<Event>();
    nodelay(this->_window, true);
    start_color();
    init_pair(BUTTON_NORMAL, COLOR_WHITE, COLOR_BLACK);
    init_pair(BUTTON_HOVER, COLOR_GREEN, COLOR_BLACK);
    init_pair(BUTTON_CLICKED, COLOR_RED, COLOR_BLACK);
    resize_term(y, x);
    keypad(stdscr, true);
    timeout(0);
    noecho();
    wclear(this->_window);
}

Window::~Window()
{
    this->close();
}

bool Window::isOpen() const
{
    return this->_opened;
}

void Window::clear()
{
}

void Window::display()
{
    refresh();
}

void Window::close()
{
    endwin();
    this->_opened = false;
    this->_window = nullptr;
}

void Window::pollEvent()
{
    this->getEvent()->manageEvent(this);
}

WINDOW* Window::getWindow() const
{
    return this->_window;
}

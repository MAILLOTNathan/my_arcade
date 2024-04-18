/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Button
*/

#include "NCURSEButton.hpp"

Button::Button(const std::string &text, const EGE::Vector<int> &pos)
{
    this->_text = new Text(text, pos, EGE::Color(255, 255, 255, 255));
    this->_position = pos;
    this->_isClick = false;
    this->_isHover = false;
    this->_onClick = nullptr;
    this->_onHover = nullptr;
}

Button::~Button()
{
}

void Button::draw(std::shared_ptr<EGE::IWindow> window)
{
    WINDOW *win = dynamic_cast<Window *>(window.get())->getWindow();
    if (!this->_isClick && !this->_isHover)
        wattron(win, COLOR_PAIR(BUTTON_NORMAL));
    if (this->_isClick)
        wattron(win, COLOR_PAIR(BUTTON_HOVER));
    if (this->_isHover)
        wattron(win, COLOR_PAIR(BUTTON_CLICKED));

    mvprintw(this->_position.getY(), this->_position.getX(), this->_text->getText().c_str());
    wattroff(win, COLOR_PAIR(BUTTON_NORMAL));
    wattroff(win, COLOR_PAIR(BUTTON_HOVER));
    wattroff(win, COLOR_PAIR(BUTTON_CLICKED));
}

void Button::normal()
{
    this->_isClick = false;
    this->_isHover = false;
}

void Button::hover()
{
    this->_isHover = true;
    if (this->_onHover)
        this->_onHover();
}

void Button::click()
{
    this->_isClick = true;
    if (this->_onClick)
        this->_onClick();
}

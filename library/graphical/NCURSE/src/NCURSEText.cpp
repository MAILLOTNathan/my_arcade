/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEText
*/

#include "NCURSEText.hpp"

Text::Text(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color &color)
{
    this->_text = text;
    this->_color = color;
    this->_position = pos;
}

Text::~Text()
{
}

void Text::setText(const std::string &text)
{
    this->_text = text;
}

void Text::setPosition(const EGE::Vector<int> &position)
{
    this->_position = position;
}

void Text::setColor(const EGE::Color &color)
{
    this->_color = color;
}

void Text::draw(std::shared_ptr<EGE::IWindow> window)
{
    WINDOW *win = dynamic_cast<Window *>(window.get())->getWindow();
    std::string spaces(this->_text.length() + 1, ' ');
    mvprintw(this->_position.getY(), this->_position.getX(), spaces.c_str());
    mvwprintw(win, this->_position.getY(), this->_position.getX(), this->_text.c_str());
}

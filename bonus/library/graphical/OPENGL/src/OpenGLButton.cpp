/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLButton
*/

#include "OpenGLButton.hpp"

Button::Button(const std::string &text, const EGE::Vector<int> &pos)
{
    this->_text = new Text(text, pos, EGE::Color(255, 255, 255, 255));
    this->_position = pos;
    this->_isClick = false;
    this->_isHover = false;
    this->_position = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
    this->_onClick = nullptr;
    this->_onHover = nullptr;
}

Button::~Button()
{
    delete this->_text;
}

void Button::draw(std::shared_ptr<EGE::IWindow> window)
{
    this->_text->draw(window);
}

void Button::normal()
{
    this->_text->setColor(EGE::Color(255, 255, 255, 255));
    this->_isClick = false;
    this->_isHover = false;
}

void Button::hover()
{
    this->_text->setColor(EGE::Color(0, 0, 0, 255));
    this->_isHover = true;
    if (this->_onHover)
        this->_onHover();
}

void Button::click()
{
    this->_text->setColor(EGE::Color(255, 0, 0, 255));
    this->_isClick = true;
    if (this->_onClick)
        this->_onClick();
}

void Button::setText(const std::string &text)
{
    this->_text->setText(text);
}

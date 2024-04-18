/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SFMLButton
*/

#include "SFMLButton.hpp"

Button::Button(const std::string& text, const EGE::Vector<int>& pos)
{
    this->_text = new Text(text, pos, EGE::Color(255, 255, 255, 255));
    this->_isClick = false;
    this->_isHover = false;
    this->_position = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
    this->_onClick = nullptr;
    this->_onHover = nullptr;
}

Button::~Button()
{
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
    if (this->_isHover)
        return;
    this->_isHover = true;
    this->_text->setColor(EGE::Color(0, 255, 0, 255));
    if (this->_onHover)
        this->_onHover();
}

void Button::click()
{
    if (this->_isClick)
        return;
    this->_isClick = true;
    this->_text->setColor(EGE::Color(255, 0, 0, 255));
    if (this->_onClick)
        this->_onClick();
}
/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Text
*/

#include "SDLText.hpp"

Text::Text(const std::string& text, const EGE::Vector<int>& pos, const EGE::Color& color)
{
    this->_text = text;
    this->_position = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
    this->_color = color;
    this->_font = std::make_shared<Bitmapfont>();
    this->_font->setColor(color);
}

Text::~Text()
{
}

void Text::draw(std::shared_ptr<EGE::IWindow> window)
{
    EGE::Vector<int> posChar = this->_position;
    for (auto &c : this->_text) {
        this->_font->draw(window.get(), c, posChar);
        posChar.setX(posChar.getX() + (this->_font->getWidth() * 3));
    }
}

void Text::setText(const std::string& text)
{
    this->_text = text;
}

void Text::setColor(const EGE::Color& color)
{
    this->_color = color;
    this->_font->setColor(color);
}

void Text::setPosition(const EGE::Vector<int>& pos)
{
    this->_position = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
}

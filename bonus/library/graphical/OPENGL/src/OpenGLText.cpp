/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLText
*/

#include "OpenGLText.hpp"

Text::Text(const std::string& text, const EGE::Vector<int>& pos, const EGE::Color& color)
{
    this->_position = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
    this->_text = text;
    this->_font = std::make_shared<Bitmapfont>();
}

Text::~Text()
{
}

void Text::draw(std::shared_ptr<EGE::IWindow> window)
{
    EGE::Vector<int> pos = this->_position;
    for (auto &c : this->_text) {
        this->_font->draw(window, c, pos);
        pos.setX(pos.getX() + (this->_font->getWidth() * 3));
    }
}

void Text::setText(const std::string& text)
{
    this->_text = text;
}

void Text::setPosition(const EGE::Vector<int>& position)
{
    this->_position = EGE::Vector<int>(position.getX() * TILE_SIZE, position.getY() * TILE_SIZE);
}

void Text::setColor(const EGE::Color& color)
{
    this->_font->setColor(color);
}

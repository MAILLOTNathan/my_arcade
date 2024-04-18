/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Bitmapfont
*/

#include "Bitmapfont.hpp"

Bitmapfont::Bitmapfont()
{
    EGE::Ressource *ressource = new EGE::Ressource("./library/graphical/OPENGL/bitmapfont.png", nullptr);
    this->_height = 12;
    this->_width = 8;
    this->_sprite = new Sprite(ressource, EGE::Vector<int>(0, 0));
}

Bitmapfont::~Bitmapfont()
{
}

int Bitmapfont::getWidth() const
{
    return this->_width;
}

int Bitmapfont::getHeight() const
{
    return this->_height;
}

EGE::Rect<int> Bitmapfont::getCharPos(char c)
{
    int y = (c >> 4) * this->_height;
    int x = (c & 15) << 3;
    return EGE::Rect<int>(x, y, this->_width, this->_height);
}

std::vector<EGE::Rect<int>> Bitmapfont::getStringPos(const std::string &str)
{
    std::vector<EGE::Rect<int>> vec;
    for (char c : str)
        vec.push_back(this->getCharPos(c));
    return vec;
}

void Bitmapfont::draw(std::shared_ptr<EGE::IWindow> window, char c, const EGE::Vector<int>& pos)
{
    EGE::Rect<int> charRect = this->getCharPos(c);
    EGE::Rect<float> rect;
    rect.setX(static_cast<float>(charRect.getX()) / static_cast<float>(this->_sprite->getWidth()));
    rect.setY(static_cast<float>(charRect.getY()) / static_cast<float>(this->_sprite->getHeight()));
    rect.setWidth(1.0f / (this->_sprite->getWidth() / charRect.getWidth()));
    rect.setHeight(1.0f / (this->_sprite->getHeight() / charRect.getHeight()));

    this->_sprite->setRect(rect);
    this->_sprite->setPosition(pos);
    this->_sprite->draw(window);
}

void Bitmapfont::setColor(const EGE::Color &color)
{
    this->_sprite->setColor(color);
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SFMLBitmapfont
*/

#include "SFMLBitmapfont.hpp"

Bitmapfont::Bitmapfont()
{
    this->_width = 8;
    this->_height = 12;
    this->_sfTexture.loadFromFile("./library/graphical/SFML/bitmapfont.png");
    this->_sfSprite.setTexture(this->_sfTexture);
    this->_sfSprite.setScale(3, 3);
    this->_sfRect = {0, 0, this->_sfTexture.getSize().x, this->_sfTexture.getSize().y};
    for (int i = 0; i < 256; i++) {
        this->_charPos.push_back(this->getCharPos(i));
    }
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

void Bitmapfont::draw(EGE::IWindow *window, char c, const EGE::Vector<int>& pos)
{
    sf::RenderWindow *win = dynamic_cast<Window *>(window)->getWindow();
    sf::Sprite sprite;
    this->_sfSprite.setTexture(this->_sfTexture);
    EGE::Rect<int> charRect = this->getCharPos(c);
    this->_sfSprite.setTextureRect(sf::IntRect(charRect.getX(), charRect.getY(), charRect.getWidth(), charRect.getHeight()));
    this->_sfSprite.setPosition(pos.getX(), pos.getY());
    win->draw(this->_sfSprite);
}

void Bitmapfont::setColor(const EGE::Color &color)
{
    this->_color = color;
    this->_sfSprite.setColor(sf::Color(this->_color.getRed(), this->_color.getGreen(), this->_color.getBlue(), this->_color.getAlpha()));
}

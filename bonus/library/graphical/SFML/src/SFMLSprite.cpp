/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Sprite
*/

#include "SFMLSprite.hpp"

Sprite::Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos)
{
    this->_texture.loadFromFile(ressource->_path);
    this->_sprite.setTexture(this->_texture);
    this->_pos = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
    this->_sprite.setPosition(this->_pos.getX(), this->_pos.getY());
    this->_sprite.setScale(TILE_SIZE / this->_sprite.getGlobalBounds().width, TILE_SIZE / this->_sprite.getGlobalBounds().height);
}

Sprite::~Sprite()
{
}

void Sprite::setPosition(const EGE::Vector<int> &pos)
{
    this->_pos = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
    this->_sprite.setPosition(this->_pos.getX(), this->_pos.getY());
}

void Sprite::setPosition(int x, int y)
{
    this->_pos = EGE::Vector<int>(x * TILE_SIZE, y * TILE_SIZE);
    this->_sprite.setPosition(this->_pos.getX(), this->_pos.getY());
}

void Sprite::draw(std::shared_ptr<EGE::IWindow> window)
{
    sf::RenderWindow *win = dynamic_cast<Window *>(window.get())->getWindow();
    win->draw(this->_sprite);
}

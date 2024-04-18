/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSESprite
*/

#include "NCURSESprite.hpp"

Sprite::Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos)
{
    this->_sprite = ressource->_character;
    this->_pos = pos;
}

Sprite::~Sprite()
{
}

void Sprite::setPosition(const EGE::Vector<int>& pos)
{
    this->_oldPos = this->_pos;
    this->_pos.setX(pos.getX());
    this->_pos.setY(pos.getY());
}

void Sprite::setPosition(int x, int y)
{
    this->_oldPos = this->_pos;
    this->_pos.setX(x);
    this->_pos.setY(y);
}

void Sprite::draw(std::shared_ptr<EGE::IWindow> window)
{
    mvprintw(this->_oldPos.getY(), this->_oldPos.getX(), " ");
    mvprintw(this->_pos.getY(), this->_pos.getX(), this->_sprite.c_str());
}

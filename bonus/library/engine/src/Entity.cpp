/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Entity
*/

#include "Entity.hpp"
#include "AGameModule.hpp"

void EGE::Entity::draw(IDisplayModule *dm)
{
    this->_sprite->draw(dm->getWindow());
}

void EGE::Entity::setPosition(const Vector<int> &pos)
{
    this->_position = pos;
    this->_sprite->setPosition(pos);
}

void EGE::Entity::setSprite(ISprite *sprite)
{
    this->_sprite = sprite;
}

bool EGE::Entity::isColliding(EGE::Entity &other)
{
    size_t absoluteX = abs(this->getPosition().getX() - other.getPosition().getX());
    size_t absoluteY = abs(this->getPosition().getY() - other.getPosition().getY());

    if (absoluteX == 0 && absoluteY == 0)
        return true;
    if (absoluteX == 1 && absoluteY == 0)
        return true;
    if (absoluteX == 0 && absoluteY == 1)
        return true;
    return false;
}

void EGE::Entity::reload(IDisplayModule *dm, IGameModule *gm)
{
    // std::cout << this->_type << " | " << this << std::endl;
    this->init(dm, gm);
    this->setPosition(this->_position);
}

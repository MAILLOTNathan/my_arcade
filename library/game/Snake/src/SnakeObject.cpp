/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SnakeObject
*/

#include "SnakeObject.hpp"
#include "AGameModule.hpp"

SnakeObject::SnakeObject(std::map<std::string, std::string> &properties)
{
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_type = EGE::Entity::OBJECT;
}

SnakeObject::~SnakeObject()
{
}

void SnakeObject::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
}

void SnakeObject::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
}

void SnakeObject::setRandomPosition(std::vector<EGE::Entity *> &entities)
{
    size_t minY = entities.at(0)->getPosition().getY();
    size_t maxY = 0;
    size_t minX = entities.at(0)->getPosition().getX();
    size_t maxX = 0;

    for (auto &entity : entities) {
        if (entity->getPosition().getY() < minY)
            minY = entity->getPosition().getY();
        if (entity->getPosition().getY() > maxY)
            maxY = entity->getPosition().getY();
        if (entity->getPosition().getX() < minX)
            minX = entity->getPosition().getX();
        if (entity->getPosition().getX() > maxX)
            maxX = entity->getPosition().getX();
    }

    this->setRandomPosition(minX, maxX, minY, maxY, entities);
}

void SnakeObject::setRandomPosition(size_t minX, size_t maxX, size_t minY, size_t maxY, std::vector<EGE::Entity *> &entities)
{
    EGE::Vector<int> newPos = EGE::Vector<int>((minX + 1) + rand() % (maxX - minX - 1), (minY + 1) + rand() % (maxY - minY - 1));

    for (auto &entity : entities) {
        if (entity->getPosition().getX() == newPos.getX() && entity->getPosition().getY() == newPos.getY()) {
            return this->setRandomPosition(minX, maxX, minY, maxY, entities);
        }
    }
    this->setPosition(newPos);
}

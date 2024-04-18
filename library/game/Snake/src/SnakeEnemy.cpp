/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SnakeEnemy
*/

#include "SnakeEnemy.hpp"
#include "AGameModule.hpp"

SnakeEnemy::SnakeEnemy(std::map<std::string, std::string> &properties)
{
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_type = EGE::Entity::ENEMY;
}

SnakeEnemy::~SnakeEnemy()
{
}

void SnakeEnemy::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
}

void SnakeEnemy::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
}

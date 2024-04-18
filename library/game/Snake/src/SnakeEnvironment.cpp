/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SnakeEnvironment
*/

#include "SnakeEnvironment.hpp"
#include "AGameModule.hpp"

SnakeEnvironment::SnakeEnvironment(std::map<std::string, std::string> &properties)
{
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_type = EGE::Entity::ENVIRONMENT;
}

SnakeEnvironment::~SnakeEnvironment()
{
}

void SnakeEnvironment::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
}

void SnakeEnvironment::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
}

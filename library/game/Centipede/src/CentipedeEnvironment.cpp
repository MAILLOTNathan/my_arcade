/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** CentipedeEnvironment
*/

#include "CentipedeEnvironment.hpp"
#include "AGameModule.hpp"

CentipedeEnvironment::CentipedeEnvironment(std::map<std::string, std::string> &properties)
{
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_type = EGE::Entity::ENVIRONMENT;
}

CentipedeEnvironment::~CentipedeEnvironment()
{
}

void CentipedeEnvironment::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
}

void CentipedeEnvironment::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
}

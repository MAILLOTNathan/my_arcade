/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** CentipedeObject
*/

#include "CentipedeObject.hpp"
#include "AGameModule.hpp"

CentipedeObject::CentipedeObject(std::map<std::string, std::string> &properties)
{
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_type = EGE::Entity::OBJECT;
}

CentipedeObject::~CentipedeObject()
{
}

void CentipedeObject::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
}

void CentipedeObject::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
}

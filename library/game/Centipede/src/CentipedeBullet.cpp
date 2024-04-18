/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** CentipedeBullet
*/

#include "CentipedeBullet.hpp"
#include "CentipedePlayer.hpp"
#include "AGameModule.hpp"

CentipedeBullet::CentipedeBullet(CentipedePlayer *_player)
{
    this->_ressource = std::make_shared<EGE::Ressource>("./library/game/Centipede/config/assets/bullet.png", "|");
    this->_player = _player;
    this->_type = EGE::Entity::PLAYER;
    this->_shooting = false;
    this->_position = EGE::Vector<int>(1000, 1000);
}

CentipedeBullet::~CentipedeBullet()
{
    delete this->_sprite;
}

void CentipedeBullet::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite *)displayModule->createSprite(this->_ressource.get());
    gameModule->addEntity(this);
}

void CentipedeBullet::draw(EGE::IDisplayModule *displayModule)
{
    if (this->isShooting())
        this->_sprite->draw(displayModule->getWindow());
}

void CentipedeBullet::reload(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    delete this->_sprite;
    this->_sprite = (EGE::ISprite *)displayModule->createSprite(this->_ressource.get());
}

bool CentipedeBullet::isColliding(EGE::Entity &other)
{
    if (other.getType() == EGE::Entity::PLAYER)
        return false;
    size_t playerX = this->getPosition().getX();
    size_t playerY = this->getPosition().getY();
    size_t otherX = other.getPosition().getX();
    size_t otherY = other.getPosition().getY();

    if (playerX == otherX && playerY == otherY)
        return true;
    return false;
}

void CentipedeBullet::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
    for (auto &entity : entities) {
        if (this->isColliding(*entity)) {
            if (entity->getType() == EGE::Entity::ENEMY)
                gameModule->setScore(gameModule->getScore() + 100); 
            this->setShooting(false);
            return;
        }
    }
    this->setPosition(this->getPosition() + EGE::Vector<int>(0, -1));
}
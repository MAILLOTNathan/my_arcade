/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SknakePlayer
*/

#include "CentipedePlayer.hpp"
#include "AGameModule.hpp"

CentipedePlayer::CentipedePlayer(std::map<std::string, std::string> &properties)
{
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_type = EGE::Entity::PLAYER;
    this->_bullet = std::make_shared<CentipedeBullet>(this);
}

CentipedePlayer::~CentipedePlayer()
{
}

void CentipedePlayer::draw(EGE::IDisplayModule *displayModule)
{
    this->_sprite->draw(displayModule->getWindow());
}

void CentipedePlayer::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
    this->_bullet->init(displayModule, gameModule);
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Z, EGE::Event::PRESSED),
        [this]() {
            this->setPosition(this->getPosition() + EGE::Vector<int>(0, -1));
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Q, EGE::Event::PRESSED),
        [this]() {
            this->setPosition(this->getPosition() + EGE::Vector<int>(-1, 0));
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::S, EGE::Event::PRESSED),
        [this]() {
            this->setPosition(this->getPosition() + EGE::Vector<int>(0, 1));
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::D, EGE::Event::PRESSED),
        [this]() {
            this->setPosition(this->getPosition() + EGE::Vector<int>(1, 0));
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Space, EGE::Event::JUST_PRESSED),
        [this]() {
            if (this->_bullet->isShooting())
                return;
            this->_bullet->setShooting(true);
            this->_bullet->setPosition(this->getPosition());
        }
    );
}

void CentipedePlayer::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
    for (auto &entity : entities) {
        bool colliding = this->isColliding(*entity);

        if (!colliding || entity->getType() == EGE::Entity::PLAYER)
            continue;
        switch (entity->getType()) {
            case EGE::Entity::OBJECT:
                break;
            case EGE::Entity::ENVIRONMENT:
                break;
            case EGE::Entity::ENEMY:
                break;
            default:
                break;
        }
    }
}

/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SknakePlayer
*/

#include "SnakePlayer.hpp"
#include "AGameModule.hpp"

SnakePlayer::SnakePlayer(std::map<std::string, std::string> &properties)
{
    this->_type = EGE::Entity::PLAYER;
    this->_size = 2;
    this->_direction = RIGHT;
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_alive = true;
}

SnakePlayer::~SnakePlayer()
{
}

void SnakePlayer::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Z, EGE::Event::JUST_PRESSED),
        [this]() {
            this->_direction = UP;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Q, EGE::Event::JUST_PRESSED),
        [this]() {
            this->_direction = LEFT;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::S, EGE::Event::JUST_PRESSED),
        [this]() {
            this->_direction = DOWN;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::D, EGE::Event::JUST_PRESSED),
        [this]() {
            this->_direction = RIGHT;
        }
    );
}

bool SnakePlayer::isColliding(EGE::Entity &other)
{
    size_t playerX = this->getPosition().getX();
    size_t playerY = this->getPosition().getY();
    size_t otherX = other.getPosition().getX();
    size_t otherY = other.getPosition().getY();

    if (playerX == otherX && playerY == otherY)
        return true;
    if (other.getType() == EGE::Entity::OBJECT) {
        if (this->_direction == RIGHT)
            if (playerX == otherX && playerY == otherY)
                return true;
        if (this->_direction == LEFT)
            if (playerX == otherX && playerY == otherY)
                return true;
        if (this->_direction == UP)
            if (playerY == otherY && playerX == otherX)
                return true;
        if (this->_direction == DOWN)
            if (playerY == otherY && playerX == otherX)
                return true;
    }
    return false;
}


void SnakePlayer::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
    for (auto &entity : entities) {
        if (this->isColliding(*entity)) {
            switch (entity->getType()) {
                case EGE::Entity::OBJECT:
                    this->increaseSize();
                    ((SnakeObject *)entity)->setRandomPosition(entities);
                    break;
                case EGE::Entity::PLAYER:
                    continue;
                case EGE::Entity::ENVIRONMENT:
                    this->_alive = false;
                    break;
                case EGE::Entity::ENEMY:
                    break;
                default:
                    break;
            }
        }
    }
    switch (this->_direction) {
        case UP:
            this->setPosition(this->getPosition() + EGE::Vector<int>(0, -1));
            break;
        case RIGHT:
            this->setPosition(this->getPosition() + EGE::Vector<int>(1, 0));
            break;
        case DOWN:
            this->setPosition(this->getPosition() + EGE::Vector<int>(0, 1));
            break;
        case LEFT:
            this->setPosition(this->getPosition() + EGE::Vector<int>(-1, 0));
            break;
        default:
            break;
    }
}

void SnakePlayer::increaseSize()
{
    this->_size++;
}

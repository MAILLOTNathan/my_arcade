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
            this->_direction = UP;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Q, EGE::Event::PRESSED),
        [this]() {
            this->_direction = LEFT;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::S, EGE::Event::PRESSED),
        [this]() {
            this->_direction = DOWN;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::D, EGE::Event::PRESSED),
        [this]() {
            this->_direction = RIGHT;
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

void CentipedePlayer::reload(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
    this->_bullet->reload(displayModule, gameModule);
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Z, EGE::Event::PRESSED),
        [this]() {
            this->_direction = UP;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::Q, EGE::Event::PRESSED),
        [this]() {
            this->_direction = LEFT;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::S, EGE::Event::PRESSED),
        [this]() {
            this->_direction = DOWN;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::D, EGE::Event::PRESSED),
        [this]() {
            this->_direction = RIGHT;
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
    this->_sprite->setPosition(this->getPosition());
}

bool CentipedePlayer::isColliding(EGE::Entity &other)
{
    size_t playerX = this->getPosition().getX();
    size_t playerY = this->getPosition().getY();
    size_t otherX = other.getPosition().getX();
    size_t otherY = other.getPosition().getY();


    if (other.getType() == EGE::Entity::PLAYER)
        return false;
    if (this->_direction == RIGHT)
        if (playerX + 1 == otherX && playerY == otherY)
            return true;
    if (this->_direction == LEFT)
        if (playerX - 1 == otherX && playerY == otherY)
            return true;
    if (this->_direction == UP)
        if (playerY - 1 == otherY && playerX == otherX)
            return true;
    if (this->_direction == DOWN)
        if (playerY + 1 == otherY && playerX == otherX)
            return true;
    if (playerX == otherX && playerY == otherY)
        return true;
    return false;
}

void CentipedePlayer::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
    bool isEnemy = false;
    for (auto &entity : entities) {
        if (entity->getType() == EGE::Entity::ENEMY)
            isEnemy = true;
        bool colliding = this->isColliding(*entity);
        if (!colliding || entity->getType() == EGE::Entity::PLAYER)
            continue;
        switch (entity->getType()) {
            case EGE::Entity::OBJECT:
                break;
            case EGE::Entity::ENVIRONMENT:
                this->_direction = NONE;
                break;
            case EGE::Entity::ENEMY:
                gameModule->setState(EGE::AGameModule::LOSE);
                break;
            default:
                break;
        }
    }
    if (!isEnemy)
        gameModule->setState(EGE::AGameModule::WIN);
    this->move(this->_direction);
}

void CentipedePlayer::move(Direction direction)
{
    switch (direction) {
        case UP:
            this->setPosition(this->getPosition() + EGE::Vector<int>(0, -1));
            break;
        case DOWN:
            this->setPosition(this->getPosition() + EGE::Vector<int>(0, 1));
            break;
        case LEFT:
            this->setPosition(this->getPosition() + EGE::Vector<int>(-1, 0));
            break;
        case RIGHT:
            this->setPosition(this->getPosition() + EGE::Vector<int>(1, 0));
            break;
        default:
            break;
    }
    this->_direction = NONE;
}

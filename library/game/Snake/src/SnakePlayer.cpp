/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SknakePlayer
*/

#include "Game.hpp"
#include "SnakePlayer.hpp"
#include "AGameModule.hpp"

SnakePlayer::SnakePlayer(std::map<std::string, std::string> &properties, Type type)
{
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_direction = RIGHT;
    this->_lastDirection = RIGHT;
    this->_size = 1;
    this->_currentSize = 0;
    this->_type = EGE::Entity::Type::PLAYER;
    this->_playerType = type;
    this->_position = EGE::Vector<int>(-1, -1);
}

SnakePlayer::~SnakePlayer()
{
}

void SnakePlayer::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_body.clear();
    this->_displayModule = displayModule;
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
    if (this->_playerType == HEAD) {
        for (size_t i = 0; i < this->_size; i++) {
            std::map<std::string, std::string> properties;
            properties["sprite"] = "library/game/Snake/config/assets/player.png";
            properties["char"] = "P";
            this->_body.push_back(new SnakePlayer(properties, BODY));
            this->_body[i]->init(displayModule, gameModule);
        }
    }
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::W, EGE::Event::JUST_PRESSED),
        [this]() {
            if (this->_direction != DOWN)
                this->_direction = UP;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::A, EGE::Event::JUST_PRESSED),
        [this]() {
            if (this->_direction != RIGHT)
                this->_direction = LEFT;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::S, EGE::Event::JUST_PRESSED),
        [this]() {
            if (this->_direction != UP)
                this->_direction = DOWN;
        }
    );
    displayModule->bindKey(
        std::make_shared<EGE::Event::Trigger<EGE::Event::Keyboard>>(
            EGE::Event::D, EGE::Event::JUST_PRESSED),
        [this]() {
            if (this->_direction != LEFT)
                this->_direction = RIGHT;
        }
    );
}

void SnakePlayer::move()
{
    switch (this->_direction) {
    case RIGHT:
        this->setPosition(this->getPosition() + EGE::Vector<int>(1, 0));
        break;
    case LEFT:
        this->setPosition(this->getPosition() + EGE::Vector<int>(-1, 0));
        break;
    case UP:
        this->setPosition(this->getPosition() + EGE::Vector<int>(0, -1));
        break;
    case DOWN:
        this->setPosition(this->getPosition() + EGE::Vector<int>(0, 1));
        break;
    }
}

void SnakePlayer::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
    int index = 0;
    this->_currentSize = this->_currentSize == this->_size ? this->_size : this->_currentSize + 1;
    if (this->_body.size() > 0) {
        for (int tmp = this->_size - 1; tmp > 0; tmp--) {
            this->_body[tmp]->setPosition(this->_body[tmp - 1]->getPosition());
            if (this->isColliding(*(Entity *)this->_body[tmp]))
                gameModule->setState(Game::LOSE);
        }
        this->_body[0]->setPosition(this->getPosition());
    }
    for (auto &entity : entities) {
        if (this->isColliding(*entity)) {
            switch (entity->getType()) {
            case EGE::Entity::OBJECT:
                if (this->_playerType == HEAD) {
                    this->increaseSize(gameModule);
                    ((SnakeObject *)entity)->setRandomPosition(entities);
                }
                break;
            case EGE::Entity::ENEMY:
                break;
            case EGE::Entity::ENVIRONMENT:
                gameModule->setState(Game::LOSE);
                break;
            case EGE::Entity::PLAYER:
                if (((SnakePlayer *)entity)->_playerType == BODY && this->_playerType == HEAD)
                    gameModule->setState(Game::LOSE);
                break;
            default:
                break;
            }
        }
    }
    this->move();
}

void SnakePlayer::increaseSize(EGE::IGameModule *gameModule)
{
    this->_size++;
    std::map<std::string, std::string> properties;
    properties["sprite"] = "library/game/Snake/config/assets/player.png";
    properties["char"] = "P";
    SnakePlayer *bodyPart = new SnakePlayer(properties, BODY);
    bodyPart->init(this->_displayModule, gameModule);
    bodyPart->setPosition(EGE::Vector<int>(-1, -1));
    gameModule->setScore(gameModule->getScore() + 1);
    this->_body.push_back(bodyPart);
}

void SnakePlayer::draw(EGE::IDisplayModule *displayModule)
{
    this->_sprite->draw(displayModule->getWindow());
    for (auto &body : this->_body) {
        if (body->_playerType != SnakePlayer::HEAD)
            body->draw(displayModule);
    }
}

bool SnakePlayer::isColliding(EGE::Entity &other)
{
    size_t playerX = this->getPosition().getX();
    size_t playerY = this->getPosition().getY();
    size_t otherX = other.getPosition().getX();
    size_t otherY = other.getPosition().getY();

    if (playerX == otherX && playerY == otherY)
        return true;
    return false;
}
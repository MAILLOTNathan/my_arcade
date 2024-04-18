/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** CentipedeEnemy
*/

#include "CentipedeEnemy.hpp"
#include "AGameModule.hpp"

CentipedeEnemy::CentipedeEnemy(std::map<std::string, std::string> &properties, Type type)
{
    this->_ressource = std::make_shared<EGE::Ressource>(properties["sprite"], properties["char"]);
    this->_direction = RIGHT;
    this->_lastDirection = RIGHT;
    this->_size = 10;
    this->_currentSize = 0;
    this->_type = EGE::Entity::Type::ENEMY;
    this->_enemyType = type;
    this->_position = EGE::Vector<int>(-1, -1);
}

CentipedeEnemy::~CentipedeEnemy()
{
}

void CentipedeEnemy::draw(EGE::IDisplayModule *displayModule)
{
    this->_sprite->draw(displayModule->getWindow());
    for (auto &body : this->_body) {
        if (body->_enemyType != CentipedeEnemy::HEAD)
            body->draw(displayModule);
    }
    // for (size_t i = 0; i < this->_currentSize; i++) {
    //     this->_body[i]->draw(displayModule);
    // }
}

void CentipedeEnemy::init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_body.clear();
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
    if (this->_enemyType == HEAD) {
        for (size_t i = 0; i < this->_size; i++) {
            std::map<std::string, std::string> properties;
            properties["sprite"] = "library/game/Centipede/config/assets/enemy.png";
            properties["char"] = "E";
            this->_body.push_back(new CentipedeEnemy(properties, BODY));
            this->_body[i]->init(displayModule, gameModule);
        }
    }
}

void CentipedeEnemy::reload(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule)
{
    this->_sprite = (EGE::ISprite*)displayModule->createSprite(this->_ressource.get());
    for (auto &body : this->_body) {
        body->reload(displayModule, gameModule);
    }
}

void CentipedeEnemy::update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule)
{
    int index = 0;
    this->_currentSize = this->_currentSize == this->_size ? this->_size : this->_currentSize + 1;
    for (int tmp = this->_size - 1; tmp > 0; tmp--) {
        this->_body[tmp]->setPosition(this->_body[tmp - 1]->getPosition());
    }
    this->_body[0]->setPosition(this->getPosition());
    if (this->_direction == DOWN) {
        this->_direction = static_cast<Direction>(!this->_lastDirection);
        this->move();
        return;
    }
    for (auto &entity : entities) {
        if (this->isColliding(entity, gameModule)) {
            switch (entity->getType()) {
            case EGE::Entity::PLAYER:
                break;
            case EGE::Entity::ENEMY:
                break;
            case EGE::Entity::ENVIRONMENT:
                this->_lastDirection = this->_direction;
                this->_direction = DOWN;
                break;
            default:
                break;
            }
        }
    }
    this->move();
}

bool CentipedeEnemy::isColliding(EGE::Entity *entity, EGE::IGameModule *gameModule)
{
    size_t x = this->getPosition().getX();
    size_t y = this->getPosition().getY();
    size_t ex = entity->getPosition().getX();
    size_t ey = entity->getPosition().getY();

    if (entity->getType() == EGE::Entity::PLAYER) {
        for (auto &body : this->_body) {
            if (body->_enemyType != CentipedeEnemy::HEAD && body->isColliding(entity, gameModule)) {
                this->split(body, gameModule);
                return true;
            }
        }
    }
    if (entity->getType() == EGE::Entity::ENVIRONMENT) {
        if (this->_direction == RIGHT)
            if (x + 1 == ex && y == ey)
                return true;
        if (this->_direction == LEFT)
            if (x - 1 == ex && y == ey)
                return true;
        if (this->_direction == UP)
            if (y == ey && x == ex)
                return true;
        if (this->_direction == DOWN)
            if (y == ey && x == ex)
                return true;
    } else if (entity->getType() == EGE::Entity::PLAYER) {
        if (this->_direction == RIGHT)
            if (x == ex && y == ey)
                return true;
        if (this->_direction == LEFT)
            if (x == ex && y == ey)
                return true;
        if (this->_direction == UP)
            if (y == ey && x == ex)
                return true;
        if (this->_direction == DOWN)
            if (y == ey && x == ex)
                return true;
    }
    return false;
}

void CentipedeEnemy::move()
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

void CentipedeEnemy::split(CentipedeEnemy *enemy, EGE::IGameModule *gameModule)
{
    size_t index = 0;
    for (index = 0; index < this->_size; index++) {
        if (this->_body[index] == enemy) {
            break;
        }
    }
    enemy->_enemyType = HEAD;
    for (size_t i = index; i < this->_size; i++) {
        enemy->_body.push_back(this->_body[i]);
        this->_body.erase(this->_body.begin() + i);
    }
    enemy->_direction = static_cast<Direction>(!this->_direction);
    enemy->_size = this->_size - index;
    this->_size = index;
    gameModule->addEntity(enemy);
}
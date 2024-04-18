/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** CentipedeEnemy
*/

#pragma once

#include "Entity.hpp"

class CentipedeEnemy : public EGE::Entity {
    public:
        enum Direction {
            LEFT,
            RIGHT,
            DOWN,
            UP
        };
        enum Type {
            HEAD,
            BODY
        };
        CentipedeEnemy(std::map<std::string, std::string> &properties, Type type = HEAD);
        ~CentipedeEnemy();

        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        bool isColliding(EGE::Entity *entity, EGE::IGameModule *gameModule);
        void move();
        void split(CentipedeEnemy *enemy, EGE::IGameModule *gameModule);

        void draw(EGE::IDisplayModule *displayModule) override;

    protected:
        Direction _direction;
        Direction _lastDirection;
        CentipedeEnemy::Type _enemyType;
        int _size;
        int _currentSize;
        std::vector<CentipedeEnemy *> _body;
    private:
};

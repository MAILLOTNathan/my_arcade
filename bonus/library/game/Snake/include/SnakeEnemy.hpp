/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SnakeEnemy
*/

#pragma once

#include "Entity.hpp"

class SnakeEnemy : public EGE::Entity {
    public:
        SnakeEnemy(std::map<std::string, std::string> &properties);
        ~SnakeEnemy();

        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

    protected:

    private:
};

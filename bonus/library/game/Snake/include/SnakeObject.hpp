/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SnakeObject
*/

#pragma once

#include "Entity.hpp"

class SnakeObject : public EGE::Entity {
    public:
        SnakeObject(std::map<std::string, std::string> &properties);
        ~SnakeObject();

        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        void setRandomPosition(std::vector<EGE::Entity *> &entities);

    private:
        void setRandomPosition(size_t minX, size_t maxX, size_t minY, size_t maxY, std::vector<EGE::Entity *> &entities);
};

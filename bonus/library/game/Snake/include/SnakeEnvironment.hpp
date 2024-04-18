/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SnakeEnvironment
*/

#pragma once

#include "Entity.hpp"

class SnakeEnvironment : public EGE::Entity {
    public:
        SnakeEnvironment(std::map<std::string, std::string> &properties);
        ~SnakeEnvironment();

        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

    protected:
        
    private:
};

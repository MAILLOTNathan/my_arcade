/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** CentipedeEnvironment
*/

#pragma once

#include "Entity.hpp"

class CentipedeEnvironment : public EGE::Entity {
    public:
        CentipedeEnvironment(std::map<std::string, std::string> &properties);
        ~CentipedeEnvironment();

        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

    protected:
        
    private:
};

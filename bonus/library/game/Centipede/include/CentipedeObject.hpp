/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** CentipedeObject
*/

#pragma once

#include "Entity.hpp"

class CentipedeObject : public EGE::Entity {
    public:
        CentipedeObject(std::map<std::string, std::string> &properties);
        ~CentipedeObject();

        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

    protected:
        
    private:
};

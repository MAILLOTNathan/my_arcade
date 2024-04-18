/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Game
*/

#pragma once

#include "AGameModule.hpp"
#include "CentipedePlayer.hpp"
#include "CentipedeEnemy.hpp"
#include "CentipedeEnvironment.hpp"
#include "CentipedeObject.hpp"

class Game : public EGE::AGameModule {
    public:
        Game();
        ~Game();

        virtual void load(EGE::IDisplayModule *displayModule) override;
        EGE::Entity *createPlayer(std::map<std::string, std::string> &properties) override;
        EGE::Entity *createEnemy(std::map<std::string, std::string> &properties) override;
        EGE::Entity *createObject(std::map<std::string, std::string> &properties) override;
        EGE::Entity *createEnvironment(std::map<std::string, std::string> &properties) override;

    private:
        void loadSavegame() override {}
};

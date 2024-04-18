/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Game
*/

#include "CentipedeGame.hpp"
#include "AGameModule.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::load(EGE::IDisplayModule *displayModule)
{
    this->_display = displayModule;
    this->init("library/game/Centipede/config");
}

EGE::Entity *Game::createPlayer(std::map<std::string, std::string> &properties)
{
    EGE::Entity *entity = new CentipedePlayer(properties);
    return entity;
}

EGE::Entity *Game::createEnemy(std::map<std::string, std::string> &properties)
{
    EGE::Entity *entity = new CentipedeEnemy(properties);
    return entity;
}

EGE::Entity *Game::createObject(std::map<std::string, std::string> &properties)
{
    EGE::Entity *entity = new CentipedeObject(properties);
    return entity;
}

EGE::Entity *Game::createEnvironment(std::map<std::string, std::string> &properties)
{
    EGE::Entity *entity = new CentipedeEnvironment(properties);
    return entity;
}

extern "C" {
    EGE::IGameModule *createGameModule()
    {
        EGE::IGameModule *gameModule = new Game();
        return gameModule;
    }

    void destroyGameModule(EGE::IGameModule *gameModule)
    {
        delete gameModule;
    }
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
}

Game::~Game()
{
}

void Game::load(EGE::IDisplayModule *displayModule)
{
    this->_display = displayModule;
    this->init("library/game/Snake/config");
}

EGE::Entity *Game::createPlayer(std::map<std::string, std::string> &properties)
{
    EGE::Entity *entity = new SnakePlayer(properties);
    return entity;
}

EGE::Entity *Game::createEnemy(std::map<std::string, std::string> &properties)
{
    EGE::Entity *entity = new SnakeEnemy(properties);
    return entity;
}

EGE::Entity *Game::createObject(std::map<std::string, std::string> &properties)
{
    EGE::Entity *entity = new SnakeObject(properties);
    return entity;
}

EGE::Entity *Game::createEnvironment(std::map<std::string, std::string> &properties)
{
    EGE::Entity *entity = new SnakeEnvironment(properties);
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

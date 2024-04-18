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

void Game::getNextFrame()
{
    switch (this->_state)
    {
    case RUN:
        AGameModule::getNextFrame();
        break;
    case LOSE:
        this->_msgEnd->setText("You lose ! (PRESS R TO RESTART)");
        this->_msgEnd->setPosition(EGE::Vector<int>(10, 10));
        this->_msgEnd->draw(this->_display->getWindow());
        this->_scoreText->setPosition(EGE::Vector<int>(10, 12));
        this->_scoreText->draw(this->_display->getWindow());
        break;
    case WIN:
        this->_msgEnd->setText("You win ! (PRESS R TO RESTART)");
        this->_msgEnd->setPosition(EGE::Vector<int>(10, 10));
        this->_msgEnd->draw(this->_display->getWindow());
        this->_scoreText->setPosition(EGE::Vector<int>(10, 12));
        this->_scoreText->draw(this->_display->getWindow());
        break;
    default:
        break;
    }
}

void Game::load(EGE::IDisplayModule *displayModule)
{
    this->_display = displayModule;
    this->_score = 0;
    this->_state = RUN;
    this->_entities.clear();
    this->_model.clear();
    this->_msgEnd = this->_display->createText("", EGE::Vector<int>(10, 10), EGE::Color(255, 255, 255));
    this->_scoreText = this->_display->createText("000", EGE::Vector<int>(0, 0), EGE::Color(255, 255, 255));
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

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Game
*/

#pragma once

#include "AGameModule.hpp"
#include "SnakePlayer.hpp"
#include "SnakeEnemy.hpp"
#include "SnakeEnvironment.hpp"
#include "SnakeObject.hpp"

/// @brief `Game Module` class of Snake Game.
class Game : public EGE::AGameModule {
    public:
        /// @brief Create the Snake `Game Module`.
        Game();

        /// @brief Destructor.
        ~Game();
  
        /// @brief Displays the next frame of the game.
        void getNextFrame() override;

        /// @brief Load Snake Game from the configuration files.
        /// @param displayModule `Display Module` currently used by this game instance.
        virtual void load(EGE::IDisplayModule *displayModule) override;

        /// @brief Create a `SnakePlayer` from `properties`
        /// @param properties Description of the `SnakePlayer`
        EGE::Entity *createPlayer(std::map<std::string, std::string> &properties) override;

        /// @brief Create a `SnakeEnemy` from `properties`
        /// @param properties Description of the `SnakeEnemy`
        EGE::Entity *createEnemy(std::map<std::string, std::string> &properties) override;

        /// @brief Create a `SnakeObject` from `properties`
        /// @param properties Description of the `SnakeObject`
        EGE::Entity *createObject(std::map<std::string, std::string> &properties) override;

        /// @brief Create a `SnakeEnvironment` from `properties`
        /// @param properties Description of the `SnakeEnvironment`
        EGE::Entity *createEnvironment(std::map<std::string, std::string> &properties) override;

    private:
        /// @brief Load the `savegame` of Snake.
        void loadSavegame() override {}
};

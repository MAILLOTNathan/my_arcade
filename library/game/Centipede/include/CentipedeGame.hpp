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

/// @brief `Game Module` class of Centipede Game.
class Game : public EGE::AGameModule {
    public:
        /// @brief Create the Centipede `Game Module`.
        Game();

        /// @brief Destructor.
        ~Game();

        /// @brief Load Centipede Game from the configuration files.
        /// @param displayModule `Display Module` currently used by this game instance.
        virtual void load(EGE::IDisplayModule *displayModule) override;

        /// @brief Displays the next frame of the game.
        void getNextFrame() override;
  
        /// @brief Create a `CentipedePlayer` from `properties`
        /// @param properties Description of the `CentipedePlayer`
        EGE::Entity *createPlayer(std::map<std::string, std::string> &properties) override;

        /// @brief Create a `CentipedeEnemy` from `properties`
        /// @param properties Description of the `CentipedeEnemy`
        EGE::Entity *createEnemy(std::map<std::string, std::string> &properties) override;

        /// @brief Create a `CentipedeObject` from `properties`
        /// @param properties Description of the `CentipedeObject`
        EGE::Entity *createObject(std::map<std::string, std::string> &properties) override;

        /// @brief Create a `CentipedeEnvironment` from `properties`
        /// @param properties Description of the `CentipedeEnvironment`
        EGE::Entity *createEnvironment(std::map<std::string, std::string> &properties) override;

    private:
        /// @brief Load the `savegame` of Centipede.
        void loadSavegame() override {}
};

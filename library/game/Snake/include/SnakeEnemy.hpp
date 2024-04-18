/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SnakeEnemy
*/

#pragma once

#include "Entity.hpp"

/// @brief Enemy for Snake game.
class SnakeEnemy : public EGE::Entity {
    public:
        /// @brief Create an enemy with the given properties and his body part.
        /// @param properties Represents the properties of the entity (ressources, char associated, specific properties).
        SnakeEnemy(std::map<std::string, std::string> &properties);

        /// @brief Destructor.
        ~SnakeEnemy();

        /// @brief Initialize the enemy ressources.
        /// @param displayModule `Display Module` where the enemy will be displayed.
        /// @param gameModule `Game Module` where the enemy is created.
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;

        /// @brief Manage the state of the enemy (position, ...).
        /// @param entities All the entities in the game.
        /// @param gameModule `Game Module` where the enemy is created.
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

    protected:

    private:
};

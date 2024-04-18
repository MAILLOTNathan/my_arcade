/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SnakeEnvironment
*/

#pragma once

#include "Entity.hpp"

/// @brief Environment objects in Snake game.
class SnakeEnvironment : public EGE::Entity {
    public:
        /// @brief Create an environement object in Snake game.
        /// @param properties Represents the properties of the entity (ressources, char associated, specific properties).
        SnakeEnvironment(std::map<std::string, std::string> &properties);

        /// @brief Destructor.
        ~SnakeEnvironment();

        /// @brief Initialize the environment object ressources.
        /// @param displayModule `Display Module` where the environment object will be displayed.
        /// @param gameModule `Game Module` where the environment object is created.
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);

        /// @brief Manage the state of the environment object (position, ...).
        /// @param entities All the entities in the game.
        /// @param gameModule `Game Module` where the environment object is created.
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

    protected:
        
    private:
};

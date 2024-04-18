/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SnakeObject
*/

#pragma once

#include "Entity.hpp"

/// @brief Object constructor for Snake Game
class SnakeObject : public EGE::Entity {
    public:
        /// @brief Create a `SnakeObject`
        /// @param properties Represents the properties of the entity (ressources, char associated, specific properties).
        SnakeObject(std::map<std::string, std::string> &properties);

        /// @brief Destructor.
        ~SnakeObject();

        /// @brief Initialize the object ressources.
        /// @param displayModule `Display Module` where the object will be displayed.
        /// @param gameModule `Game Module` where the object is created.
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);

        /// @brief Manage the state of the object (position, ...).
        /// @param entities All the entities in the game.
        /// @param gameModule `Game Module` where the object is created.
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        /// @brief Set a random position to the object.
        /// @param entities All entities in the game.
        void setRandomPosition(std::vector<EGE::Entity *> &entities);

    private:
        /// @brief Set a random position to the object.
        /// @param entities All entities in the game.
        void setRandomPosition(size_t minX, size_t maxX, size_t minY, size_t maxY, std::vector<EGE::Entity *> &entities);
};

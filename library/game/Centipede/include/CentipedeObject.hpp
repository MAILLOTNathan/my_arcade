/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** CentipedeObject
*/

#pragma once

#include "Entity.hpp"

/// @brief Object constructor for Centipede Game
class CentipedeObject : public EGE::Entity {
    public:
        /// @brief Create a `CentipedeObject`
        /// @param properties Represents the properties of the entity (ressources, char associated, specific properties).
        CentipedeObject(std::map<std::string, std::string> &properties);

        /// @brief Destructor.
        ~CentipedeObject();

        /// @brief Initialize the object ressources.
        /// @param displayModule `Display Module` where the object will be displayed.
        /// @param gameModule `Game Module` where the object is created.
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);

        /// @brief Manage the state of the object (position, ...).
        /// @param entities All the entities in the game.
        /// @param gameModule `Game Module` where the object is created.
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

    protected:
        
    private:
};

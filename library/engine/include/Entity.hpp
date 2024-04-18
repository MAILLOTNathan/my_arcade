/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Entity
*/

#pragma once

#include "IDisplayModule.hpp"
#include "ISprite.hpp"
#include "Maths/Vector.hpp"

#include "Ressource.hpp"

#include <map>

/// @brief Mandatory properties for a game configuration file.
#define MANDATORY_PROPS std::vector<std::string>{"char", "type", "sprite"}

namespace EGE {
    class IGameModule;

    /// @brief Generic implementation of Entity into a game.
    class Entity {
        public:
            /// @brief Draws the entity with the given `Display Module`.
            /// @param displayModule Module to draw the entity.
            virtual void draw(IDisplayModule *displayModule);

            /// @brief Sets the entity position to the given `position
            /// @param position Position to be set to the entity.
            void setPosition(const Vector<int> &position);

            /// @brief Sets a `sprite` to the entity.
            /// @param sprite Sprite to be set to the entity.
            void setSprite(ISprite *sprite);

            /// @brief Returns the current `position` of the entity.
            EGE::Vector<int> getPosition() const { return this->_position; }

            /// @brief Reloads the entity with the given `Display Module`. Used when the `Display Module` changes and the `Core` reloads the games components.
            /// @param displayModule `Display Module` which reloads the entity sprite.
            /// @param gameModule `Game Module` where the entity belongs to.
            virtual void reload(IDisplayModule *displayModule, IGameModule *gameModule);

            /// @brief A simple and generic implementation of collision detection. Returns true if the `other` entity given is colliding with this entity.
            /// @param other Another entity to collide with.
            virtual bool isColliding(EGE::Entity &other);

            /// @brief An update `specific` for each `type` of entity.
            /// @param entities All the other entities in the game, with which we can interact with.
            /// @param gameModule The current `Game Module`.
            virtual void update(std::vector<EGE::Entity *> &entities, IGameModule *gameModule) = 0;

            /// @brief Initialize the entity with his specified properties.
            /// @param displayModule `Display Module` which loads graphics stuff for the entity.
            /// @param gameModule `Game Module` where the entity belongs to.
            virtual void init(IDisplayModule *displayModule, IGameModule *gameModule) = 0;

            /// @brief Returns the `sprite` of the entity.
            ISprite *getSprite() const { return this->_sprite; }

            /// @brief All the types an entity can be.
            enum Type {
                PLAYER,         // A Player entity (controlled by the user).
                ENEMY,          // A Enemy entity (managed through the game mechanic).
                ENVIRONMENT,    // A Static entity (walls, etc).
                OBJECT,         // An object entity (can be anything).
            };

            /// @brief Returns the `type` of the entity.
            Entity::Type getType() const { return this->_type; }
        protected:
            ISprite *_sprite;                       // A way of representing graphically an entity.
            Type _type;                             // Indicator of the type of the entity.
            Vector<int> _position;                  // Position of the entity.
            std::shared_ptr<Ressource> _ressource;  // A reference to the ressource loaded and used by the entity. (used for the sprite especially)
    };
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** CentipedeEnemy
*/

#pragma once

#include "Entity.hpp"

/// @brief Enemy for Centipede game.
class CentipedeEnemy : public EGE::Entity {
    public:
        /// @brief Directions the enemy can take.
        enum Direction {
            LEFT,   // Enemy going left.
            RIGHT,  // Enemy going right.
            DOWN,   // Enemy going down.
            UP      // Enemy going up.
        };

        /// @brief Body part of the enemy.
        enum Type {
            HEAD,   // Head of enemy.
            BODY    // Body of enemy.
        };

        /// @brief Create an enemy with the given properties and his body part.
        /// @param properties Represents the properties of the entity (ressources, char associated, specific properties).
        /// @param type Body part of the enemy.
        /// If it is type of `BODY`, it will create a node which will be added the the 'main' enemy. In the other case, it will create the 'main' enemy.
        CentipedeEnemy(std::map<std::string, std::string> &properties, Type type = HEAD);

        /// @brief Destructor.
        ~CentipedeEnemy();

        /// @brief Initialize the enemy ressources.
        /// @param displayModule `Display Module` where the enemy will be displayed.
        /// @param gameModule `Game Module` where the enemy is created.
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);

        /// @brief Reload all the sprites off the enemy.
        /// @param displayModule `Display Module` which displays the enemy.
        /// @param gameModule `Game Module` where the enemy is created.
        void reload(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;
  
        /// @brief Manage the state of the enemy (position, ...).
        /// @param entities All the entities in the game.
        /// @param gameModule `Game Module` where the enemy is created.
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        /// @brief Returns if the bullet is colliding with the given entity.
        /// @param entity Entity to check.
        bool isColliding(EGE::Entity *entity, EGE::IGameModule *gameModule);

        /// @brief Move the enemy.
        void move();

        /// @brief Split the enemy in 2 parts, a mandatory feature in Centipede game.
        /// @param enemy Enemy to be split.
        /// @param gameModule `Game Module` where the enemy is created.
        void split(CentipedeEnemy *enemy, EGE::IGameModule *gameModule);

        /// @brief Draws the enemy into the given `Display Module`.
        /// @param displayModule `Display Module` to draw the enemy.
        void draw(EGE::IDisplayModule *displayModule) override;

    protected:
        Direction _direction;                   // Direction of the enemy is going to.
        Direction _lastDirection;               // Last direction taken by the enemy.
        CentipedeEnemy::Type _enemyType;        // Type of enemy (`BODY` or `HEAD`).
        int _size;                              // Size of the enemy.
        int _currentSize;                       // Current size of the enemy.
        std::vector<CentipedeEnemy *> _body;    // All body parts of the enemy.
        EGE::IDisplayModule *_displayModule;    // Current diplay module used.
    private:
};

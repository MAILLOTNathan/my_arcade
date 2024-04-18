/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SnakePlayer
*/

#ifndef SNAKEPLAYER_HPP_
#define SNAKEPLAYER_HPP_

#include "Entity.hpp"
#include "IEvent.hpp"

#include "SnakeObject.hpp"

/// @brief Player in Snake Game.
class SnakePlayer : public EGE::Entity {
    /// @brief Directions the player can take.
    enum Direction {
        UP,     // Player going up.
        RIGHT,  // Player going right.
        DOWN,   // Player going down.
        LEFT    // Player going left.
    };

    /// @brief Body part the player can have.
    enum Type {
        HEAD,   // Head of the snake.
        BODY    // Other body part of the snake.
    };

    public:
        /// @brief Create a player in Snake game.
        /// @param properties Represents the properties of the player (ressources, char associated, specific properties).
        SnakePlayer(std::map<std::string, std::string> &properties, Type type = HEAD);

        /// @brief Destructor.
        ~SnakePlayer();

        /// @brief Initialize the player ressources.
        /// @param displayModule `Display Module` where the player will be displayed.
        /// @param gameModule `Game Module` where the player is created.
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;

        /// @brief Manage the state of the player (position, ...).
        /// @param entities All the entities in the game.
        /// @param gameModule `Game Module` where the player is created.
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        /// @brief Returns if the player is currently colliding with another entity.
        /// @param other Other entity to check.
        bool isColliding(EGE::Entity &other) override;
  
        // @brief Move the player in the direction set.
        void move();
  
        /// @brief Draws the snake into the given `Display Module`.
        /// @param displayModule `Display Module` to draw the snake.
        void draw(EGE::IDisplayModule *displayModule);

        /// @brief Increase the size of the player (when a player eat an apple).
        void increaseSize(EGE::IGameModule *gameModule);


    private:
        size_t _size;           // The size of the player.
        EGE::ISprite *_tail;    // Tail of the player.
        Direction _direction;   // Direction of the player
        bool _alive;            // Whether the player is alive.
        int _currentSize;       // Current size of the player.
        Type _playerType;       // Body part of the player (`HEAD` or `BODY`)
        Direction _lastDirection;   // Last direction taken by the player.
        std::vector<SnakePlayer *> _body;   // All body parts of the player.
        EGE::IDisplayModule *_displayModule;  // Current `Display Module`.
};

#endif /* !SNAKEPLAYER_HPP_ */

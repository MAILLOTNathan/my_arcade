/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** CentipedePlayer
*/

#ifndef CentipedePLAYER_HPP_
#define CentipedePLAYER_HPP_

#include "Entity.hpp"
#include "IEvent.hpp"
#include "CentipedeBullet.hpp"

/// @brief Player in Centipede Game.
class CentipedePlayer : public EGE::Entity {
    public:
        /// @brief Directions the player can take.
        enum Direction {
            UP,   // Player is going up.
            DOWN, // Player is going down.
            LEFT, // Player is going left.
            RIGHT,// Player is going right.
            NONE  // Player not moving.
        };
  
        /// @brief Create a player in Centipede game.
        /// @param properties Represents the properties of the player (ressources, char associated, specific properties).
        CentipedePlayer(std::map<std::string, std::string> &properties);

        /// @brief Destructor.
        ~CentipedePlayer();

        /// @brief Draws the player into the given `Display Module`.
        /// @param displayModule `Display Module` to draw the player.
        void draw(EGE::IDisplayModule *displayModule) override;
  
        /// @brief Returns if the player is colliding with the given entity.
        /// @param entity Entity to check.
        virtual bool isColliding(EGE::Entity &other);

        /// @brief Initialize the player ressources.
        /// @param displayModule `Display Module` where the player will be displayed.
        /// @param gameModule `Game Module` where the player is created.
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);

        /// @brief Reload all the sprites off the enemy.
        /// @param displayModule `Display Module` which displays the enemy.
        /// @param gameModule `Game Module` where the enemy is created.
        void reload(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;
  
        /// @brief Manage the state of the player (position, ...).
        /// @param entities All the entities in the game.
        /// @param gameModule `Game Module` where the player is created.
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        /// @brief Change if the the player is currently shooting.
        /// @param shooting State to be set.
        void setShooting(bool shooting) { _shooting = shooting; }

        /// @brief Return if the player is currently shooting.
        bool isShooting() { return _shooting; }
        void move(Direction direction);

    private:
        std::shared_ptr<CentipedeBullet> _bullet;   // Bullet thrown by the player.
        bool _shooting;                             // State of the player (shooting or not).
        bool _alive;                                // State of the player if he is alive.
        Direction _direction;                       // Direction taken by the player.
};

#endif /* !CentipedePLAYER_HPP_ */

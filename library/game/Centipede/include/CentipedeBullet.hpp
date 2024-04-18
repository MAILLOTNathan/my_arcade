/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** CentipedeBullet
*/

#ifndef CENTIPEDEBULLET_HPP_
#define CENTIPEDEBULLET_HPP_

#include "Entity.hpp"

class CentipedePlayer;

/// @brief Bullet for centipede game.
class CentipedeBullet : public EGE::Entity {
    public:
        /// @brief Creates a bullet.
        /// @param _player Player who shoot the bullet.
        CentipedeBullet(CentipedePlayer *_player);

        /// @brief Destructor.
        ~CentipedeBullet();

        /// @brief Manage the state of the bullet (position, ...).
        /// @param entities All the entities in the game.
        /// @param gameModule `Game Module` where the bullet is created.
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        /// @brief Initialize the bullet ressources.
        /// @param displayModule `Display Module` to display the bullet.
        /// @param gameModule `Game Module` where the bullet is created.
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;

        /// @brief Draws the bullet into the given `Display Module`.
        /// @param displayModule `Display Module` to draw the bullet.
        void draw(EGE::IDisplayModule *displayModule) override;
        void reload(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;


        /// @brief Returns if the bullet is colliding with the given entity.
        /// @param entity Entity to check.
        bool isColliding(EGE::Entity &entity);

        /// @brief Change if the the bullet is currently thrown.
        /// @param shooting State to be set.
        void setShooting(bool shooting) { _shooting = shooting; }

        /// @brief Return if the bullet is currently thrown.
        bool isShooting() { return _shooting; }

    protected:
        CentipedePlayer *_player;   // The player how shoot the bullet.
        bool _shooting;             // State of the bullet (thrown or not).
    private:
};

#endif /* !CENTIPEDEBULLET_HPP_ */

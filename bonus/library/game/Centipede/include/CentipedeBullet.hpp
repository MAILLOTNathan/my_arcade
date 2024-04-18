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

class CentipedeBullet : public EGE::Entity {
    public:
        CentipedeBullet(CentipedePlayer *_player);
        ~CentipedeBullet();


        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;
        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;
        void draw(EGE::IDisplayModule *displayModule) override;

        bool isColliding(EGE::Entity &entity);
        void setShooting(bool shooting) { _shooting = shooting; }
        bool isShooting() { return _shooting; }

    protected:
        CentipedePlayer *_player;
        bool _shooting;
    private:
};

#endif /* !CENTIPEDEBULLET_HPP_ */

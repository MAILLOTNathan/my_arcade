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

class CentipedePlayer : public EGE::Entity {
    public:
        CentipedePlayer(std::map<std::string, std::string> &properties);
        ~CentipedePlayer();

        void draw(EGE::IDisplayModule *displayModule) override;

        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule);
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        void setShooting(bool shooting) { _shooting = shooting; }
        bool isShooting() { return _shooting; }

    private:
        std::shared_ptr<CentipedeBullet> _bullet;
        bool _shooting;
        bool _alive;
};

#endif /* !CentipedePLAYER_HPP_ */

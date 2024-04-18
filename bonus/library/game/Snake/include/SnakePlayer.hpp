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

class SnakePlayer : public EGE::Entity {
    enum Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    public:
        SnakePlayer(std::map<std::string, std::string> &properties);
        ~SnakePlayer();

        void init(EGE::IDisplayModule *displayModule, EGE::IGameModule *gameModule) override;
        void update(std::vector<EGE::Entity *> &entities, EGE::IGameModule *gameModule) override;

        bool isColliding(EGE::Entity &other) override;

        void increaseSize();

    private:
        size_t _size;
        EGE::ISprite *_tail;
        Direction _direction;
        bool _alive;
};

#endif /* !SNAKEPLAYER_HPP_ */

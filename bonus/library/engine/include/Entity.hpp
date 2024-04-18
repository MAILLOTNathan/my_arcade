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

#define MANDATORY_PROPS std::vector<std::string>{"char", "type", "sprite"}
#define IS_VALID_PROPERTY(prop) \
    (std::find(MANDATORY_PROPS.begin(), MANDATORY_PROPS.end(), prop) != MANDATORY_PROPS.end())

namespace EGE {
    class IGameModule;
    class Entity {
        public:
            virtual void draw(IDisplayModule *displayModule);
            void setPosition(const Vector<int> &pos);
            void setSprite(ISprite *sprite);
            EGE::Vector<int> getPosition() const { return this->_position; }

            void reload(IDisplayModule *displayModule, IGameModule *gameModule);
            virtual bool isColliding(EGE::Entity &other);


            virtual void update(std::vector<EGE::Entity *> &entities, IGameModule *gameModule) = 0;
            virtual void init(IDisplayModule *displayModule, IGameModule *gameModule) = 0;

            ISprite *getSprite() const { return this->_sprite; }

            enum Type {
                PLAYER,
                ENEMY,
                ENVIRONMENT,
                OBJECT,
            };



            Entity::Type getType() const { return this->_type; }
        protected:
            ISprite *_sprite;
            Type _type;
            Vector<int> _position;
            std::shared_ptr<Ressource> _ressource;
    };
}

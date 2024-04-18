/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include "ADisplayModule.hpp"
#include "Entity.hpp"

namespace EGE {
    class IGameModule {
        public:
            virtual ~IGameModule() = default;

            virtual void getNextFrame() = 0;
            virtual void load(EGE::IDisplayModule *displayModule) = 0;
            virtual void reload(EGE::IDisplayModule *displayModule) = 0;
            virtual void init(const std::string &gameFolder) = 0;
            virtual EGE::Entity *createPlayer(std::map<std::string, std::string> &properties) = 0;
            virtual EGE::Entity *createEnemy(std::map<std::string, std::string> &properties) = 0;
            virtual EGE::Entity *createEnvironment(std::map<std::string, std::string> &properties) = 0;
            virtual EGE::Entity *createObject(std::map<std::string, std::string> &properties) = 0;
            virtual void addEntity(EGE::Entity *entity) = 0;

        protected:
        private:
    };
}

#endif /* !IGAMEMODULE_HPP_ */

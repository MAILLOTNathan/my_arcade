/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_

#include "IGameModule.hpp"
#include "Utils.hpp"
#include "Error.hpp"
#include "Factory.hpp"

#include <map>

namespace EGE {
    class AGameModuleException : public Error {
        public:
            AGameModuleException(const std::string &message) : Error(message) {}
            ~AGameModuleException() = default;
    };
    class AGameModule : public IGameModule {
        public:
            virtual ~AGameModule() = default;

            void getNextFrame() override;

            virtual void load(EGE::IDisplayModule *displayModule) = 0;
            virtual EGE::Entity *createPlayer(std::map<std::string, std::string> &properties) = 0;
            virtual EGE::Entity *createEnemy(std::map<std::string, std::string> &properties) = 0;
            virtual EGE::Entity *createEnvironment(std::map<std::string, std::string> &properties) = 0;
            virtual EGE::Entity *createObject(std::map<std::string, std::string> &properties) = 0;

            void reload(EGE::IDisplayModule *displayModule) override;
            void init(const std::string &gameFolder) override;

            virtual void addEntity(EGE::Entity *entity) override { this->_entities.push_back(entity); }

        protected:
            EGE::IDisplayModule *_display;
            std::vector<EGE::Entity *> _entities;
            std::vector<std::map<std::string, std::string>> _model;
            std::string _savegame;

        private:
            void parseEntities(const std::string &path);
            void parseMap(const std::string &path);
            virtual void loadSavegame() = 0;

    };
}

#endif /* !AGAMEMODULE_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Factory
*/

#pragma once

#include "Error.hpp"
#include "Entity.hpp"
#include "IGameModule.hpp"

#include <functional>
#include <map>

namespace EGE {
    class FactoryException : public Error {
        public:
            FactoryException(const std::string &message) : Error(message) {}
            ~FactoryException() = default;
    };

    /// @brief Simple factory to simplify creation of entities while parsing the configuration files of a game.
    class Factory {
        public:
            /// @brief Creates an entity by the given `properties` and the current given `Game Module`.
            /// @param properties Represents the properties of the entity (ressources, char associated, specific properties)
            /// @param module `Game Module` to be used to create the entity.
            static EGE::Entity *createEntity(std::map<std::string, std::string> &properties, EGE::IGameModule *module);

    };
}

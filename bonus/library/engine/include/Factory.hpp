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

    class Factory {
        public:
            static EGE::Entity *createEntity(std::map<std::string, std::string> &properties, EGE::IGameModule *module);

    };
}

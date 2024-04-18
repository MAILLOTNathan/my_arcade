/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Factory
*/

#include "Factory.hpp"

EGE::Entity *EGE::Factory::createEntity(std::map<std::string, std::string> &properties, EGE::IGameModule *module)
{
    try {
        for (auto &property : MANDATORY_PROPS)
            if (properties.find(property) == properties.end())
                throw FactoryException("Property [" + property + "] not found.");
        if (properties["type"] == "PLAYER")
            return module->createPlayer(properties);
        if (properties["type"] == "ENEMY")
            return module->createEnemy(properties);
        if (properties["type"] == "ENVIRONMENT")
            return module->createEnvironment(properties);
        if (properties["type"] == "OBJECT")
            return module->createObject(properties);
        throw FactoryException("Entity of type [" + properties["type"] + "] does not exist.");
    } catch (const std::exception &e) {
        std::string message = "Factory (createEntity) \n\t";
        message += e.what();
        throw FactoryException(message);
    }
}

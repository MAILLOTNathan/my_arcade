/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** GUIManager
*/

#include "GUI/GUIManager.hpp"

EGE::GUIManager::GUIManager()
{
}

EGE::GUIManager::~GUIManager()
{
}


void EGE::GUIManager::addGUI(IGUI *component, const std::string &name, const std::string &type)
{
    this->_components[name] = component;
    this->_types[name] = type;
}

void EGE::GUIManager::removeGUI(const std::string &name)
{
    this->_components.erase(name);
    this->_types.erase(name);
}

void EGE::GUIManager::renderGUI(std::shared_ptr<EGE::IWindow> window)
{
    for (auto &component : this->_components) {
        component.second->draw(window);
    }
}

std::string EGE::GUIManager::getGUIName(IGUI *component)
{
    for (auto &comp : this->_components) {
        if (comp.second == component)
            return comp.first;
    }
    throw GUIManagerException("Component not found");
}

std::string EGE::GUIManager::getGUIType(IGUI *component)
{
    for (auto &comp : this->_components) {
        if (comp.second == component)
            return this->_types[comp.first];
    }
    throw GUIManagerException("Component not found");
}

std::string EGE::GUIManager::getGUIType(const std::string &name)
{
    if (this->_types.find(name) == this->_types.end())
        throw GUIManagerException("Component not found");
    return this->_types[name];
}
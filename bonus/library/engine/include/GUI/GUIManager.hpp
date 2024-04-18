/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IGUIManager
*/

#pragma once

#include "GUI/IGUI.hpp"

#include <algorithm>
#include <map>
#include <string>

#include "Error.hpp"

namespace EGE {
    class GUIManagerException : public Error {
        public:
            GUIManagerException(const std::string &message) : Error(message) {}
            ~GUIManagerException() = default;
    };

    class GUIManager {
        public:
            GUIManager();
            ~GUIManager();

            void addGUI(IGUI *component, const std::string& name, const std::string& type);
            void removeGUI(const std::string &name);

            void renderGUI(std::shared_ptr<EGE::IWindow> window);

            std::string getGUIName(IGUI *component);
            std::string getGUIType(IGUI *component);
            std::string getGUIType(const std::string& name);
        protected:
            std::map<std::string, IGUI *> _components;
            std::map<std::string, std::string> _types;
    };
}
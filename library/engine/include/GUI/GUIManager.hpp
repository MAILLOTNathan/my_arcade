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

    /// @brief `!!! DEPRECATED !!!` Manager for user interface.
    class GUIManager {
        public:
            GUIManager();
            ~GUIManager();

            /// @brief `!!! DEPRECATED !!!`
            void addGUI(IGUI *component, const std::string& name, const std::string& type);

            /// @brief `!!! DEPRECATED !!!`
            void removeGUI(const std::string &name);

            /// @brief `!!! DEPRECATED !!!`
            void renderGUI(std::shared_ptr<EGE::IWindow> window);

            /// @brief `!!! DEPRECATED !!!`
            std::string getGUIName(IGUI *component);

            /// @brief `!!! DEPRECATED !!!`
            std::string getGUIType(IGUI *component);

            /// @brief `!!! DEPRECATED !!!`
            std::string getGUIType(const std::string& name);
        protected:
            std::map<std::string, IGUI *> _components; // `!!! DEPRECATED !!!`
            std::map<std::string, std::string> _types; // `!!! DEPRECATED !!!`
    };
}
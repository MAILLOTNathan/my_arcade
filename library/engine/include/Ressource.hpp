/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Ressource
*/

#pragma once

#include <string>

namespace EGE {

    /// @brief Class representing ressource from an asset file.
    class Ressource {
        public:
            /// @brief Creates a new ressource from a path to an asset and a character
            /// @param path Path to the asset file.
            /// @param character Character representing entity into the game map.
            Ressource(const std::string &path, const std::string &character);

            /// @brief Destructor.
            ~Ressource();

            /// @brief Sets the path of the asset to the given path.
            /// @param path Path to an asset file.
            void setPath(const std::string &path);

            /// @brief Sets the character to the given character.
            /// @param character Character to be set.
            void setCharacter(const std::string &character);

            std::string _path;      // Path to an asset file (picture, 3D object, etc)
            std::string _character; // Character which represents the assets.
    };
}

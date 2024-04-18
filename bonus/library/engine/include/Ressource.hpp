/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Ressource
*/

#pragma once

#include <string>

namespace EGE {
    class Ressource {
        public:
            Ressource(const std::string &path, const std::string &character);
            ~Ressource();

            void setPath(const std::string &path);
            void setCharacter(const std::string &character);

            std::string _path;
            std::string _character;
    };
}

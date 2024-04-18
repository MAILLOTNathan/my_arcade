/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Ressource
*/

#include "Ressource.hpp"

EGE::Ressource::Ressource(const std::string &path, const std::string &character)
{
    this->_path = path;
    this->_character = character;
}

EGE::Ressource::~Ressource()
{
}

void EGE::Ressource::setPath(const std::string &path)
{
    this->_path = path;
}

void EGE::Ressource::setCharacter(const std::string &character)
{
    this->_character = character;
}
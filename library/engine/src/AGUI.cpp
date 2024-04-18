/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AGUI
*/

#include "GUI/AGUI.hpp"

void EGE::AGUI::setPosition(EGE::Vector<int> position)
{
    this->_position = position;
}


EGE::Vector<int> EGE::AGUI::getPosition()
{
    return this->_position;
}
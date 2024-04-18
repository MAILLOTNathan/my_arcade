/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AText
*/

#include "GUI/AText.hpp"

std::string EGE::AText::getText() const
{
    return this->_text;
}

EGE::Vector<int> EGE::AText::getPosition() const
{
    return this->_position;
}

EGE::Color EGE::AText::getColor() const
{
    return this->_color;
}
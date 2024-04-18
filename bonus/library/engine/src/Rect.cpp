/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Rect
*/

#include "Maths/Rect.hpp"

std::ostream &operator<<(std::ostream &os, const EGE::Rect<int> &rect)
{
    os << "Rect(" << rect.getX() << ", " << rect.getY() << ", " << rect.getWidth() << ", " << rect.getHeight() << ")";
    return os;
}

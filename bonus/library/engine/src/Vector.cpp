/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Vector
*/

#include "Maths/Vector.hpp"


std::ostream &operator<<(std::ostream &os, const EGE::Vector<int> &vec)
{
    os << "Vector(" << vec.getX() << ", " << vec.getY() << ")";
    return os;
}

bool operator==(const EGE::Vector<int> &rect, const EGE::Vector<int> &other)
{
    return (rect.getX() == other.getX() && rect.getY() == other.getY());
}

/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Color
*/

#include "GUI/Color.hpp"

EGE::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    this->_r = r;
    this->_g = g;
    this->_b = b;
    this->_a = a;
}

unsigned char EGE::Color::getRed(void) const
{
    return this->_r;
}

unsigned char EGE::Color::getGreen(void) const
{
    return this->_g;
}

unsigned char EGE::Color::getBlue(void) const
{
    return this->_b;
}

unsigned char EGE::Color::getAlpha(void) const
{
    return this->_a;
}

void EGE::Color::setRed(unsigned char red)
{
    this->_r = red;
}

void EGE::Color::setGreen(unsigned char green)
{
    this->_g = green;
}

void EGE::Color::setBlue(unsigned char blue)
{
    this->_b = blue;
}

void EGE::Color::setAlpha(unsigned char alpha)
{
    this->_a = alpha;
}
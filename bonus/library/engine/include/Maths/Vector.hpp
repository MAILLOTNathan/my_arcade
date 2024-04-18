/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Vector
*/

#pragma once

#include <iostream>

namespace EGE {
    template<typename T>
    class Vector {
        public:
            Vector(T x, T y) : _x(x), _y(y) {};
            Vector() : _x(0), _y(0) {};
            ~Vector() {};

            T getX() const { return this->_x; }
            T getY() const { return this->_y; }

            void setX(T x) { this->_x = x; }
            void setY(T y) { this->_y = y; }

            Vector<T> operator+(const Vector<T> &v) const
            {
                return Vector<T>(this->_x + v._x, this->_y + v._y);
            }

        protected:
            T _x;
            T _y;
    };
}

bool operator==(const EGE::Vector<int> &rect, const EGE::Vector<int> &other);

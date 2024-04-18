/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Vector
*/

#pragma once

#include <iostream>

namespace EGE {
    /// @brief Generic Vector implementation.
    /// @tparam T Unit of the dimensions.
    template<typename T>
    class Vector {
        public:
            /// @brief Constructor of a vector.
            /// @param x Position in x.
            /// @param y Position in y.
            Vector(T x, T y) : _x(x), _y(y) {};

            /// @brief Constructor of a vector with x = 0 and y = 0.
            Vector() : _x(0), _y(0) {};
            ~Vector() {};

            /// @brief Get the x value of the vector.
            T getX() const { return this->_x; }

            /// @brief Get the y value of the vector.
            T getY() const { return this->_y; }

            /// @brief Set the x value of the vector.
            /// @param x Position in x.
            void setX(T x) { this->_x = x; }

            /// @brief Set the y value of the vector.
            /// @param y Position in y.
            void setY(T y) { this->_y = y; }

            /// @brief Overload operator `+`, increment a vector by another.
            /// @param v Vector to be added.
            Vector<T> operator+(const Vector<T> &v) const
            {
                return Vector<T>(this->_x + v._x, this->_y + v._y);
            }

        protected:
            T _x;   // Position in x.
            T _y;   // Position in y.
    };
}


/// @brief Overload operator `==`, check if two vectors are the sames.
/// @param rect The rect to check
/// @param other The other rect to check.
bool operator==(const EGE::Vector<int> &rect, const EGE::Vector<int> &other);

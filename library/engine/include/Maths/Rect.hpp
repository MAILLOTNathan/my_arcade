/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Rect
*/

#ifndef RECT_HPP_
#define RECT_HPP_

#include "Vector.hpp"

namespace EGE {
    /// @brief Generic Rectangle implementation.
    /// @tparam T Unit of the rectangle dimensions.
    template<typename T>
    class Rect {
        public:
            /// @brief Constructor of a rectangle.
            /// @param x Position in x.
            /// @param y Position in y.
            /// @param width Width of the rectangle.
            /// @param height Height of the rectangle.
            Rect(T x, T y, T width, T height) : _x(x), _y(y), _width(width), _height(height) {};
            /// @brief Constructor of a rectangle (set all the values to 0).
            Rect() : _x(0), _y(0), _width(0), _height(0) {};
            ~Rect() = default;

            /// @brief Get the x position of the rectangle.
            T getX() const { return this->_x; }

            /// @brief Get the y position of the rectangle.
            T getY() const { return this->_y; }

            /// @brief Get the width of the rectangle.
            T getWidth() const { return this->_width; }

            /// @brief Get the height of the rectangle.
            T getHeight() const { return this->_height; }

            /// @brief Set the x position of the rectangle.
            void setX(T x) { this->_x = x; }

            /// @brief Set the y position of the rectangle.
            void setY(T y) { this->_y = y; }

            /// @brief Set the width of the rectangle.
            void setWidth(T width) { this->_width = width; }

            /// @brief Set the height of the rectangle.
            void setHeight(T height) { this->_height = height; }

            /// @brief Return if a rectangle contains a point.
            /// @param point Point to check into the rectangle.
            bool contains(Vector<T> point) {
                return (point.getX() >= this->_x && point.getX() <= this->_x + this->_width && point.getY() >= this->_y && point.getY() <= this->_y + this->_height);
            }

            /// @brief Return if a rectangle contains another rectangle.
            /// @param rect Rectangle to check into the current rectangle.
            bool intersects(const Rect<T> &rect) {
                return (this->_x < rect.getX() + rect.getWidth() && this->_x + this->_width > rect.getX() && this->_y < rect.getY() + rect.getHeight() && this->_y + this->_height > rect.getY());
            }

            /// @brief Overload of `=` operator.
            /// @param rect Rect value to be assign to the current rectangle.
            void operator=(const Rect<T> &rect) {
                this->_x = rect.getX();
                this->_y = rect.getY();
                this->_width = rect.getWidth();
                this->_height = rect.getHeight();
            }

            /// @brief Overload of `==` operator, return if a rectangle as the same properties than another rectangle.
            /// @param rect Rectangle to check properties.
            bool operator==(const Rect<T> &rect) {
                return (this->_x == rect.getX() && this->_y == rect.getY() && this->_width == rect.getWidth() && this->_height == rect.getHeight());
            }

        protected:
            T _x;       // Position in x.
            T _y;       // Position in y.
            T _width;   // Width of the rectangle.
            T _height;  // Height of the rectangle.
        private:
    };
}
#endif /* !RECT_HPP_ */

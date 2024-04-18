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
    template<typename T>
    class Rect {
        public:
            Rect(T x, T y, T width, T height) : _x(x), _y(y), _width(width), _height(height) {};
            Rect() : _x(0), _y(0), _width(0), _height(0) {};
            ~Rect() = default;

            T getX() const { return this->_x; }
            T getY() const { return this->_y; }
            T getWidth() const { return this->_width; }
            T getHeight() const { return this->_height; }

            void setX(T x) { this->_x = x; }
            void setY(T y) { this->_y = y; }
            void setWidth(T width) { this->_width = width; }
            void setHeight(T height) { this->_height = height; }

            bool contains(Vector<T> point) {
                return (point.getX() >= this->_x && point.getX() <= this->_x + this->_width && point.getY() >= this->_y && point.getY() <= this->_y + this->_height);
            }

            bool intersects(const Rect<T> &rect) {
                return (this->_x < rect.getX() + rect.getWidth() && this->_x + this->_width > rect.getX() && this->_y < rect.getY() + rect.getHeight() && this->_y + this->_height > rect.getY());
            }

            void operator=(const Rect<T> &rect) {
                this->_x = rect.getX();
                this->_y = rect.getY();
                this->_width = rect.getWidth();
                this->_height = rect.getHeight();
            }

            bool operator==(const Rect<T> &rect) {
                return (this->_x == rect.getX() && this->_y == rect.getY() && this->_width == rect.getWidth() && this->_height == rect.getHeight());
            }

        protected:
            T _x;
            T _y;
            T _width;
            T _height;
        private:
    };
}
#endif /* !RECT_HPP_ */

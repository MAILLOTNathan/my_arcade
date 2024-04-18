/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Color
*/

#pragma once

namespace EGE {
    /// @brief Class for color.
    class Color {
        public:
            /// @brief Create a new color.
            /// @param r Red value of the color.
            /// @param g Green value of the color.
            /// @param b Blue value of the color.
            /// @param a Alpha value of the color
            Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255);
            virtual ~Color() = default;

            /// @brief Returns the number of `red` in the color.
            unsigned char getRed() const;

            /// @brief Returns the number of `green` in the color.
            unsigned char getGreen() const;

            /// @brief Returns the number of `blue` in the color.
            unsigned char getBlue() const;

            /// @brief Returns the number of `alpha` in the color.
            unsigned char getAlpha() const;

            /// @brief Sets the number of `red` in the color.
            /// @param red A value between `0` and `255`.
            void setRed(unsigned char red);

            /// @brief Sets the number of `green` in the color.
            /// @param green A value between `0` and `255`.
            void setGreen(unsigned char green);

            /// @brief Sets the number of `blue` in the color.
            /// @param blue A value between `0` and `255`.
            void setBlue(unsigned char blue);

            /// @brief Sets the number of `alpha` in the color.
            /// @param alpha A value between `0` and `255`.
            void setAlpha(unsigned char alpha);

        protected:
            unsigned char _r; // Red component.
            unsigned char _g; // Green component.
            unsigned char _b; // Blue component.
            unsigned char _a; // Alpha component.
        private:
    };
}
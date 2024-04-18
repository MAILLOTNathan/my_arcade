/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Color
*/

#pragma once

namespace EGE {
    class Color {
        public:
            Color(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255);
            virtual ~Color() = default;

            unsigned char getRed() const;
            unsigned char getGreen() const;
            unsigned char getBlue() const;
            unsigned char getAlpha() const;

            void setRed(unsigned char red);
            void setGreen(unsigned char green);
            void setBlue(unsigned char blue);
            void setAlpha(unsigned char alpha);

        protected:
            unsigned char _r;
            unsigned char _g;
            unsigned char _b;
            unsigned char _a;
        private:
    };
}
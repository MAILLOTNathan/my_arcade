/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Bitmapfont
*/

#pragma once

#include "SFMLWindow.hpp"
#include "Maths/Vector.hpp"
#include "Maths/Rect.hpp"
#include "GUI/Color.hpp"

class Bitmapfont {
    public:
        Bitmapfont();
        ~Bitmapfont();

        int getWidth() const;
        int getHeight() const;

        void draw(EGE::IWindow *window, char c, const EGE::Vector<int>& pos);
        void setColor(const EGE::Color& color);

    protected:
        EGE::Rect<int> getCharPos(char c);
        std::vector<EGE::Rect<int>> getStringPos(const std::string& str);
        std::vector<EGE::Rect<int>> _charPos;

        EGE::Color _color;
        sf::Texture _sfTexture;
        sf::Sprite _sfSprite;
        sf::Rect<unsigned int> _sfRect;
        int _width;
        int _height;
    private:
};

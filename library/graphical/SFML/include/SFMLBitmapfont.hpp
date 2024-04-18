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

/// @brief SFML BitmapFont implementation.
class Bitmapfont {
    public:
        /// @brief Creates a BitmapFont.
        Bitmapfont();

        /// @brief Destructs a BitmapFont.
        ~Bitmapfont();

        /// @brief Returns the width of the font.
        int getWidth() const;

        /// @brief Returns the height of the font.
        int getHeight() const;

        /// @brief Draws the font.
        /// @param window The window to draw the font on.
        void draw(EGE::IWindow *window, char c, const EGE::Vector<int>& pos);

        /// @brief Sets the font color.
        /// @param color Color to be set on the font.
        void setColor(const EGE::Color& color);

    protected:
        /// @brief Returns the position of the character.
        /// @param c Char to get the position.
        EGE::Rect<int> getCharPos(char c);

        /// @brief Returns the string position.
        /// @param str String to get the position.
        std::vector<EGE::Rect<int>> getStringPos(const std::string& str);

        std::vector<EGE::Rect<int>> _charPos; // All characters positions.

        EGE::Color _color;              // Color of the text.
        sf::Texture _sfTexture;         // Texture of the font.
        sf::Sprite _sfSprite;           // Sprite of the font.
        sf::Rect<unsigned int> _sfRect; // Rect of the font.
        int _width;                     // Width of the font.
        int _height;                    // Height of the font.
    private:
};

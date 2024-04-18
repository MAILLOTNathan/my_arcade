/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SDLBitmapfont
*/

#ifndef SDLBITMAPFONT_HPP_
#define SDLBITMAPFONT_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include "Maths/Rect.hpp"
#include "SDLWindow.hpp"
#include "GUI/Color.hpp"

/// @brief SDL2 BitmapFont implementation.
class Bitmapfont {
    public:
        /// @brief Creates a BitmapFont.
        Bitmapfont();

        /// @brief Destructs a BitmapFont.
        ~Bitmapfont();

        /// @brief Returns the width of the font.
        int getWidth(void) const;

        /// @brief Returns the height of the font.
        int getHeight(void) const;

        /// @brief Draws the font.
        /// @param window The window to draw the font on.
        /// @param c Char to draw.
        /// @param pos Position of the char.
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

        EGE::Color _color;          // Color of the text.
        SDL_Surface *_sprite;       // Surface of the font.
        SDL_Texture *_texture;      // Texture of the font.
        SDL_Rect _rect;             // Rect of the font.
        int _width;                 // Width of the font.
        int _height;                // Height of the font.
    private:
};

#endif /* !SDLBITMAPFONT_HPP_ */

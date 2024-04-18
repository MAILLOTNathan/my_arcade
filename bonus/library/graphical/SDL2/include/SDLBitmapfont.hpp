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

class Bitmapfont {
    public:
        Bitmapfont();
        ~Bitmapfont();

        int getWidth(void) const;
        int getHeight(void) const;
        void draw(EGE::IWindow *window, char c, const EGE::Vector<int>& pos);
        void setColor(const EGE::Color& color);

    protected:
        EGE::Rect<int> getCharPos(char c);
        std::vector<EGE::Rect<int>> getStringPos(const std::string& str);
        std::vector<EGE::Rect<int>> _charPos;

        EGE::Color _color;
        SDL_Surface *_sprite;
        SDL_Texture *_texture;
        SDL_Rect _rect;
        int _width;
        int _height;
    private:
};

#endif /* !SDLBITMAPFONT_HPP_ */

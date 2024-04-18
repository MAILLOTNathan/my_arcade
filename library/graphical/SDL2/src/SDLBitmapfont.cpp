/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SDLBitmapfont
*/

#include "SDLBitmapfont.hpp"

Bitmapfont::Bitmapfont()
{
    this->_width = 8;
    this->_height = 12;
    this->_sprite = IMG_Load("./library/graphical/SDL2/bitmapfont.png");
    SDL_SetColorKey(this->_sprite, SDL_TRUE, SDL_MapRGB(this->_sprite->format, 255, 0, 255));
    this->_texture = NULL;
    this->_rect = {0, 0, this->_sprite->w, this->_sprite->h};
    for (int i = 0; i < 256; i++) {
        this->_charPos.push_back(this->getCharPos(i));
    }
}

Bitmapfont::~Bitmapfont()
{
    SDL_FreeSurface(this->_sprite);
    SDL_DestroyTexture(this->_texture);
}

int Bitmapfont::getWidth(void) const
{
    return this->_width;
}

int Bitmapfont::getHeight(void) const
{
    return this->_height;
}

EGE::Rect<int> Bitmapfont::getCharPos(char c)
{
    int y = (c >> 4) * this->_height;
    int x = (c & 15) << 3;
    return EGE::Rect<int>(x, y, this->_width, this->_height);
}

std::vector<EGE::Rect<int>> Bitmapfont::getStringPos(const std::string &str)
{
    std::vector<EGE::Rect<int>> vec;
    for (char c : str)
        vec.push_back(this->getCharPos(c));
    return vec;
}

void Bitmapfont::draw(EGE::IWindow *window, char c, const EGE::Vector<int>& pos)
{
    Window *sdlWin = dynamic_cast<Window *>(window);
    SDL_Window *win = sdlWin->getWindow();
    SDL_Rect rect = {pos.getX(), pos.getY(), this->_width * 3, this->_height * 3};
    EGE::Rect<int> charRect = this->_charPos[c];
    SDL_Rect charRectS = {charRect.getX(), charRect.getY(), charRect.getWidth(), charRect.getHeight()};

    if (this->_texture == NULL)
        this->_texture = SDL_CreateTextureFromSurface(sdlWin->getRenderer(), this->_sprite);
    SDL_SetTextureColorMod(this->_texture, this->_color.getRed(), this->_color.getGreen(), this->_color.getBlue());
    SDL_RenderCopy(sdlWin->getRenderer(), this->_texture, &charRectS, &rect);
}

void Bitmapfont::setColor(const EGE::Color &color)
{
    this->_color = color;
}
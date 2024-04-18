/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Sprite
*/

#include "SDLSprite.hpp"

Sprite::Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos)
{
    this->_sprite = IMG_Load(ressource->_path.c_str());
    this->_texture = NULL;
    this->_rect = { pos.getX(), pos.getY(), this->_sprite->w, this->_sprite->h };
    this->_pos = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
}

Sprite::~Sprite()
{
    SDL_FreeSurface(this->_sprite);
    SDL_DestroyTexture(this->_texture);
}

void Sprite::setPosition(const EGE::Vector<int> &pos)
{
    this->_pos = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
    this->_rect = { pos.getX(), pos.getY(), this->_sprite->w, this->_sprite->h };
}

void Sprite::setPosition(int x, int y)
{
    this->setPosition(EGE::Vector<int>(x, y));
}

void Sprite::draw(std::shared_ptr<EGE::IWindow> window)
{
    Window *sdlWin = dynamic_cast<Window *>(window.get());
    SDL_Window *win = sdlWin->getWindow();
    SDL_Rect rect = {this->_pos.getX(), this->_pos.getY(), TILE_SIZE, TILE_SIZE};

    if (this->_texture == NULL)
        this->_texture = SDL_CreateTextureFromSurface(sdlWin->getRenderer(), this->_sprite);
    SDL_RenderCopy(sdlWin->getRenderer(), this->_texture, NULL, &rect);
}

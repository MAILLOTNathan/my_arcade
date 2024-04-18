/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SDLSprite
*/

#pragma once

#include "ASprite.hpp"
#include "SDLWindow.hpp"

#include <SDL2/SDL_image.h>
#include "Maths/Rect.hpp"

#include "Ressource.hpp"

#include <string>

class Sprite : public EGE::ASprite {
    public:
        Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos);
        virtual ~Sprite() override;

        void draw(std::shared_ptr<EGE::IWindow> window) override;

        void setPosition(const EGE::Vector<int>& pos) override;
        void setPosition(int x, int y) override;

    private:
        SDL_Surface *_sprite;
        SDL_Texture *_texture;
        SDL_Rect _rect;

};

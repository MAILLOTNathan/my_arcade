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

/// @brief SDL2 Sprite implementation.
class Sprite : public EGE::ASprite {
    public:
        /// @brief Creates a SDL2 sprite.
        /// @param ressource Ressource of the sprite (containing the path to the asset).
        /// @param pos Position of the sprite to be set.
        Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos);

        /// @brief Destructs a SDL2 sprite.
        virtual ~Sprite() override;

        /// @brief Draws the sprite to the specified `window`.
        /// @param window Window to draw the sprite
        void draw(std::shared_ptr<EGE::IWindow> window) override;

        /// @brief Sets the sprite position to the specified `positions`.
        /// @param pos Position to be set to the sprite.
        void setPosition(const EGE::Vector<int>& pos) override;

        /// @brief Sets the sprite position to the specified `positions`.
        /// @param x Position to be set to the sprite in x coordinates.
        /// @param y Position to be set to the sprite in y coordinates.
        void setPosition(int x, int y) override;

    private:
        SDL_Surface *_sprite;   // The SDL_Surface of this sprite.
        SDL_Texture *_texture;  // The texture of the SDL_Surface.
        SDL_Rect _rect;         // The rect of the SDL_Surface.

};

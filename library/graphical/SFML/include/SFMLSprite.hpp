/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SFMLSprite
*/

#pragma once

#include "ASprite.hpp"
#include "SFMLWindow.hpp"

#include <string>
#include <SFML/Graphics.hpp>

#include "Ressource.hpp"

/// @brief SFML Sprite implementation.
class Sprite : public EGE::ASprite {
    public:
        /// @brief Creates a SFML sprite.
        /// @param ressource Ressource of the sprite (containing the path to the asset).
        /// @param pos Position of the sprite to be set.
        Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos);

        /// @brief Destructs a SFML sprite.
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
        sf::Sprite _sprite;     // The sf::Sprite of this sprite.
        sf::Texture _texture;   // The texture of the sf::Sprite.
};

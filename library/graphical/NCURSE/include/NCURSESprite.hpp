/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSESprite
*/

#pragma once

#include "ASprite.hpp"
#include "NCURSEWindow.hpp"

#include "Ressource.hpp"

#include <string>

/// @brief NCURSE Sprite implementation.
class Sprite : public EGE::ASprite {
    public:
        /// @brief Creates a NCURSE sprite.
        /// @param ressource Ressource of the sprite (containing the path to the asset).
        /// @param pos Position of the sprite to be set.
        Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos);

        /// @brief Destructs a NCURSE sprite.
        ~Sprite();

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
        std::string _sprite;        // The path to the sprite.
        EGE::Vector<int> _oldPos;   // The old position of the sprite.
};

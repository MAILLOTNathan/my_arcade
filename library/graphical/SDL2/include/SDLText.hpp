/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SDLText
*/

#pragma once

#include <SDL2/SDL.h>

#include "GUI/AText.hpp"
#include "SDLSprite.hpp"
#include "SDLBitmapfont.hpp"

/// @brief SDL2 Text implementation.
class Text : public EGE::AText {
    public:
        /// @brief Creates a SDL2 Text.
        /// @param text Content of the text.
        /// @param pos Position of the text.
        /// @param color Color of the text.
        Text(const std::string& text, const EGE::Vector<int>& pos, const EGE::Color& color);

        /// @brief Destroys the SDL2 Text.
        virtual ~Text() override;

        /// @brief Draws the text in the given `window`.
        /// @param window Window where the text will be drawn.
        void draw(std::shared_ptr<EGE::IWindow> window) override;

        /// @brief Sets the contents of the text.
        /// @param text Reprensents the value of the contents of the text.
        void setText(const std::string& text) override;

        /// @brief Sets the position of the text.
        /// @param position Reprensents the value of the position of the text.
        void setColor(const EGE::Color& color) override;

        /// @brief Sets the position of the text.
        /// @param position Reprensents the value of the position of the text.
        void setPosition(const EGE::Vector<int>& pos) override;

    protected:
        std::shared_ptr<Bitmapfont> _font;  // Font of the SDL2 text.
    private:
};

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SDLButtton
*/

#pragma once

#include "GUI/AButton.hpp"
#include "SDLText.hpp"
#include "SDLBitmapfont.hpp"

/// @brief SDL2 Button implementation.
class Button : public EGE::AButton {
    public:
        /// @brief Creates a SDL2 Button.
        /// @param text Content of the text which will be displayed on the button.
        /// @param pos Position of the button.
        Button(const std::string& text, const EGE::Vector<int>& pos);

        /// @brief Destructs a SDL2 Button.
        ~Button();

        /// @brief Draws the button.
        /// @param window The window to draw the button on.
        void draw(std::shared_ptr<EGE::IWindow> window) override;

        /// @brief Sets the text of the button.
        /// @param text Text to be set on the button.
        void setText(const std::string& text) override;

        /// @brief Set the current `state` of the button to `normal`.
        void normal() override;

        /// @brief Set the current `state` of the button to `hover`.
        void hover() override;

        /// @brief Set the current `state` of the button to `click`.
        void click() override;
};

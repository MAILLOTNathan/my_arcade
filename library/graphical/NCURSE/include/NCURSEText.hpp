/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEText
*/

#pragma once

#include "GUI/AText.hpp"
#include "NCURSEWindow.hpp"

/// @brief NCURSE Text implementation.
class Text : public EGE::AText {
    public:
        /// @brief Creates a NCURSE Text.
        /// @param text Content of the text.
        /// @param pos Position of the text.
        /// @param color Color of the text.
        Text(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color &color);

        /// @brief Destroys the NCURSE Text.
        ~Text();

        /// @brief Sets the contents of the text.
        /// @param text Reprensents the value of the contents of the text.
        void setText(const std::string& text) override;

        /// @brief Sets the position of the text.
        /// @param position Reprensents the value of the position of the text.
        void setPosition(const EGE::Vector<int>& position) override;

        /// @brief Sets the color of the text.
        /// @param color Reprensents the value of the color of the text.
        void setColor(const EGE::Color &color) override;

        /// @brief Draws the text in the given `window`.
        /// @param window Window where the text will be drawn.
        void draw(std::shared_ptr<EGE::IWindow> window) override;

};


/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IButton
*/

#pragma once

#include "AGUI.hpp"

namespace EGE {
    /// @brief Interface for Button.
    class IButton : public AGUI {
        public:

            /// @brief Draws the button.
            /// @param window The window to draw on.
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            /// @brief Sets the text of the button.
            /// @param text The text to set.
            virtual void setText(const std::string& text) = 0;

            /// @brief Returns the `text` of the button.
            virtual std::string getText() = 0;

            /// @brief Sets the `position` of the button.
            /// @param position The `position` to set.
            virtual void setPosition(EGE::Vector<int> position) = 0;

            /// @brief Returns the `position` of the button.
            virtual EGE::Vector<int> getPosition() = 0;

            /// @brief Set the current `state` of the button to `hover`.
            virtual void hover() = 0;

            /// @brief Set the current `state` of the button to `normal`.
            virtual void normal() = 0;

            /// @brief Set the current `state` of the button to `click`.
            virtual void click() = 0;

    };
}

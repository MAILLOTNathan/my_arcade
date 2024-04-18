/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IText
*/

#pragma once

#include "GUI/AGUI.hpp"
#include "Maths/Vector.hpp"
#include "GUI/Color.hpp"

#include <string>

namespace EGE {
    /// @brief Interface with a text.
    class IText : public AGUI {
        public:
            virtual ~IText() = default;

            /// @brief Draws the text in the given `window`.
            /// @param window Window where the text will be drawn.
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            /// @brief Sets the contents of the text.
            /// @param text Reprensents the value of the contents of the text.
            virtual void setText(const std::string& text) = 0;

            /// @brief Returns the contents of the text.
            virtual std::string getText() const = 0;

            /// @brief Sets the position of the text.
            virtual void setPosition(const Vector<int>& position) = 0;

            /// @brief Returns the current position of the text.
            virtual Vector<int> getPosition() const = 0;

            /// @brief Sets a color to the text.
            /// @param color Color to be set to the text.
            virtual void setColor(const Color& color) = 0;

            /// @brief Returns the current color of the text.
            virtual Color getColor() const = 0;
    };
}
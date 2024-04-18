/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AText
*/

#pragma once

#include "GUI/IText.hpp"

namespace EGE {
    /// @brief Abstract class of a text.
    class AText : public EGE::IText {
        public:
            virtual ~AText() = default;

            /// @brief Draws the text in the given `window`.
            /// @param window Window where the text will be drawn.
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            /// @brief Sets the contents of the text.
            /// @param text Reprensents the value of the contents of the text.
            virtual void setText(const std::string& text) = 0;

            /// @brief Returns the contents of the text.
            virtual std::string getText() const;

            /// @brief Sets the position of the text.
            /// @param position Reprensents the value of the position of the text.
            virtual void setPosition(const Vector<int>& position) = 0;

            /// @brief Returns the current position of the text.
            virtual Vector<int> getPosition() const;

            /// @brief Sets a color to the text.
            /// @param color Color to be set to the text.
            virtual void setColor(const Color& color) = 0;

            /// @brief Returns the current color of the text.
            virtual Color getColor() const;

        protected:
            std::string _text;      // `Content` of the text.
            Vector<int> _position;  // `Position` of the text.
            Color _color;           // `Color` of the text.
    };
}

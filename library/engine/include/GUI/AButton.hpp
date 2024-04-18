/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AButton
*/

#pragma once

#include "GUI/IButton.hpp"
#include "GUI/IText.hpp"
#include <string>

namespace EGE {
    /// @brief Abstract class representing a button.
    class AButton : public IButton {
        public:
            ~AButton() = default;

            /// @brief Draws the button.
            /// @param window The window to draw the button on.
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            /// @brief Sets the `text` of the button.
            /// @param text The text to set.
            virtual void setText(const std::string& text);

            /// @brief Returns the `text` of the button.
            virtual std::string getText();

            /// @brief Sets the `position` of the button.
            /// @param position The position to set.
            virtual void setPosition(EGE::Vector<int> position);

            /// @brief Returns the `position` of the button.
            virtual EGE::Vector<int> getPosition();

            /// @brief Set the current `state` of the button to `normal`.
            virtual void normal() = 0;

            /// @brief Set the current `state` of the button to `hover`.
            virtual void hover() = 0;

            /// @brief Set the current `state` of the button to `click`.
            virtual void click() = 0;

            /// @brief Set a function when a button is `click`.
            /// @param onClick Function to be called when the button is clicked.
            virtual void setOnClick(std::function<void()> onClick);

            /// @brief Set a function when a button is `hover`.
            /// @param onHover Function to be called when the button is hovered.
            virtual void setOnHover(std::function<void()> onHover);
        protected:
            EGE::Vector<int> _position;     // Position of the button.
            EGE::IText *_text;              // Text content of the button.
            std::function<void()> _onClick; // Function called when the button is clicked.
            std::function<void()> _onHover; // Function called when the button is hovered.
            bool _isHover;                  // State of the button when it's hover.
            bool _isClick;                  // State of the button when it's clicked.
    };
}

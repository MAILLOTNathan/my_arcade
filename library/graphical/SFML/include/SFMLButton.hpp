/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SFMLButton
*/

#ifndef SFMLBUTTON_HPP_
#define SFMLBUTTON_HPP_

#include "GUI/AButton.hpp"
#include "SFMLWindow.hpp"
#include "SFMLText.hpp"

/// @brief SFML Button implementation.
class Button : public EGE::AButton {
    public:
        /// @brief Creates a SFML Button.
        /// @param text Content of the text which will be displayed on the button.
        /// @param pos Position of the button.
        Button(const std::string &text, const EGE::Vector<int> &pos);

        /// @brief Destructs a SFML Button.
        ~Button();

        /// @brief Draws the button.
        /// @param window The window to draw the button on.
        void draw(std::shared_ptr<EGE::IWindow> window) override;

        /// @brief Set the current `state` of the button to `normal`.
        void normal() override;

        /// @brief Set the current `state` of the button to `hover`.
        void hover() override;

        /// @brief Set the current `state` of the button to `click`.
        void click() override;
};

#endif /* !SFMLBUTTON_HPP_ */

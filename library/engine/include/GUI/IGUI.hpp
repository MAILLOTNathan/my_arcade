/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IGUI
*/

#pragma once

#include "IWindow.hpp"
#include "ADrawable.hpp"

namespace EGE {
    /// @brief Interface for Graphical User Interface objects.
    class IGUI : public ADrawable {
        public:
            /// @brief Draws the GUI object in the given `window`.
            /// @param window Window where the GUI object will be drawn.
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;
    };
}
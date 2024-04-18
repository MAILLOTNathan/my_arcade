/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** ADrawable
*/

#pragma once

#include "IDrawable.hpp"

namespace EGE {
    /// @brief Abstract class for drawable objects.
    class ADrawable : public IDrawable {
        public:
            ~ADrawable() = default;

            /// @brief Draws the object.
            /// @param window Window where the object is to be drawn.
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;
    };
}
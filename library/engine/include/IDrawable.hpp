/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IDrawable
*/

#pragma once

#include "IWindow.hpp"
#include <memory>

#define TILE_SIZE 32

namespace EGE {
    /// @brief Interface for drawable objects.
    class IDrawable {
        public:
            /// @brief Draws the object.
            /// @param window Window where the object is to be drawn.
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;
    };
}

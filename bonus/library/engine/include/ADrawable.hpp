/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** ADrawable
*/

#pragma once

#include "IDrawable.hpp"

namespace EGE {
    class ADrawable : public IDrawable {
        public:
            ~ADrawable() = default;

            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;
    };
}
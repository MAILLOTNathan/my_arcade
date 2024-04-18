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
    class IGUI : public ADrawable {
        public:
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;
    };
}
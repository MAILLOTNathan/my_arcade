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
    class IText : public AGUI {
        public:
            virtual ~IText() = default;
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            virtual void setText(const std::string& text) = 0;
            virtual std::string getText() const = 0;

            virtual void setPosition(const Vector<int>& position) = 0;
            virtual Vector<int> getPosition() const = 0;

            virtual void setColor(const Color& color) = 0;
            virtual Color getColor() const = 0;
    };
}
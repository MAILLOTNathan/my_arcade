/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AText
*/

#pragma once

#include "GUI/IText.hpp"

namespace EGE {
    class AText : public EGE::IText {
        public:
            virtual ~AText() = default;

            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            virtual void setText(const std::string& text) = 0;
            virtual std::string getText() const;

            virtual void setPosition(const Vector<int>& position) = 0;
            virtual Vector<int> getPosition() const;

            virtual void setColor(const Color& color) = 0;
            virtual Color getColor() const;

        protected:
            std::string _text;
            Vector<int> _position;
            Color _color;
    };
}

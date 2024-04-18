/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IButton
*/

#pragma once

#include "AGUI.hpp"

namespace EGE {
    class IButton : public AGUI {
        public:
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            virtual void setText(const std::string& text) = 0;
            virtual std::string getText() = 0;

            virtual void setPosition(EGE::Vector<int>) = 0;
            virtual EGE::Vector<int> getPosition() = 0;

            virtual void hover() = 0;
            virtual void normal() = 0;
            virtual void click() = 0;

    };
}

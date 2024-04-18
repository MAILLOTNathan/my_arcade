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
    class AButton : public IButton {
        public:
            ~AButton() = default;

            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            virtual void setText(const std::string& text);
            virtual std::string getText();

            virtual void setPosition(EGE::Vector<int>);
            virtual EGE::Vector<int> getPosition();

            virtual void normal() = 0;
            virtual void hover() = 0;
            virtual void click() = 0;

            virtual void setOnClick(std::function<void()> onClick);
            virtual void setOnHover(std::function<void()> onHover);
        protected:
            EGE::Vector<int> _position;
            EGE::IText *_text;
            std::function<void()> _onClick;
            std::function<void()> _onHover;
            bool _isHover;
            bool _isClick;
    };
}

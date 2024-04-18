/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SDLButtton
*/

#pragma once

#include "GUI/AButton.hpp"
#include "SDLText.hpp"
#include "SDLBitmapfont.hpp"

class Button : public EGE::AButton {
    public:
        Button(const std::string& text, const EGE::Vector<int>& pos);
        ~Button();

        void draw(std::shared_ptr<EGE::IWindow> window) override;

        void setText(const std::string& text) override;

        void normal() override;
        void hover() override;
        void click() override;
};

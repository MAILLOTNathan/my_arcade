/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** SDLText
*/

#pragma once

#include <SDL2/SDL.h>

#include "GUI/AText.hpp"
#include "SDLSprite.hpp"
#include "SDLBitmapfont.hpp"

class Text : public EGE::AText {
    public:
        Text(const std::string& text, const EGE::Vector<int>& pos, const EGE::Color& color);
        virtual ~Text() override;

        void draw(std::shared_ptr<EGE::IWindow> window) override;

        void setText(const std::string& text) override;
        void setColor(const EGE::Color& color) override;
        void setPosition(const EGE::Vector<int>& pos) override;

    protected:
        std::shared_ptr<Bitmapfont> _font;
    private:
};

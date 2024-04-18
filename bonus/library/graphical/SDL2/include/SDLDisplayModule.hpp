/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** DisplayModule
*/

#pragma once

#include "ADisplayModule.hpp"
#include "SDLWindow.hpp"
#include "SDLEvent.hpp"
#include "SDLSprite.hpp"
#include "SDLText.hpp"
#include "SDLButton.hpp"

class DisplayModule : public EGE::ADisplayModule {
    public:
        DisplayModule();
        ~DisplayModule();

        void init() override;

        EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int>& pos) override;
        EGE::IText *createText(const std::string &text, const EGE::Vector<int>& pos, const EGE::Color& color) override;
        EGE::IButton *createButton(const std::string &text, const EGE::Vector<int>& pos) override;

    protected:
    private:
};

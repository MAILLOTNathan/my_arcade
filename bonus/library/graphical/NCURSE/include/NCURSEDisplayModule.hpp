/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEDisplayModule
*/

#pragma once

#include "ADisplayModule.hpp"
#include "NCURSEWindow.hpp"
#include "NCURSESprite.hpp"
#include "NCURSEText.hpp"
#include "NCURSEButton.hpp"

class DisplayModule : public EGE::ADisplayModule {
    public:
        DisplayModule();
        virtual ~DisplayModule() override;

        void init() override;
        EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos) override;
        EGE::IText *createText(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color& color) override;
        EGE::IButton *createButton(const std::string &text, const EGE::Vector<int> &pos) override;

    protected:
    private:
};

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSESprite
*/

#pragma once

#include "ASprite.hpp"
#include "NCURSEWindow.hpp"

#include "Ressource.hpp"

#include <string>

class Sprite : public EGE::ASprite {
    public:
        Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos);
        ~Sprite();

        void draw(std::shared_ptr<EGE::IWindow> window) override;

        void setPosition(const EGE::Vector<int>& pos) override;
        void setPosition(int x, int y) override;

    private:
        std::string _sprite;
        EGE::Vector<int> _oldPos;
};

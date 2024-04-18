/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEText
*/

#pragma once

#include "GUI/AText.hpp"
#include "NCURSEWindow.hpp"

class Text : public EGE::AText {
    public:
        Text(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color &color);
        ~Text();

        void setText(const std::string& text) override;
        void setPosition(const EGE::Vector<int>& position) override;

        void setColor(const EGE::Color &color) override;
        void draw(std::shared_ptr<EGE::IWindow> window) override;

};


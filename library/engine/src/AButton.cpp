/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AButton
*/

#include "GUI/AButton.hpp"

void EGE::AButton::setText(const std::string &text)
{
    this->_text->setText(text);
}

std::string EGE::AButton::getText()
{
    return this->_text->getText();
}

void EGE::AButton::setPosition(EGE::Vector<int> position)
{
    this->_position = position;
}

EGE::Vector<int> EGE::AButton::getPosition()
{
    return this->_position;
}

void EGE::AButton::setOnClick(std::function<void()> onClick)
{
    this->_onClick = onClick;
}

void EGE::AButton::setOnHover(std::function<void()> onHover)
{
    this->_onHover = onHover;
}
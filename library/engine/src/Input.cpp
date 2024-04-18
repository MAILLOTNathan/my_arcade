/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Input
*/

#include "GUI/Input.hpp"

EGE::Input::Input(EGE::IDisplayModule *graphic, const EGE::Vector<int>& pos)
{
    this->_text = graphic->createText("", pos, {255, 255, 255});
}

EGE::Input::~Input()
{
    delete this->_text;
}

void EGE::Input::draw(std::shared_ptr<EGE::IWindow> window)
{
    this->_text->draw(window);
}

void EGE::Input::addChar(char c)
{
    this->_text->setText(this->_text->getText() + c);
}

void EGE::Input::removeChar()
{
    std::string text = this->_text->getText();
    if (text.size() > 0)
        text.pop_back();
    this->_text->setText(text);
}

std::string EGE::Input::getText() const
{
    return this->_text->getText();
}

void EGE::Input::removeText()
{
    this->_input = this->_text->getText();
    delete this->_text;
    this->_text = nullptr;
}

void EGE::Input::reload(EGE::IDisplayModule *graphic, const EGE::Vector<int>& pos)
{
    std::string text = this->_input;

    this->_text = graphic->createText(text, pos,  {255, 255, 255});
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** ADisplayModule
*/

#include "ADisplayModule.hpp"
#include <iostream>

void EGE::ADisplayModule::windowClear()
{
    this->_window->clear();
}

void EGE::ADisplayModule::windowDisplay()
{
    this->_window->display();
}

void EGE::ADisplayModule::windowClose()
{
    this->_window->close();
}

void EGE::ADisplayModule::windowPollEvent()
{
    this->_window->pollEvent();
}

bool EGE::ADisplayModule::windowIsOpen()
{
    return this->_window->isOpen();
}

void EGE::ADisplayModule::bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func)
{
    this->_window->getEvent()->bindKey(trigger, func);
}

std::shared_ptr<EGE::IWindow> EGE::ADisplayModule::getWindow()
{
    return this->_window;
}

EGE::IDrawable *EGE::ADisplayModule::createSprite(Ressource *ressource)
{
    return this->createSprite(ressource, EGE::Vector<int>(0, 0));
}

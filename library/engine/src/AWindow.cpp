/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AWindow
*/

#include "AWindow.hpp"

std::unique_ptr<EGE::IEvent>& EGE::AWindow::getEvent()
{
    return this->_event;
}
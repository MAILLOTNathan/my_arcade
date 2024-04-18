/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** AEvent
*/

#include "AEvent.hpp"
#include "IWindow.hpp"

void EGE::AEvent::setKeyboardEnabled(bool enabled)
{
    this->_keyboardEnabled = enabled;
}

void EGE::AEvent::setMouseEnabled(bool enabled)
{
    this->_mouseEnabled = enabled;
}


void EGE::AEvent::setMouseHidden(bool hidden)
{
    this->_mouseHidden = hidden;
}

bool EGE::AEvent::isKeyboardEnabled() const
{
    return this->_keyboardEnabled;
}

bool EGE::AEvent::isMouseEnabled() const
{
    return this->_mouseEnabled;
}

bool EGE::AEvent::isMouseHidden() const
{
    return this->_mouseHidden;
}

void EGE::AEvent::bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func)
{
    this->_keyMap[trigger] = func;
}

void EGE::AEvent::bindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger, std::function<void(void)> func)
{
    this->_mouseMap[trigger] = func;
}

void EGE::AEvent::unbindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger)
{
    this->_keyMap.erase(trigger);
}

void EGE::AEvent::unbindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger)
{
    this->_mouseMap.erase(trigger);
}

std::uint32_t EGE::AEvent::keyboardTranslate(EGE::Event::Keyboard trigger)
{
    return this->_keyboardTranslate[trigger];
}

std::uint32_t EGE::AEvent::mouseTranslate(EGE::Event::Mouse trigger)
{
    return this->_mouseTranslate[trigger];
}

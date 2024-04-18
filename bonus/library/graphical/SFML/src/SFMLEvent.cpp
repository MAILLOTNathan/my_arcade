/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Event
*/

#include "SFMLEvent.hpp"
#include "SFMLWindow.hpp"

Event::Event()
{
    this->_mouseEnabled = true;
    this->_keyboardEnabled = true;
}

Event::~Event()
{
}

void Event::bindMouseScroll(std::unique_ptr<EGE::IWindow> window, std::function<void(double, double)> func)
{
    this->_mouseScrollFunc = func;
}

void Event::unbindMouseScroll(void)
{
    this->_mouseScrollFunc = nullptr;
}

void Event::manageKeyboardEvent(EGE::IWindow *window)
{
    if (this->_event.type == sf::Event::KeyPressed) {
        for (auto it = this->_keyMap.begin(); it != this->_keyMap.end(); it++) {
            if (this->keyboardTranslate(it->first->getTrigger()) == this->_event.key.code && (!it->first->isPressed() || it->first->getType() == EGE::Event::PRESSED)) {
                it->first->setPressed(true);
                if (it->first->getType() <= EGE::Event::JUST_PRESSED)
                    it->second();
                break;
            }
        }
    }
    if (this->_event.type == sf::Event::KeyReleased) {
        for (auto it = this->_keyMap.begin(); it != this->_keyMap.end(); it++) {
            if (this->keyboardTranslate(it->first->getTrigger()) == this->_event.key.code && (it->first->isPressed() || it->first->getType() == EGE::Event::RELEASED)) {
                it->first->setPressed(false);
                if (it->first->getType() >= EGE::Event::RELEASED)
                    it->second();
                break;
            }
        }
    }
}

void Event::manageMouseEvent(EGE::IWindow *window)
{
    if (this->_event.type == sf::Event::MouseButtonReleased) {
        for (auto it = this->_mouseMap.begin(); it != this->_mouseMap.end(); it++) {
            if (this->mouseTranslate(it->first->getTrigger()) == this->_event.mouseButton.button && (it->first->isPressed() || it->first->getType() == EGE::Event::RELEASED)) {
                it->first->setPressed(false);
                if (it->first->getType() >= EGE::Event::RELEASED)
                    it->second();
                break;
            }
        }
    }
    if (this->_event.type == sf::Event::MouseButtonPressed) {
        for (auto& it: this->_mouseMap) {
            if (sf::Mouse::isButtonPressed((sf::Mouse::Button)it.first->getTrigger()) && (!it.first->isPressed() || it.first->getType() == EGE::Event::PRESSED)) {
                it.first->setPressed(true);
                if (it.first->getType() <= EGE::Event::JUST_PRESSED)
                    it.second();
                    break;
            }
        }
    }
    if (this->_event.type == sf::Event::MouseWheelScrolled) {
        if (this->_event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
            if (this->_event.mouseWheelScroll.delta > 0)
                this->_mouseScrollFunc(0, 1);
            else if (this->_event.mouseWheelScroll.delta < 0)
                this->_mouseScrollFunc(0, -1);
        }
        if (this->_event.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel) {
            if (this->_event.mouseWheelScroll.delta > 0)
                this->_mouseScrollFunc(1, 0);
            else if (this->_event.mouseWheelScroll.delta < 0)
                this->_mouseScrollFunc(-1, 0);
        }
    }
}

void Event::manageEvent(EGE::IWindow *window)
{
    Window *win = dynamic_cast<Window *>(window);

    while (win->getWindow()->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed)
            window->close();
        if (this->_mouseEnabled)
            this->manageMouseEvent(window);
        if (this->_keyboardEnabled)
            this->manageKeyboardEvent(window);
    }
}

std::uint32_t Event::keyboardTranslate(EGE::Event::Keyboard trigger)
{
    return trigger;
}

std::uint32_t Event::mouseTranslate(EGE::Event::Mouse trigger)
{
    return trigger;
}

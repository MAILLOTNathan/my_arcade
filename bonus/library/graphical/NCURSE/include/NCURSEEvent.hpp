/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEEvent
*/

#pragma once

#include "AEvent.hpp"
#include "NCURSEWindow.hpp"

class Event : public EGE::AEvent {
    public:
        Event();
        ~Event();

        void bindMouseScroll(std::unique_ptr<EGE::IWindow> window, std::function<void(std::double_t, std::double_t)> func) override;
        void unbindMouseScroll(void) override;

        void manageKeyboardEvent(EGE::IWindow *window) override;
        void manageMouseEvent(EGE::IWindow *window) override;
        void manageEvent(EGE::IWindow *window) override;

        std::uint32_t keyboardTranslate(EGE::Event::Keyboard button) override;
        std::uint32_t mouseTranslate(EGE::Event::Mouse button) override;

    protected:
    private:
        void _initKeyboardTranslate();

        std::function<void(std::double_t, std::double_t)> _mouseScrollFunc;
        int _event;
};

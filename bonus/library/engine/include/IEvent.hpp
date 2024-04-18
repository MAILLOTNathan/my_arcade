/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IEvent
*/

#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>
#include "Trigger.hpp"
#include <cstdint>

namespace EGE {

    class IWindow;

    class IEvent {
        public:
            virtual ~IEvent() = default;
            virtual void setKeyboardEnabled(bool enabled) = 0;
            virtual void setMouseEnabled(bool enabled) = 0;
            virtual void setMouseHidden(bool hidden)  = 0;
            virtual bool isKeyboardEnabled(void) const = 0;
            virtual bool isMouseEnabled(void) const = 0;
            virtual bool isMouseHidden(void) const = 0;


            virtual void bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func) = 0;
            virtual void bindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger, std::function<void(void)> func) = 0;
            virtual void bindMouseScroll(std::unique_ptr<IWindow> window, std::function<void(std::double_t, std::double_t)> func) = 0;

            virtual void unbindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger) = 0;
            virtual void unbindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger) = 0;
            virtual void unbindMouseScroll(void) = 0;

            virtual std::uint32_t keyboardTranslate(EGE::Event::Keyboard trigger) = 0;
            virtual std::uint32_t mouseTranslate(EGE::Event::Mouse trigger) = 0;

            virtual void manageKeyboardEvent(EGE::IWindow *window) = 0;
            virtual void manageMouseEvent(EGE::IWindow *window) = 0;
            virtual void manageEvent(EGE::IWindow *window) = 0;

        protected:
        private:
    };
}

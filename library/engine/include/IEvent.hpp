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

    /// @brief Interface for events.
    class IEvent {
        public:
            virtual ~IEvent() = default;

            /// @brief Change the state of `_keyboardEnabled`.
            /// @param enabled New state to be set.
            virtual void setKeyboardEnabled(bool enabled) = 0;

            /// @brief Change the state of `_mouseEnabled`.
            /// @param enabled New state to be set.
            virtual void setMouseEnabled(bool enabled) = 0;

            /// @brief Change the state of `_mouseHidden`.
            /// @param hidden New state to be set.
            virtual void setMouseHidden(bool hidden)  = 0;

            /// @brief Returns if the keyboard is enabled or not.
            virtual bool isKeyboardEnabled(void) const = 0;

            /// @brief Returns if the mouse is enabled or not.
            virtual bool isMouseEnabled(void) const = 0;

            /// @brief Returns if the mouse is hidden or not.
            virtual bool isMouseHidden(void) const = 0;

            /// @brief Bind a `key` to an `action`
            /// @param trigger `Key` or `Trigger` to be bound.
            /// @param func `Action` launched when the trigger is triggered.
            virtual void bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func) = 0;

            /// @brief Bind mouse actions.
            /// @param trigger Trigger to be bound.
            /// @param func Action to be executed when the trigger is triggered.
            virtual void bindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger, std::function<void(void)> func) = 0;

            /// @brief Unbind an action set on a key.
            /// @param trigger Trigger to be unbound.
            virtual void bindMouseScroll(std::unique_ptr<IWindow> window, std::function<void(std::double_t, std::double_t)> func) = 0;

            /// @brief Unbind an action set on a key.
            /// @param trigger Trigger to be unbound.
            virtual void unbindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger) = 0;

            /// @brief Unbind an action set on the mouse
            /// @param trigger Trigger to be unbound.
            virtual void unbindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger) = 0;

            /// @brief Unbind an action set on the mouse scroll.
            virtual void unbindMouseScroll(void) = 0;

            /// @brief Translates a `Key` to a specific `Library key` (for example: between SFML and SDL events are not the sames).
            /// @param trigger `Key` to be translated.
            virtual std::uint32_t keyboardTranslate(EGE::Event::Keyboard trigger) = 0;

            /// @brief Translates mouse events to a specific `Mouse event` (for example: between SFML and SDL are not the sames).
            /// @param trigger Event to be translated
            virtual std::uint32_t mouseTranslate(EGE::Event::Mouse trigger) = 0;

            /// @brief Manages Keyboard events on a specific `Graphical Library`.
            /// @param window Window where we have to manage keyboard events.
            virtual void manageKeyboardEvent(EGE::IWindow *window) = 0;

            /// @brief Manages Mouse events on a specific `Graphical Library`.
            /// @param window Window where we have to manage mouse events.
            virtual void manageMouseEvent(EGE::IWindow *window) = 0;

            /// @brief Manages events on a specific `Graphical Library`.
            /// @param window Window where we have to manage events.
            virtual void manageEvent(EGE::IWindow *window) = 0;

        protected:
        private:
    };
}

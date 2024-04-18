/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** AEvent
*/

#ifndef AEVENT_HPP_
#define AEVENT_HPP_

#include "IEvent.hpp"
#include <map>
#include <functional>

namespace EGE {
    /// @brief Abstract class for events.
    class AEvent : public IEvent {
        public:
            virtual ~AEvent() = default;

            /// @brief Change the state of `_keyboardEnabled`.
            /// @param enabled New state to be set.
            virtual void setKeyboardEnabled(bool enabled) override;

            /// @brief Change the state of `_mouseEnabled`.
            /// @param enabled New state to be set.
            virtual void setMouseEnabled(bool enabled) override;

            /// @brief Change the state of `_mouseHidden`.
            /// @param hidden New state to be set.
            virtual void setMouseHidden(bool hidden) override;

            /// @brief Returns if the keyboard is enabled or not.
            virtual bool isKeyboardEnabled(void) const override;

            /// @brief Returns if the mouse is enabled or not.
            virtual bool isMouseEnabled(void) const override;

            /// @brief Returns if the mouse is hidden or not.
            virtual bool isMouseHidden(void) const override;

            /// @brief Bind a `key` to an `action`
            /// @param trigger `Key` or `Trigger` to be bound.
            /// @param func `Action` launched when the trigger is triggered.
            virtual void bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func) override;

            /// @brief Bind mouse actions.
            /// @param trigger Trigger to be bound.
            /// @param func Action to be executed when the trigger is triggered.
            virtual void bindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger, std::function<void(void)> func) override;

            /// @brief Unbind an action set on a key.
            /// @param trigger Trigger to be unbound.
            virtual void unbindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger) override;

            /// @brief Unbind an action set on the mouse
            /// @param trigger Trigger to be unbound.
            virtual void unbindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger) override;

            /// @brief Unbind an action set on the mouse scroll.
            virtual void unbindMouseScroll(void) = 0;

            /// @brief Translates a `Key` to a specific `Library key` (for example: between SFML and SDL events are not the sames).
            /// @param trigger `Key` to be translated.
            virtual std::uint32_t keyboardTranslate(EGE::Event::Keyboard trigger) override;

            /// @brief Translates mouse events to a specific `Mouse event` (for example: between SFML and SDL are not the sames).
            /// @param trigger Event to be translated
            virtual std::uint32_t mouseTranslate(EGE::Event::Mouse trigger) override;

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
            bool _mouseEnabled;     // State of mouse: enabled or disabled.
            bool _mouseHidden;      // State of mouse: hidden or visible.
            bool _keyboardEnabled;  // State of keyboard: enabled or disabled.

            std::map<std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>>, std::function<void(void)>> _keyMap;    // Map of key linked to their actions.
            std::map<std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>>, std::function<void(void)>> _mouseMap;     // Map of mouse events linked to their actions.

            std::map<EGE::Event::Keyboard, std::uint32_t> _keyboardTranslate;   // Translations between `Keys` and `Values`
            std::map<EGE::Event::Mouse, std::uint32_t> _mouseTranslate;         // Translations between `Mouse events` and `Values`
        private:
    };
}


#endif /* !AEVENT_HPP_ */

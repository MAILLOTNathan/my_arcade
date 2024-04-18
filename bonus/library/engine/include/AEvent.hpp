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
    class AEvent : public IEvent {
        public:
            virtual ~AEvent() = default;

            virtual void setKeyboardEnabled(bool enabled) override;
            virtual void setMouseEnabled(bool enabled) override;
            virtual void setMouseHidden(bool hidden) override;
            virtual bool isKeyboardEnabled(void) const override;
            virtual bool isMouseEnabled(void) const override;
            virtual bool isMouseHidden(void) const override;


            virtual void bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func) override;
            virtual void bindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger, std::function<void(void)> func) override;

            virtual void unbindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger) override;
            virtual void unbindMouse(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>> trigger) override;
            virtual void unbindMouseScroll(void) = 0;

            virtual std::uint32_t keyboardTranslate(EGE::Event::Keyboard trigger) override;
            virtual std::uint32_t mouseTranslate(EGE::Event::Mouse trigger) override;

            virtual void manageKeyboardEvent(EGE::IWindow *window) = 0;
            virtual void manageMouseEvent(EGE::IWindow *window) = 0;
            virtual void manageEvent(EGE::IWindow *window) = 0;

        protected:
            bool _mouseEnabled;
            bool _mouseHidden;
            bool _keyboardEnabled;

            std::map<std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>>, std::function<void(void)>> _keyMap;
            std::map<std::shared_ptr<EGE::Event::Trigger<EGE::Event::Mouse>>, std::function<void(void)>> _mouseMap;

            std::map<EGE::Event::Keyboard, std::uint32_t> _keyboardTranslate;
            std::map<EGE::Event::Mouse, std::uint32_t> _mouseTranslate;
        private:
    };
}


#endif /* !AEVENT_HPP_ */

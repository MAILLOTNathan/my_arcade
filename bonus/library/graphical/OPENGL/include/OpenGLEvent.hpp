/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLEvent
*/

#ifndef OPENGLEVENT_HPP_
#define OPENGLEVENT_HPP_

#include "OpenGL.hpp"
#include "AEvent.hpp"
#include "OpenGLWindow.hpp"

class Event : public EGE::AEvent {
    public:
        Event();
        ~Event();

        void bindMouseScroll(std::unique_ptr<EGE::IWindow> window, std::function<void(double_t, double_t)> func) override;
        void unbindMouseScroll() override;

        void manageKeyboardEvent(EGE::IWindow *window) override;
        void manageMouseEvent(EGE::IWindow *window) override;
        void manageEvent(EGE::IWindow *window) override;

    protected:
        void _initKeyboardTranslate();
    private:
};

#endif /* !OPENGLEVENT_HPP_ */

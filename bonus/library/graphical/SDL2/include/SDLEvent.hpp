/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "AEvent.hpp"
#include <SDL2/SDL.h>
#include "SDLWindow.hpp"

class Event : public EGE::AEvent {
    public:
        Event();
        ~Event();

        virtual void bindMouseScroll(std::unique_ptr<EGE::IWindow> window, std::function<void(std::double_t, std::double_t)> func) override;
        void unbindMouseScroll(void) override;

        virtual void manageKeyboardEvent(EGE::IWindow *window) override;
        virtual void manageMouseEvent(EGE::IWindow *window) override;
        virtual void manageEvent(EGE::IWindow *window) override;

    protected:
    private:
        void _initKeyboardTranslate(void);
        SDL_Event event;
};

#endif /* !EVENT_HPP_ */


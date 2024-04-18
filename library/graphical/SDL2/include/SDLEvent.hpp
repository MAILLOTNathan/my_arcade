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

/// @brief SDL2 event implementation.
class Event : public EGE::AEvent {
    public:
        /// @brief Creates a SDL2 event.
        Event();

        /// @brief Destroys a SDL2 event.
        ~Event();

        /// @brief Bind an action set on a key.
        /// @param window The window where we have to bind the action.
        /// @param func Function that will be called back.
        virtual void bindMouseScroll(std::unique_ptr<EGE::IWindow> window, std::function<void(std::double_t, std::double_t)> func) override;

        /// @brief Unbind an action set on the mouse scroll.
        void unbindMouseScroll(void) override;

        /// @brief Manages Keyboard events on a specific `Graphical Library`.
        /// @param window Window where we have to manage keyboard events.
        virtual void manageKeyboardEvent(EGE::IWindow *window) override;

        /// @brief Manages Mouse events on a specific `Graphical Library`.
        /// @param window Window where we have to manage mouse events.
        virtual void manageMouseEvent(EGE::IWindow *window) override;

        /// @brief Manages events on a specific `Graphical Library`.
        /// @param window Window where we have to manage events.
        virtual void manageEvent(EGE::IWindow *window) override;

    protected:
    private:
        /// @brief Init the map of SDL2 keyboard translation.
        void _initKeyboardTranslate(void);

        SDL_Event event; /// Current SDL_Event.
};

#endif /* !EVENT_HPP_ */


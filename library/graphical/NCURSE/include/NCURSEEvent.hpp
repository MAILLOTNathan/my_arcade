/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** NCURSEEvent
*/

#pragma once

#include "AEvent.hpp"
#include "NCURSEWindow.hpp"

/// @brief NCURSE Event implementation.
class Event : public EGE::AEvent {
    public:
        /// @brief Creates a NCURSE Event.
        Event();

        /// @brief Destroys a NCURSE Event.
        ~Event();

        /// @brief Bind an action set on a key.
        /// @param window The window where we have to bind the action.
        /// @param func Function that will be called back.
        void bindMouseScroll(std::unique_ptr<EGE::IWindow> window, std::function<void(std::double_t, std::double_t)> func) override;

        /// @brief Unbind an action set on the mouse scroll.
        void unbindMouseScroll(void) override;

        /// @brief Manages Keyboard events on a specific `Graphical Library`.
        /// @param window Window where we have to manage keyboard events.
        void manageKeyboardEvent(EGE::IWindow *window) override;

        /// @brief Manages Mouse events on a specific `Graphical Library`.
        /// @param window Window where we have to manage mouse events.
        void manageMouseEvent(EGE::IWindow *window) override;

        /// @brief Manages events on a specific `Graphical Library`.
        /// @param window Window where we have to manage events.
        void manageEvent(EGE::IWindow *window) override;

        /// @brief Translates a EGE::Event::Keyboard to a specific NCURSE keyboard event.
        /// @param trigger `Key` to be translated.
        /// @return The translated key.
        std::uint32_t keyboardTranslate(EGE::Event::Keyboard button) override;

        /// @brief Translates a EGE::Event::Mouse to a specific NCURSE mouse event.
        /// @param trigger Event to be translated
        /// @return The translated mouse event.
        std::uint32_t mouseTranslate(EGE::Event::Mouse button) override;

    protected:
    private:
        /// @brief Init the map of NCURSE keyboard translation.
        void _initKeyboardTranslate();

        std::function<void(std::double_t, std::double_t)> _mouseScrollFunc; // Function assiociated to mouse scroll.
        int _event;                                                         // Current NCURSE event.
};

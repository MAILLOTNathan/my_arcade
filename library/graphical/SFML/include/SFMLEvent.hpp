/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Event
*/

#pragma once

#include "AEvent.hpp"

#include <SFML/Graphics.hpp>

#include <functional>
#include <memory>
#include "SFMLWindow.hpp"

/// @brief SFML event implementation.
class Event : public EGE::AEvent {
    public:
        /// @brief Creates a SFML event.
        Event();

        /// @brief Destroys a SFML event.
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

        /// @brief Translates a EGE::Event::Keyboard to a specific SFML keyboard event.
        /// @param trigger `Key` to be translated.
        std::uint32_t keyboardTranslate(EGE::Event::Keyboard trigger) override;

        /// @brief Translates a EGE::Event::Mouse to a specific SFML mouse event.
        /// @param trigger Event to be translated
        std::uint32_t mouseTranslate(EGE::Event::Mouse trigger) override;

    protected:
    private:
        std::function<void(std::double_t, std::double_t)> _mouseScrollFunc;     // All functions assiociated to mouse scroll.
        sf::Event _event;                                                       // Current sf::Event.
};

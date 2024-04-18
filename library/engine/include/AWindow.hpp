/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AWindow
*/

#pragma once

#include "IEvent.hpp"
#include <memory>
#include "IWindow.hpp"

namespace EGE {
    /// @brief Abstract class for Window.
    class AWindow : public EGE::IWindow {
        public:
            virtual ~AWindow() = default;

            /// @brief Returns whether the window is currently open or closed.
            virtual bool isOpen() const = 0;

            /// @brief Clears the window.
            virtual void clear() = 0;

            /// @brief Displays the window.
            virtual void display() = 0;

            /// @brief Close the window.
            virtual void close() = 0;

            /// @brief `Catches` and `manages` events.
            virtual void pollEvent() = 0;

            /// @brief Returns the current event caught (`_event`).
            std::unique_ptr<EGE::IEvent>& getEvent() override;


        protected:
            std::unique_ptr<EGE::IEvent> _event;    // Current caught event.
        private:
    };
}

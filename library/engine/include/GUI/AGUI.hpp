/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AGUI
*/

#pragma once

#include "GUI/IGUI.hpp"
#include "Maths/Vector.hpp"

namespace EGE {
    /// @brief Abstract class for Graphical User Interface objects.
    class AGUI : public EGE::IGUI {
        public:
            virtual ~AGUI() = default;

            /// @brief Draws the GUI object in the given `window`.
            /// @param window Window where the GUI object will be drawn.
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            /// @brief Sets the position of the GUI object.
            /// @param position New position of the GUI object.
            virtual void setPosition(Vector<int> position);

            /// @brief Returns the position of the GUI object.
            virtual Vector<int> getPosition();
        protected:
            Vector<int> _position;  // Position of the GUI object.
    };
}

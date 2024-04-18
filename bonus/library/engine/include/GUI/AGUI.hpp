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
    class AGUI : public EGE::IGUI {
        public:
            virtual ~AGUI() = default;

            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            virtual void setPosition(Vector<int> position);
            virtual Vector<int> getPosition();
        protected:
            Vector<int> _position;
    };
}

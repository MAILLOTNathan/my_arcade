/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** ISprite
*/

#ifndef ISPRITE_HPP_
#define ISPRITE_HPP_

#include "Maths/Vector.hpp"
#include "IWindow.hpp"
#include "ADrawable.hpp"

#include <memory>

namespace EGE {
    class ISprite : public ADrawable {
        public:
            virtual ~ISprite() = default;
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            virtual void setPosition(const Vector<int>& pos) = 0;
            virtual void setPosition(int x, int y) = 0;
            virtual Vector<int> getPosition() const = 0;

    };
}

#endif /* !ISPRITE_HPP_ */

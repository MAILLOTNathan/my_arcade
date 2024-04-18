/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** ASprite
*/

#ifndef ASPRITE_HPP_
#define ASPRITE_HPP_

#include "ISprite.hpp"

namespace EGE {
    class ASprite : public ISprite {
        public:
            virtual ~ASprite() override = default;

            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            virtual void setPosition(const Vector<int>& pos) = 0;
            virtual void setPosition(int x, int y) = 0;
            virtual Vector<int> getPosition() const;

        protected:
            Vector<int> _pos;
    };
}

#endif /* !ASPRITE_HPP_ */

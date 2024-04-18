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
    /// @brief Abstract class representing Srites objects.
    class ASprite : public ISprite {
        public:
            virtual ~ASprite() override = default;

            /// @brief Draws the sprite to the specified `window`.
            /// @param window Window to draw the sprite
            virtual void draw(std::shared_ptr<EGE::IWindow> window) = 0;

            /// @brief Sets the sprite position to the specified `positions`.
            /// @param pos Position to be set to the sprite.
            virtual void setPosition(const Vector<int>& pos) = 0;

            /// @brief Sets the sprite position to the specified `positions`.
            /// @param x Position to be set to the sprite in x coordinates.
            /// @param y Position to be set to the sprite in y coordinates.
            virtual void setPosition(int x, int y) = 0;

            /// @brief Return the sprite's position.
            virtual Vector<int> getPosition() const;

        protected:
            Vector<int> _pos;   // Position of the sprite.
    };
}

#endif /* !ASPRITE_HPP_ */

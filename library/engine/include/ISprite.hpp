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

    /// @brief Interface for Srites objects.
    class ISprite : public ADrawable {
        public:
            virtual ~ISprite() = default;

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
            virtual Vector<int> getPosition() const = 0;

    };
}

#endif /* !ISPRITE_HPP_ */

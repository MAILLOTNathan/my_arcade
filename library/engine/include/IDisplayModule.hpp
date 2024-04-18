/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IDisplayModule
*/

#pragma once

#include "IWindow.hpp"
#include "ISprite.hpp"
#include "IEvent.hpp"
#include "Maths/Vector.hpp"
#include "GUI/IText.hpp"
#include "GUI/AButton.hpp"

#include "Ressource.hpp"

#include <memory>
#include <string>

namespace EGE {
    /// @brief Interface of `Display Module`.
    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;

            /// @brief `Initializes` the module with the specific values.
            virtual void init() = 0;

            /// @brief Returns if the `window` of the module is currently `open`.
            virtual bool windowIsOpen() = 0;

            /// @brief `Clears` the `window` of the module.
            virtual void windowClear() = 0;

            /// @brief `Display` the content given to the module on the `window`.
            virtual void windowDisplay() = 0;

            /// @brief `Close` the `window` of the module.
            virtual void windowClose() = 0;

            /// @brief `Catches` and `manages` `events` in the module's `window`.
            virtual void windowPollEvent() = 0;

            /// @brief Returns the `window` of the module.
            virtual std::shared_ptr<EGE::IWindow> getWindow() = 0;

            /// @brief `Bind` a `trigger` to an `action`.
            /// @param trigger Trigger to be `assigned` to an action.
            /// @param func Function to be called when the trigger is `triggered`.
            virtual void bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func) = 0;

            /// @brief `Bind` a `trigger` to an `action`.
            /// @param trigger Trigger to be `assigned` to an action.
            /// @param func Function to be called when the trigger is `triggered`.
            virtual EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos) = 0;

                        /// @brief Create a sprite using the current library loaded `without knowing` which library it is.
            /// It is like a call of `createSprite(*ressource*, EGE::Vector<int>(0,0))`
            /// @param ressource `Ressource` which represents the `source` of the content of the sprite.
            virtual EGE::IDrawable *createSprite(EGE::Ressource *ressource) = 0;

            /// @brief Create a text using the current library loaded `without knowing` which library it is.
            /// @param text Content of the text.
            /// @param pos Position of the text.
            /// @param color Color to be set on the text.
            virtual EGE::IText *createText(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color& color) = 0;

            /// @brief Create a button using the current library loaded `without knowing` which library it is.
            /// @param text Text showed on the button.
            /// @param pos Position of the button.
            virtual EGE::IButton *createButton(const std::string &text, const EGE::Vector<int> &pos) = 0;
    };
}

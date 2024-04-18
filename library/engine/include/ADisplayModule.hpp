/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** ADisplayModule
*/

#pragma once

#include "IDisplayModule.hpp"

namespace EGE {
    /// @brief Abstract class which represents a `Display Module`.
    class ADisplayModule : public IDisplayModule {
        public:
            virtual ~ADisplayModule() override = default;

            /// @brief `Initializes` the module with the specific values.
            virtual void init() = 0;

            /// @brief Returns if the `window` of the module is currently `open`.
            virtual bool windowIsOpen() override;

            /// @brief `Clears` the `window` of the module.
            virtual void windowClear() override;

            /// @brief `Display` the content given to the module on the `window`.
            virtual void windowDisplay() override;

            /// @brief `Close` the `window` of the module.
            virtual void windowClose() override;

            /// @brief `Catches` and `manages` `events` in the module's `window`.
            virtual void windowPollEvent() override;

            /// @brief Returns the `window` of the module.
            virtual std::shared_ptr<EGE::IWindow> getWindow() override;

            /// @brief `Bind` a `trigger` to an `action`.
            /// @param trigger Trigger to be `assigned` to an action.
            /// @param func Function to be called when the trigger is `triggered`.
            virtual void bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func) override;

            /// @brief Create a sprite using the current library loaded `without knowing` which library it is.
            /// @param ressource `Ressource` which represents the `source` of the content of the sprite.
            /// @param pos `Position` of the sprite.
            virtual EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos) = 0;

            /// @brief Create a sprite using the current library loaded `without knowing` which library it is.
            /// It is like a call of `createSprite(*ressource*, EGE::Vector<int>(0,0))`
            /// @param ressource `Ressource` which represents the `source` of the content of the sprite.
            virtual EGE::IDrawable *createSprite(EGE::Ressource *ressource) override;

            /// @brief Create a text using the current library loaded `without knowing` which library it is.
            /// @param text Content of the text.
            /// @param pos Position of the text.
            /// @param color Color to be set on the text.
            virtual EGE::IText *createText(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color& color) = 0;

            /// @brief Create a button using the current library loaded `without knowing` which library it is.
            /// @param text Text showed on the button.
            /// @param pos Position of the button.
            virtual EGE::IButton *createButton(const std::string &text, const EGE::Vector<int> &pos) = 0;
        protected:
            std::shared_ptr<EGE::IWindow> _window;  // The window stored in the `Display Module`.
    };
}

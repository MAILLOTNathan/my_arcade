/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** DisplayModule
*/

#pragma once

#include "ADisplayModule.hpp"
#include "SDLWindow.hpp"
#include "SDLEvent.hpp"
#include "SDLSprite.hpp"
#include "SDLText.hpp"
#include "SDLButton.hpp"

/// @brief SDL2 Display Module implementation.
class DisplayModule : public EGE::ADisplayModule {
    public:
        /// @brief Creates a SDL2 Display Module.
        DisplayModule();

        /// @brief Destroys a SDL2 Display Module.
        ~DisplayModule();

        /// @brief `Initializes` the module with the specific values.
        void init() override;

        /// @brief Create a sprite using the current library loaded `without knowing` which library it is.
        /// @param ressource `Ressource` which represents the `source` of the content of the sprite.
        /// @param pos `Position` of the sprite.
        /// @return The created sprite.
        EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int>& pos) override;

        /// @brief Create a text using the current library loaded `without knowing` which library it is.
        /// @param text Content of the text.
        /// @param pos Position of the text.
        /// @param color Color to be set on the text.
        /// @return The created text.
        EGE::IText *createText(const std::string &text, const EGE::Vector<int>& pos, const EGE::Color& color) override;

        /// @brief Create a button using the current library loaded `without knowing` which library it is.
        /// @param text Text showed on the button.
        /// @param pos Position of the button.
        /// @return The created button.
        EGE::IButton *createButton(const std::string &text, const EGE::Vector<int>& pos) override;

    protected:
    private:
};

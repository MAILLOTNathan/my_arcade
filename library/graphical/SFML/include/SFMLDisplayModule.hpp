/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** DisplayModule
*/

#ifndef DISPLAYMODULE_HPP_
#define DISPLAYMODULE_HPP_

#include "ADisplayModule.hpp"
#include "SFMLWindow.hpp"
#include "SFMLEvent.hpp"
#include <memory>
#include "SFMLSprite.hpp"
#include "SFMLText.hpp"
#include "SFMLButton.hpp"

/// @brief SFML Display Module implementation.
class DisplayModule : public EGE::ADisplayModule {
    public:
        /// @brief Creates a SFML Display Module.
        DisplayModule();

        /// @brief Destroys a SFML Display Module.
        virtual ~DisplayModule() override;

        /// @brief `Initializes` the module with the specific values.
        void init() override;

        /// @brief Create a sprite using the current library loaded `without knowing` which library it is.
        /// @param ressource `Ressource` which represents the `source` of the content of the sprite.
        /// @param pos `Position` of the sprite.
        EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int>& pos) override;

        /// @brief Create a text using the current library loaded `without knowing` which library it is.
        /// @param text Content of the text.
        /// @param pos Position of the text.
        /// @param color Color to be set on the text.
        EGE::IText *createText(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color& color) override;

        /// @brief Create a button using the current library loaded `without knowing` which library it is.
        /// @param text Text showed on the button.
        /// @param pos Position of the button.
        EGE::IButton *createButton(const std::string &text, const EGE::Vector<int> &pos) override;

    protected:
    private:
};

#endif /* !DISPLAYMODULE_HPP_ */

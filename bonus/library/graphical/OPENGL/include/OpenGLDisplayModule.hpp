/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLDisplayModule
*/

#ifndef OPENGLDISPLAYMODULE_HPP_
#define OPENGLDISPLAYMODULE_HPP_

#include "ADisplayModule.hpp"
#include "OpenGLWindow.hpp"
#include "OpenGLEvent.hpp"
#include "OpenGLSprite.hpp"
#include "OpenGLText.hpp"
#include "OpenGLButton.hpp"

class DisplayModule : public EGE::ADisplayModule {
    public:
        DisplayModule();
        ~DisplayModule();

        void init() override;

        EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int>& pos) override;
        EGE::IText *createText(const std::string &text, const EGE::Vector<int>& pos, const EGE::Color& color) override;
        EGE::IButton *createButton(const std::string &text, const EGE::Vector<int>& pos) override;

    protected:
    private:
};

#endif /* !OPENGLDISPLAYMODULE_HPP_ */

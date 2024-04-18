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

class DisplayModule : public EGE::ADisplayModule {
    public:
        DisplayModule();
        virtual ~DisplayModule() override;

        void init() override;
        EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int>& pos) override;
        EGE::IText *createText(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color& color) override;
        EGE::IButton *createButton(const std::string &text, const EGE::Vector<int> &pos) override;

    protected:
    private:
};

#endif /* !DISPLAYMODULE_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** ADisplayModule
*/

#pragma once

#include "IDisplayModule.hpp"

namespace EGE {
    class ADisplayModule : public IDisplayModule {
        public:
            virtual ~ADisplayModule() override = default;

            virtual void init() = 0;

            virtual bool windowIsOpen() override;
            virtual void windowClear() override;
            virtual void windowDisplay() override;
            virtual void windowClose() override;
            virtual void windowPollEvent() override;
            virtual std::shared_ptr<EGE::IWindow> getWindow() override;
            virtual void bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func) override;
            virtual EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos) = 0;
            virtual EGE::IDrawable *createSprite(EGE::Ressource *ressource) override;
            virtual EGE::IText *createText(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color& color) = 0;
            virtual EGE::IButton *createButton(const std::string &text, const EGE::Vector<int> &pos) = 0;
        protected:
            std::shared_ptr<EGE::IWindow> _window;
    };
}

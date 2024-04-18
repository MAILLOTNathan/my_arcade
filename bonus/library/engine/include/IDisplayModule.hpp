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
    class IDisplayModule {
        public:
            virtual ~IDisplayModule() = default;

            virtual void init() = 0;

            virtual bool windowIsOpen() = 0;
            virtual void windowClear() = 0;
            virtual void windowDisplay() = 0;
            virtual void windowClose() = 0;
            virtual void windowPollEvent() = 0;
            virtual std::shared_ptr<EGE::IWindow> getWindow() = 0;

            virtual void bindKey(std::shared_ptr<EGE::Event::Trigger<EGE::Event::Keyboard>> trigger, std::function<void(void)> func) = 0;

            virtual EGE::IDrawable *createSprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos) = 0;
            virtual EGE::IDrawable *createSprite(EGE::Ressource *ressource) = 0;
            virtual EGE::IText *createText(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color& color) = 0;
            virtual EGE::IButton *createButton(const std::string &text, const EGE::Vector<int> &pos) = 0;
    };
}

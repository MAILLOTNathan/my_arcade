/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AWindow
*/

#pragma once

#include "IEvent.hpp"
#include <memory>
#include "IWindow.hpp"

namespace EGE {
class AWindow : public EGE::IWindow {
    public:
        virtual ~AWindow() = default;

        virtual bool isOpen() const = 0;
        virtual void clear() = 0;
        virtual void display() = 0;
        virtual void close() = 0;
        virtual void pollEvent() = 0;
        std::unique_ptr<EGE::IEvent>& getEvent() override;


    protected:
        std::unique_ptr<EGE::IEvent> _event;
    private:
    };
}

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IWindow
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#include "IEvent.hpp"

namespace EGE {
    class IWindow {
        public:
            virtual ~IWindow() = default;

            virtual bool isOpen() const = 0;
            virtual void clear() = 0;
            virtual void display() = 0;
            virtual void close() = 0;
            virtual void pollEvent() = 0;

            virtual std::unique_ptr<EGE::IEvent>& getEvent() = 0;
    };
}

#endif /* !IWINDOW_HPP_ */

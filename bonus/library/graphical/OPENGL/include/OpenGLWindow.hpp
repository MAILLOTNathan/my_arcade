/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLWindow
*/

#ifndef OPENGLWINDOW_HPP_
#define OPENGLWINDOW_HPP_

#include "OpenGL.hpp"
#include <iostream>
#include "AWindow.hpp"
#include "OpenGLEvent.hpp"

class Window : public EGE::AWindow {
    public:
        Window(const std::string& title, unsigned int x, unsigned int y);
        ~Window();

        bool isOpen() const override;
        void clear() override;
        void display() override;
        void close() override;
        void pollEvent() override;

        GLFWwindow *getWindow() const;

    protected:
        GLFWwindow *window;
    private:
};

#endif /* !OPENGLWINDOW_HPP_ */

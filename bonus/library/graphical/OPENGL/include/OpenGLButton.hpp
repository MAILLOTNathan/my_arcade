/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLButton
*/

#ifndef OPENGLBUTTON_HPP_
#define OPENGLBUTTON_HPP_

#include "GUI/AButton.hpp"
#include "OpenGLText.hpp"
#include "Bitmapfont.hpp"

class Button : public EGE::AButton {
    public:
        Button(const std::string& text, const EGE::Vector<int>& pos);
        ~Button();

        void draw(std::shared_ptr<EGE::IWindow> window) override;

        void setText(const std::string& text) override;

        void normal() override;
        void hover() override;
        void click() override;

    protected:
    private:
};

#endif /* !OPENGLBUTTON_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLText
*/

#ifndef OPENGLTEXT_HPP_
#define OPENGLTEXT_HPP_

#include "GUI/AText.hpp"
#include "Bitmapfont.hpp"

class Text : public EGE::AText {
    public:
        Text(const std::string& text, const EGE::Vector<int>& pos, const EGE::Color &color);
        ~Text();

        void draw(std::shared_ptr<EGE::IWindow> window) override;
        void setText(const std::string& text) override;
        void setPosition(const EGE::Vector<int>& position) override;
        void setColor(const EGE::Color& color) override;

    protected:
        std::shared_ptr<Bitmapfont> _font;
    private:
};

#endif /* !OPENGLTEXT_HPP_ */


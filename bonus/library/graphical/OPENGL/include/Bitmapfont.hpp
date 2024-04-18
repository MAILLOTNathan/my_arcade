/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Bitmapfont
*/

#ifndef BITMAPFONT_HPP_
#define BITMAPFONT_HPP_

#include "OpenGLWindow.hpp"
#include "Maths/Vector.hpp"
#include "Maths/Rect.hpp"
#include "GUI/Color.hpp"
#include "OpenGLSprite.hpp"

class Bitmapfont {
    public:
        Bitmapfont();
        ~Bitmapfont();

        void draw(std::shared_ptr<EGE::IWindow> window, char c, const EGE::Vector<int>& pos);
        void setColor(const EGE::Color& color);

        int getWidth() const;
        int getHeight() const;

    protected:
        EGE::Rect<int> getCharPos(char c);
        std::vector<EGE::Rect<int>> getStringPos(const std::string& str);
        std::vector<EGE::Rect<int>> _charPos;

        Sprite *_sprite;
        int _width;
        int _height;
    private:
};

#endif /* !BITMAPFONT_HPP_ */

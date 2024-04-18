/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLSprite
*/

#ifndef OPENGLSPRITE_HPP_
#define OPENGLSPRITE_HPP_

#include "OpenGL.hpp"
#include "ASprite.hpp"
#include "Shader.hpp"
#include "Maths/Rect.hpp"
#include "GUI/Color.hpp"

#include "Ressource.hpp"

#define SPRITE_VERTEX_SHADER "./library/graphical/OPENGL/shaders/sprite.vertexshader"
#define SPRITE_FRAGMENT_SHADER "./library/graphical/OPENGL/shaders/sprite.fragmentshader"

class Sprite : public EGE::ASprite {
    public:
        Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos);
        ~Sprite();

        void draw(std::shared_ptr<EGE::IWindow> window) override;

        void setPosition(const EGE::Vector<int>& pos) override;
        void setPosition(int x, int y) override;

        void setTexture(GLuint texture);
        GLuint getTexture() const;

        void setRect(const EGE::Rect<float>& rect);

        void bind() const;

        int getWidth() const;
        int getHeight() const;

        void setColor(const EGE::Color& color);

    protected:
        GLuint _texture;
        int _width;
        int _height;
        unsigned int _id;
        unsigned int _internalFormat;
        unsigned int _imageFormat;
        unsigned int _wrapS;
        unsigned int _wrapT;
        unsigned int _filterMin;
        unsigned int _filterMax;
        unsigned int _quadVAO;
        unsigned int _quadVBO;
        EGE::Rect<float> _rect;
        glm::vec2 _size;
        float _rotate;
        glm::vec2 _scale;
        EGE::Color _color;
    private:
};

#endif /* !OPENGLSPRITE_HPP_ */

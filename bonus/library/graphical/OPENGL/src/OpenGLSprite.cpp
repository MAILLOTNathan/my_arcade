/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLSprite
*/

#include "OpenGLSprite.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_images.h"

Sprite::Sprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos)
{
    this->_pos = EGE::Vector<int>(pos.getX() *TILE_SIZE, pos.getY() * TILE_SIZE);
    Shader::compileShader(SPRITE_VERTEX_SHADER, SPRITE_FRAGMENT_SHADER, this);
    this->_width = 0;
    this->_height = 0;
    this->_internalFormat = GL_RGB;
    this->_imageFormat = GL_RGB;
    this->_wrapS = GL_REPEAT;
    this->_wrapT = GL_REPEAT;
    this->_filterMin = GL_NEAREST;
    this->_filterMax = GL_NEAREST;
    this->_rect = EGE::Rect<float>(0.0f, 0.0f, 1.0f, 1.0f);
    this->_rotate = 0.0f;
    this->_color = EGE::Color(1.0f, 1.0f, 1.0f);

    glGenTextures(1, &this->_id);
    int nrChannels;
    unsigned char *data = stbi_load(ressource->_path.c_str(), &this->_width, &this->_height, &nrChannels, 0);
    glBindTexture(GL_TEXTURE_2D, this->_id);
    switch (nrChannels) {
    case 3:
        this->_internalFormat = GL_RGB;
        this->_imageFormat = GL_RGB;
        break;
    case 4:
        this->_internalFormat = GL_RGBA;
        this->_imageFormat = GL_RGBA;
        break;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, this->_internalFormat, this->_width, this->_height, 0, this->_imageFormat, GL_UNSIGNED_BYTE, data);
    this->_scale = glm::vec2(TILE_SIZE / static_cast<float>(this->_width), TILE_SIZE / static_cast<float>(this->_height));

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->_wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->_wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->_filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->_filterMax);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);


    glGenVertexArrays(1, &this->_quadVAO);
    glGenBuffers(1, &this->_quadVBO);

    glBindBuffer(GL_ARRAY_BUFFER, this->_quadVBO);

    glBindVertexArray(this->_quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    stbi_image_free(data);
}

Sprite::~Sprite()
{
    glDeleteVertexArrays(1, &this->_quadVAO);
    glDeleteBuffers(1, &this->_quadVBO);
    glDeleteTextures(1, &this->_id);
}

void Sprite::draw(std::shared_ptr<EGE::IWindow> window)
{
    glUseProgram(this->_texture);

    float vertices[] {
        0.0f, 0.0f,                     this->_rect.getX(), this->_rect.getY(), // top-left
        static_cast<float>(this->_width), 0.0f,                       this->_rect.getX() + this->_rect.getWidth(), this->_rect.getY(), // top-right
        0.0f, static_cast<float>(this->_height),                       this->_rect.getX(), this->_rect.getY() + this->_rect.getHeight(), // bottom-left
        static_cast<float>(this->_width), static_cast<float>(this->_height), this->_rect.getX() + this->_rect.getWidth(), this->_rect.getY() + this->_rect.getHeight(),  // bottom-right
    };
    this->bind();
    unsigned int VBO;
    glBindVertexArray(this->_quadVAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->_quadVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

    Shader::setInterger("image", 0, this->getTexture());

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(1920), static_cast<float>(1080), 0.0f, -100.0f, 100.0f);
    Shader::setMatrix4("projection", projection, this->getTexture());

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(this->getPosition().getX(), this->getPosition().getY(), 0.0f));

    // model = glm::translate(model, glm::vec3(0.5f * this->_size.x, 0.5f * this->_size.y, 0.0f));
    // model = glm::rotate(model, glm::radians(this->_rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    // model = glm::translate(model, glm::vec3(-0.5f * this->_size.x, -0.5f * this->_size.y, 0.0f));

    model = glm::scale(model, glm::vec3(this->_scale ,1.0f));

    Shader::setMatrix4("model", model, this->getTexture());
    Shader::setVector3f("spriteColor", glm::vec3(this->_color.getRed(), this->_color.getGreen(), this->_color.getBlue()), this->getTexture());
    glActiveTexture(GL_TEXTURE0);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glBindVertexArray(0);
}

void Sprite::setPosition(const EGE::Vector<int> &pos)
{
    this->_pos = EGE::Vector<int>(pos.getX() * TILE_SIZE, pos.getY() * TILE_SIZE);
}

void Sprite::setPosition(int x, int y)
{
    this->_pos = EGE::Vector<int>(x * TILE_SIZE, y * TILE_SIZE);
}

void Sprite::setTexture(GLuint texture)
{
    this->_texture = texture;
}

GLuint Sprite::getTexture() const
{
    return this->_texture;
}

void Sprite::bind() const
{
    glBindTexture(GL_TEXTURE_2D, this->_id);
}

int Sprite::getWidth() const
{
    return this->_width;
}

int Sprite::getHeight() const
{
    return this->_height;
}

void Sprite::setRect(const EGE::Rect<float> &rect)
{
    this->_rect = rect;
}

void Sprite::setColor(const EGE::Color & color)
{
    this->_color = EGE::Color(color.getRed() / 255.0f, color.getGreen() / 255.0f, color.getBlue() / 255.0f);
}

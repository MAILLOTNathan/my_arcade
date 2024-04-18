/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Shader
*/

#ifndef SHADER_HPP_
#define SHADER_HPP_

#include "Error.hpp"
#include "OpenGLSprite.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

class Sprite;

class ShaderException : public Error {
    public:
        ShaderException(const std::string &message) : Error(message) {}
        ~ShaderException() {}
};

class Shader {
    public:
        Shader() = default;
        virtual ~Shader() = default;

        static void compileShader(const std::string& vertexPath, const std::string& fragmentPath, Sprite *sprite);
        static void setInterger(const std::string &name, int value, GLuint program);
        static void setMatrix4(const std::string &name, glm::mat4 value, GLuint program);
        static void setVector3f(const std::string &name, glm::vec3 value, GLuint program);

    protected:
        static void checkCompileErrors(GLuint shader, std::string type);
    private:
};

#endif /* !SHADER_HPP_ */

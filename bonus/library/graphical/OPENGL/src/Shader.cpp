/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Shader
*/

#include "Shader.hpp"
#include "OpenGLSprite.hpp"

void Shader::compileShader(const std::string& vertexPath, const std::string& fragmentPath, Sprite *sprite)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;

    try
    {
        std::ifstream vertexShaderFile(vertexPath);
        std::stringstream vShaderStream;
        vShaderStream << vertexShaderFile.rdbuf();
        vertexCode = vShaderStream.str();
        vertexShaderFile.close();

        std::ifstream fragmentShaderFile(fragmentPath);
        std::stringstream fShaderStream;
        fShaderStream << fragmentShaderFile.rdbuf();
        fragmentCode = fShaderStream.str();
        fragmentShaderFile.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << "ERROR: Cannot load the shaders." << std::endl;
    }
    std::uint32_t sGeometry;

    std::uint32_t sVertex = glCreateShader(GL_VERTEX_SHADER);
    const char *vertexStr = vertexCode.c_str();
    glShaderSource(sVertex, 1, &vertexStr, NULL);
    glCompileShader(sVertex);
    Shader::checkCompileErrors(sVertex, "VERTEX");

    std::uint32_t sFragment = glCreateShader(GL_FRAGMENT_SHADER);
    const char *fragmentStr = fragmentCode.c_str();
    glShaderSource(sFragment, 1, &fragmentStr, NULL);
    glCompileShader(sFragment);
    Shader::checkCompileErrors(sFragment, "FRAGMENT");

    if (!geometryCode.empty()) {
        sGeometry = glCreateShader(GL_GEOMETRY_SHADER);
        const char *geometryStr = geometryCode.c_str();
        glShaderSource(sGeometry, 1, &geometryStr, NULL);
        glCompileShader(sGeometry);
        Shader::checkCompileErrors(sGeometry, "GEOMETRY");
    }

    sprite->setTexture(glCreateProgram());
    glAttachShader(sprite->getTexture(), sVertex);
    glAttachShader(sprite->getTexture(), sFragment);
    if (!geometryCode.empty()) {
        glAttachShader(sprite->getTexture(), sGeometry);
    }

    glLinkProgram(sprite->getTexture());
    Shader::checkCompileErrors(sprite->getTexture(), "PROGRAM");

    glDeleteShader(sVertex);
    glDeleteShader(sFragment);
    if (!geometryCode.empty()) {
        glDeleteShader(sGeometry);
    }
}

void Shader::setInterger(const std::string &name, int value, GLuint program)
{
    glUniform1i(glGetUniformLocation(program, name.c_str()), value);
}

void Shader::setMatrix4(const std::string &name, glm::mat4 value, GLuint program)
{
    glUniformMatrix4fv(glGetUniformLocation(program, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setVector3f(const std::string &name, glm::vec3 value, GLuint program)
{
    glUniform3f(glGetUniformLocation(program, name.c_str()), value.x, value.y, value.z);
}

void Shader::checkCompileErrors(GLuint object, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(object, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(object, 1024, NULL, infoLog);
            throw ShaderException("ERROR::SHADER: Compile-time error: Type: " + type + "\n" + infoLog + "\n -- --------------------------------------------------- -- ");
        }
    }
    else
    {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, NULL, infoLog);
            throw ShaderException("ERROR::Shader: Link-time error: Type: " + type + "\n" + infoLog + "\n -- --------------------------------------------------- -- ");
        }
    }
}

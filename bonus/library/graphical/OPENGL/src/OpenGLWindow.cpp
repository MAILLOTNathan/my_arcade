/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLWindow
*/

#include "OpenGLWindow.hpp"

void error_callback(int error, const char* description)
{
    std::cerr << "Error: " << description << std::endl;
}

Window::Window(const std::string &title, unsigned int x, unsigned int y)
{
    if (!glfwInit())
        return;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_SAMPLES, 4);

    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
    glfwSetErrorCallback(error_callback);

    window = glfwCreateWindow(x, y, title.c_str(), NULL, NULL);

    glfwMakeContextCurrent(this->window);

    glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSwapInterval(1);

    this->_event = std::make_unique<Event>();
}

Window::~Window()
{
}

bool Window::isOpen() const
{
    return !glfwWindowShouldClose(this->window);
}

void Window::clear()
{
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::display()
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

void Window::close()
{
    glfwSetWindowShouldClose(this->window, GL_TRUE);
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

void Window::pollEvent()
{
    this->getEvent()->manageEvent(this);
    glfwPollEvents();
}

GLFWwindow *Window::getWindow() const
{
    return this->window;
}


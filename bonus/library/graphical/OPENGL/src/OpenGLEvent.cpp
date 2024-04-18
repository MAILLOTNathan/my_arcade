/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** OpenGLEvent
*/

#include "OpenGLEvent.hpp"

Event::Event()
{
    this->_mouseEnabled = true;
    this->_keyboardEnabled = true;
    this->_initKeyboardTranslate();
}

Event::~Event()
{
}

void Event::bindMouseScroll(std::unique_ptr<EGE::IWindow> window, std::function<void(std::double_t, std::double_t)> func)
{
    (void)window;
    (void)func;
}

void Event::unbindMouseScroll(void)
{
}

void Event::manageMouseEvent(EGE::IWindow *window)
{
}

void Event::manageKeyboardEvent(EGE::IWindow *window)
{
    GLFWwindow * glfwWindow = dynamic_cast<Window *>(window)->getWindow();
    std::int32_t keyValue = -1;
    std::uint8_t keyButtonType = 0;
    bool keyPressed = false;
    for (auto it = this->_keyMap.begin(); it != this->_keyMap.end(); it++) {
        keyValue = glfwGetKey(glfwWindow, this->keyboardTranslate(it->first->getTrigger()));
        keyButtonType = it->first->getType();
        keyPressed = it->first->isPressed();
        if (keyValue == GLFW_PRESS && (!keyPressed || keyButtonType == EGE::Event::PRESSED)) {
            it->first->setPressed(true);
            if (keyButtonType <= EGE::Event::JUST_PRESSED)
                it->second();
            continue;
        }
        if (keyValue == GLFW_RELEASE && (keyPressed || keyButtonType == EGE::Event::RELEASED)) {
            it->first->setPressed(false);
            if (keyButtonType >= EGE::Event::RELEASED)
                it->second();
        }
    }
}

void Event::manageEvent(EGE::IWindow *window)
{
    if (this->_mouseEnabled)
        this->manageMouseEvent(window);
    if (this->_keyboardEnabled)
        this->manageKeyboardEvent(window);

}

void Event::_initKeyboardTranslate()
{
    this->_keyboardTranslate[EGE::Event::Keyboard::Unknown] = GLFW_KEY_UNKNOWN;

    this->_keyboardTranslate[EGE::Event::Keyboard::A] = GLFW_KEY_A;
    this->_keyboardTranslate[EGE::Event::Keyboard::B] = GLFW_KEY_B;
    this->_keyboardTranslate[EGE::Event::Keyboard::C] = GLFW_KEY_C;
    this->_keyboardTranslate[EGE::Event::Keyboard::D] = GLFW_KEY_D;
    this->_keyboardTranslate[EGE::Event::Keyboard::E] = GLFW_KEY_E;
    this->_keyboardTranslate[EGE::Event::Keyboard::F] = GLFW_KEY_F;
    this->_keyboardTranslate[EGE::Event::Keyboard::G] = GLFW_KEY_G;
    this->_keyboardTranslate[EGE::Event::Keyboard::H] = GLFW_KEY_H;
    this->_keyboardTranslate[EGE::Event::Keyboard::I] = GLFW_KEY_I;
    this->_keyboardTranslate[EGE::Event::Keyboard::J] = GLFW_KEY_J;
    this->_keyboardTranslate[EGE::Event::Keyboard::K] = GLFW_KEY_K;
    this->_keyboardTranslate[EGE::Event::Keyboard::L] = GLFW_KEY_L;
    this->_keyboardTranslate[EGE::Event::Keyboard::M] = GLFW_KEY_M;
    this->_keyboardTranslate[EGE::Event::Keyboard::N] = GLFW_KEY_N;
    this->_keyboardTranslate[EGE::Event::Keyboard::O] = GLFW_KEY_O;
    this->_keyboardTranslate[EGE::Event::Keyboard::P] = GLFW_KEY_P;
    this->_keyboardTranslate[EGE::Event::Keyboard::Q] = GLFW_KEY_Q;
    this->_keyboardTranslate[EGE::Event::Keyboard::R] = GLFW_KEY_R;
    this->_keyboardTranslate[EGE::Event::Keyboard::S] = GLFW_KEY_S;
    this->_keyboardTranslate[EGE::Event::Keyboard::T] = GLFW_KEY_T;
    this->_keyboardTranslate[EGE::Event::Keyboard::U] = GLFW_KEY_U;
    this->_keyboardTranslate[EGE::Event::Keyboard::V] = GLFW_KEY_V;
    this->_keyboardTranslate[EGE::Event::Keyboard::W] = GLFW_KEY_W;
    this->_keyboardTranslate[EGE::Event::Keyboard::X] = GLFW_KEY_X;
    this->_keyboardTranslate[EGE::Event::Keyboard::Y] = GLFW_KEY_Y;
    this->_keyboardTranslate[EGE::Event::Keyboard::Z] = GLFW_KEY_Z;

    this->_keyboardTranslate[EGE::Event::Keyboard::Num0] = GLFW_KEY_0;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num1] = GLFW_KEY_1;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num2] = GLFW_KEY_2;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num3] = GLFW_KEY_3;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num4] = GLFW_KEY_4;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num5] = GLFW_KEY_5;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num6] = GLFW_KEY_6;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num7] = GLFW_KEY_7;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num8] = GLFW_KEY_8;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num9] = GLFW_KEY_9;

    this->_keyboardTranslate[EGE::Event::Keyboard::Escape] = GLFW_KEY_ESCAPE;
    this->_keyboardTranslate[EGE::Event::Keyboard::LControl] = GLFW_KEY_LEFT_CONTROL;
    this->_keyboardTranslate[EGE::Event::Keyboard::LShift] = GLFW_KEY_LEFT_SHIFT;
    this->_keyboardTranslate[EGE::Event::Keyboard::LAlt] = GLFW_KEY_LEFT_ALT;
    this->_keyboardTranslate[EGE::Event::Keyboard::LSystem] = GLFW_KEY_LEFT_SUPER;
    this->_keyboardTranslate[EGE::Event::Keyboard::RControl] = GLFW_KEY_RIGHT_CONTROL;
    this->_keyboardTranslate[EGE::Event::Keyboard::RShift] = GLFW_KEY_RIGHT_SHIFT;
    this->_keyboardTranslate[EGE::Event::Keyboard::RAlt] = GLFW_KEY_RIGHT_ALT;
    this->_keyboardTranslate[EGE::Event::Keyboard::RSystem] = GLFW_KEY_RIGHT_SUPER;
    this->_keyboardTranslate[EGE::Event::Keyboard::Menu] = GLFW_KEY_MENU;

    this->_keyboardTranslate[EGE::Event::Keyboard::LBracket] = GLFW_KEY_LEFT_BRACKET;
    this->_keyboardTranslate[EGE::Event::Keyboard::RBracket] = GLFW_KEY_RIGHT_BRACKET;
    this->_keyboardTranslate[EGE::Event::Keyboard::Semicolon] = GLFW_KEY_SEMICOLON;
    this->_keyboardTranslate[EGE::Event::Keyboard::Comma] = GLFW_KEY_COMMA;
    this->_keyboardTranslate[EGE::Event::Keyboard::Period] = GLFW_KEY_PERIOD;
    this->_keyboardTranslate[EGE::Event::Keyboard::Quote] = GLFW_KEY_APOSTROPHE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Slash] = GLFW_KEY_SLASH;
    this->_keyboardTranslate[EGE::Event::Keyboard::Backslash] = GLFW_KEY_BACKSLASH;
    this->_keyboardTranslate[EGE::Event::Keyboard::Tilde] = GLFW_KEY_GRAVE_ACCENT;
    this->_keyboardTranslate[EGE::Event::Keyboard::Equal] = GLFW_KEY_EQUAL;
    this->_keyboardTranslate[EGE::Event::Keyboard::Hyphen] = GLFW_KEY_MINUS;
    this->_keyboardTranslate[EGE::Event::Keyboard::Space] = GLFW_KEY_SPACE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Enter] = GLFW_KEY_ENTER;
    this->_keyboardTranslate[EGE::Event::Keyboard::Backspace] = GLFW_KEY_BACKSPACE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Tab] = GLFW_KEY_TAB;
    this->_keyboardTranslate[EGE::Event::Keyboard::PageUp] = GLFW_KEY_PAGE_UP;
    this->_keyboardTranslate[EGE::Event::Keyboard::PageDown] = GLFW_KEY_PAGE_DOWN;
    this->_keyboardTranslate[EGE::Event::Keyboard::End] = GLFW_KEY_END;
    this->_keyboardTranslate[EGE::Event::Keyboard::Home] = GLFW_KEY_HOME;

    this->_keyboardTranslate[EGE::Event::Keyboard::Insert] = GLFW_KEY_INSERT;
    this->_keyboardTranslate[EGE::Event::Keyboard::Delete] = GLFW_KEY_DELETE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Add] = GLFW_KEY_KP_ADD;
    this->_keyboardTranslate[EGE::Event::Keyboard::Subtract] = GLFW_KEY_KP_SUBTRACT;
    this->_keyboardTranslate[EGE::Event::Keyboard::Multiply] = GLFW_KEY_KP_MULTIPLY;
    this->_keyboardTranslate[EGE::Event::Keyboard::Divide] = GLFW_KEY_KP_DIVIDE;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyLeft] = GLFW_KEY_LEFT;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyRight] = GLFW_KEY_RIGHT;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyUp] = GLFW_KEY_UP;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyDown] = GLFW_KEY_DOWN;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad0] = GLFW_KEY_KP_0;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad1] = GLFW_KEY_KP_1;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad2] = GLFW_KEY_KP_2;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad3] = GLFW_KEY_KP_3;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad4] = GLFW_KEY_KP_4;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad5] = GLFW_KEY_KP_5;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad6] = GLFW_KEY_KP_6;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad7] = GLFW_KEY_KP_7;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad8] = GLFW_KEY_KP_8;
    this->_keyboardTranslate[EGE::Event::Keyboard::Numpad9] = GLFW_KEY_KP_9;

    this->_keyboardTranslate[EGE::Event::Keyboard::F1] = GLFW_KEY_F1;
    this->_keyboardTranslate[EGE::Event::Keyboard::F2] = GLFW_KEY_F2;
    this->_keyboardTranslate[EGE::Event::Keyboard::F3] = GLFW_KEY_F3;
    this->_keyboardTranslate[EGE::Event::Keyboard::F4] = GLFW_KEY_F4;
    this->_keyboardTranslate[EGE::Event::Keyboard::F5] = GLFW_KEY_F5;
    this->_keyboardTranslate[EGE::Event::Keyboard::F6] = GLFW_KEY_F6;
    this->_keyboardTranslate[EGE::Event::Keyboard::F7] = GLFW_KEY_F7;
    this->_keyboardTranslate[EGE::Event::Keyboard::F8] = GLFW_KEY_F8;
    this->_keyboardTranslate[EGE::Event::Keyboard::F9] = GLFW_KEY_F9;
    this->_keyboardTranslate[EGE::Event::Keyboard::F10] = GLFW_KEY_F10;
    this->_keyboardTranslate[EGE::Event::Keyboard::F11] = GLFW_KEY_F11;
    this->_keyboardTranslate[EGE::Event::Keyboard::F12] = GLFW_KEY_F12;
    this->_keyboardTranslate[EGE::Event::Keyboard::F13] = GLFW_KEY_F13;
    this->_keyboardTranslate[EGE::Event::Keyboard::F14] = GLFW_KEY_F14;
    this->_keyboardTranslate[EGE::Event::Keyboard::F15] = GLFW_KEY_F15;
    this->_keyboardTranslate[EGE::Event::Keyboard::Pause] = GLFW_KEY_PAUSE;

    this->_keyboardTranslate[EGE::Event::Keyboard::KeyCount] = GLFW_KEY_LAST;
}


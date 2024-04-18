/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Event
*/

#include "SDLEvent.hpp"

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
    if (this->event.key.state == SDL_PRESSED) {
        for (auto it = this->_keyMap.begin(); it != this->_keyMap.end(); it++) {
            if (this->keyboardTranslate(it->first->getTrigger()) == this->event.key.keysym.scancode && (!it->first->isPressed() || it->first->getType() == EGE::Event::PRESSED)) {
                it->first->setPressed(true);
                if (it->first->getType() <= EGE::Event::JUST_PRESSED)
                    it->second();
                continue;
            }

        }
    }
    if (this->event.key.state == SDL_RELEASED) {
        for (auto it = this->_keyMap.begin(); it != this->_keyMap.end(); it++) {
            if (this->keyboardTranslate(it->first->getTrigger()) == this->event.key.keysym.scancode && (it->first->isPressed() || it->first->getType() == EGE::Event::RELEASED)) {
                it->first->setPressed(false);
                if (it->first->getType() >= EGE::Event::RELEASED)
                    it->second();
                continue;
            }
        }
    }
}

void Event::manageEvent(EGE::IWindow *window)
{
    (void)window;
    while (SDL_PollEvent(&this->event)) {
        if (this->event.type == SDL_QUIT)
            window->close();
        if (this->_mouseEnabled)
            this->manageMouseEvent(window);
        if (this->_keyboardEnabled)
            this->manageKeyboardEvent(window);
    }
}

void Event::_initKeyboardTranslate(void)
{
    this->_keyboardTranslate[EGE::Event::Keyboard::A] = SDL_SCANCODE_A;
    this->_keyboardTranslate[EGE::Event::Keyboard::B] = SDL_SCANCODE_B;
    this->_keyboardTranslate[EGE::Event::Keyboard::C] = SDL_SCANCODE_C;
    this->_keyboardTranslate[EGE::Event::Keyboard::D] = SDL_SCANCODE_D;
    this->_keyboardTranslate[EGE::Event::Keyboard::E] = SDL_SCANCODE_E;
    this->_keyboardTranslate[EGE::Event::Keyboard::F] = SDL_SCANCODE_F;
    this->_keyboardTranslate[EGE::Event::Keyboard::G] = SDL_SCANCODE_G;
    this->_keyboardTranslate[EGE::Event::Keyboard::H] = SDL_SCANCODE_H;
    this->_keyboardTranslate[EGE::Event::Keyboard::I] = SDL_SCANCODE_I;
    this->_keyboardTranslate[EGE::Event::Keyboard::J] = SDL_SCANCODE_J;
    this->_keyboardTranslate[EGE::Event::Keyboard::K] = SDL_SCANCODE_K;
    this->_keyboardTranslate[EGE::Event::Keyboard::L] = SDL_SCANCODE_L;
    this->_keyboardTranslate[EGE::Event::Keyboard::M] = SDL_SCANCODE_M;
    this->_keyboardTranslate[EGE::Event::Keyboard::N] = SDL_SCANCODE_N;
    this->_keyboardTranslate[EGE::Event::Keyboard::O] = SDL_SCANCODE_O;
    this->_keyboardTranslate[EGE::Event::Keyboard::P] = SDL_SCANCODE_P;
    this->_keyboardTranslate[EGE::Event::Keyboard::Q] = SDL_SCANCODE_Q;
    this->_keyboardTranslate[EGE::Event::Keyboard::R] = SDL_SCANCODE_R;
    this->_keyboardTranslate[EGE::Event::Keyboard::S] = SDL_SCANCODE_S;
    this->_keyboardTranslate[EGE::Event::Keyboard::T] = SDL_SCANCODE_T;
    this->_keyboardTranslate[EGE::Event::Keyboard::U] = SDL_SCANCODE_U;
    this->_keyboardTranslate[EGE::Event::Keyboard::V] = SDL_SCANCODE_V;
    this->_keyboardTranslate[EGE::Event::Keyboard::W] = SDL_SCANCODE_W;
    this->_keyboardTranslate[EGE::Event::Keyboard::X] = SDL_SCANCODE_X;
    this->_keyboardTranslate[EGE::Event::Keyboard::Y] = SDL_SCANCODE_Y;
    this->_keyboardTranslate[EGE::Event::Keyboard::Z] = SDL_SCANCODE_Z;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num0] = SDL_SCANCODE_0;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num1] = SDL_SCANCODE_1;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num2] = SDL_SCANCODE_2;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num3] = SDL_SCANCODE_3;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num4] = SDL_SCANCODE_4;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num5] = SDL_SCANCODE_5;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num6] = SDL_SCANCODE_6;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num7] = SDL_SCANCODE_7;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num8] = SDL_SCANCODE_8;
    this->_keyboardTranslate[EGE::Event::Keyboard::Num9] = SDL_SCANCODE_9;
    this->_keyboardTranslate[EGE::Event::Keyboard::Escape] = SDL_SCANCODE_ESCAPE;
    this->_keyboardTranslate[EGE::Event::Keyboard::LControl] = SDL_SCANCODE_LCTRL;
    this->_keyboardTranslate[EGE::Event::Keyboard::LShift] = SDL_SCANCODE_LSHIFT;
    this->_keyboardTranslate[EGE::Event::Keyboard::LAlt] = SDL_SCANCODE_LALT;
    this->_keyboardTranslate[EGE::Event::Keyboard::LSystem] = SDL_SCANCODE_LGUI;
    this->_keyboardTranslate[EGE::Event::Keyboard::RControl] = SDL_SCANCODE_RCTRL;
    this->_keyboardTranslate[EGE::Event::Keyboard::RShift] = SDL_SCANCODE_RSHIFT;
    this->_keyboardTranslate[EGE::Event::Keyboard::RAlt] = SDL_SCANCODE_RALT;
    this->_keyboardTranslate[EGE::Event::Keyboard::RSystem] = SDL_SCANCODE_RGUI;
    this->_keyboardTranslate[EGE::Event::Keyboard::Menu] = SDL_SCANCODE_MENU;
    this->_keyboardTranslate[EGE::Event::Keyboard::LBracket] = SDL_SCANCODE_LEFTBRACKET;
    this->_keyboardTranslate[EGE::Event::Keyboard::RBracket] = SDL_SCANCODE_RIGHTBRACKET;
    this->_keyboardTranslate[EGE::Event::Keyboard::SemiColon] = SDL_SCANCODE_SEMICOLON;
    this->_keyboardTranslate[EGE::Event::Keyboard::Comma] = SDL_SCANCODE_COMMA;
    this->_keyboardTranslate[EGE::Event::Keyboard::Period] = SDL_SCANCODE_PERIOD;
    this->_keyboardTranslate[EGE::Event::Keyboard::Quote] = SDL_SCANCODE_APOSTROPHE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Slash] = SDL_SCANCODE_SLASH;
    this->_keyboardTranslate[EGE::Event::Keyboard::BackSlash] = SDL_SCANCODE_BACKSLASH;
    this->_keyboardTranslate[EGE::Event::Keyboard::Tilde] = SDL_SCANCODE_GRAVE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Equal] = SDL_SCANCODE_EQUALS;
    this->_keyboardTranslate[EGE::Event::Keyboard::Dash] = SDL_SCANCODE_MINUS;
    this->_keyboardTranslate[EGE::Event::Keyboard::Space] = SDL_SCANCODE_SPACE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Return] = SDL_SCANCODE_RETURN;
    this->_keyboardTranslate[EGE::Event::Keyboard::BackSpace] = SDL_SCANCODE_BACKSPACE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Tab] = SDL_SCANCODE_TAB;
    this->_keyboardTranslate[EGE::Event::Keyboard::PageUp] = SDL_SCANCODE_PAGEUP;
    this->_keyboardTranslate[EGE::Event::Keyboard::PageDown] = SDL_SCANCODE_PAGEDOWN;
    this->_keyboardTranslate[EGE::Event::Keyboard::End] = SDL_SCANCODE_END;
    this->_keyboardTranslate[EGE::Event::Keyboard::Home] = SDL_SCANCODE_HOME;
    this->_keyboardTranslate[EGE::Event::Keyboard::Insert] = SDL_SCANCODE_INSERT;
    this->_keyboardTranslate[EGE::Event::Keyboard::Delete] = SDL_SCANCODE_DELETE;
    this->_keyboardTranslate[EGE::Event::Keyboard::Add] = SDL_SCANCODE_KP_PLUS;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyUp] = SDL_SCANCODE_UP;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyDown] = SDL_SCANCODE_DOWN;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyRight] = SDL_SCANCODE_RIGHT;
    this->_keyboardTranslate[EGE::Event::Keyboard::KeyLeft] = SDL_SCANCODE_LEFT;
}

/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Workspace)
** File description:
** Trigger
*/

#ifndef TRIGGER_HPP_
#define TRIGGER_HPP_

#include <cmath>
#include <cstdint>

namespace EGE {
    namespace Event {

        /*
        // \brief  Enumeration of the different keys supported by Etib Game Engine
        */
        enum Keyboard {
            Unknown = -1, ///< Unhandled key
            A = 0,        ///< The A key
            B,            ///< The B key
            C,            ///< The C key
            D,            ///< The D key
            E,            ///< The E key
            F,            ///< The F key
            G,            ///< The G key
            H,            ///< The H key
            I,            ///< The I key
            J,            ///< The J key
            K,            ///< The K key
            L,            ///< The L key
            M,            ///< The M key
            N,            ///< The N key
            O,            ///< The O key
            P,            ///< The P key
            Q,            ///< The Q key
            R,            ///< The R key
            S,            ///< The S key
            T,            ///< The T key
            U,            ///< The U key
            V,            ///< The V key
            W,            ///< The W key
            X,            ///< The X key
            Y,            ///< The Y key
            Z,            ///< The Z key
            Num0,         ///< The 0 key
            Num1,         ///< The 1 key
            Num2,         ///< The 2 key
            Num3,         ///< The 3 key
            Num4,         ///< The 4 key
            Num5,         ///< The 5 key
            Num6,         ///< The 6 key
            Num7,         ///< The 7 key
            Num8,         ///< The 8 key
            Num9,         ///< The 9 key
            Escape,       ///< The Escape key
            LControl,     ///< The left Control key
            LShift,       ///< The left Shift key
            LAlt,         ///< The left Alt key
            LSystem,      ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
            RControl,     ///< The right Control key
            RShift,       ///< The right Shift key
            RAlt,         ///< The right Alt key
            RSystem,      ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
            Menu,         ///< The Menu key
            LBracket,     ///< The [ key
            RBracket,     ///< The ] key
            Semicolon,    ///< The ; key
            Comma,        ///< The , key
            Period,       ///< The . key
            Quote,        ///< The ' key
            Slash,        ///< The / key
            Backslash,    ///< The \ key
            Tilde,        ///< The ~ key
            Equal,        ///< The = key
            Hyphen,       ///< The - key (hyphen)
            Space,        ///< The Space key
            Enter,        ///< The Enter/Return keys
            Backspace,    ///< The Backspace key
            Tab,          ///< The Tabulation key
            PageUp,       ///< The Page up key
            PageDown,     ///< The Page down key
            End,          ///< The End key
            Home,         ///< The Home key
            Insert,       ///< The Insert key
            Delete,       ///< The Delete key
            Add,          ///< The + key
            Subtract,     ///< The - key (minus, usually from numpad)
            Multiply,     ///< The * key
            Divide,       ///< The / key
            KeyLeft,      ///< Left arrow
            KeyRight,     ///< Right arrow
            KeyUp,        ///< Up arrow
            KeyDown,      ///< Down arrow
            Numpad0,      ///< The numpad 0 key
            Numpad1,      ///< The numpad 1 key
            Numpad2,      ///< The numpad 2 key
            Numpad3,      ///< The numpad 3 key
            Numpad4,      ///< The numpad 4 key
            Numpad5,      ///< The numpad 5 key
            Numpad6,      ///< The numpad 6 key
            Numpad7,      ///< The numpad 7 key
            Numpad8,      ///< The numpad 8 key
            Numpad9,      ///< The numpad 9 key
            F1,           ///< The F1 key
            F2,           ///< The F2 key
            F3,           ///< The F3 key
            F4,           ///< The F4 key
            F5,           ///< The F5 key
            F6,           ///< The F6 key
            F7,           ///< The F7 key
            F8,           ///< The F8 key
            F9,           ///< The F9 key
            F10,          ///< The F10 key
            F11,          ///< The F11 key
            F12,          ///< The F12 key
            F13,          ///< The F13 key
            F14,          ///< The F14 key
            F15,          ///< The F15 key
            Pause,        ///< The Pause key

            KeyCount, ///< Keep last -- the total number of keyboard keys

            // Deprecated values:

            Dash = Hyphen,         ///< \deprecated Use Hyphen instead
            BackSpace = Backspace, ///< \deprecated Use Backspace instead
            BackSlash = Backslash, ///< \deprecated Use Backslash instead
            SemiColon = Semicolon, ///< \deprecated Use Semicolon instead
            Return = Enter         ///< \deprecated Use Enter instead
        };

        /*
        // \brief  Enumeration of the different mouse triggers supported by Etib Game Engine
        */
        enum Mouse {
            Left,     ///< The left mouse trigger
            Right,    ///< The right mouse trigger
            Middle,   ///< The middle (wheel) mouse trigger
            XButton1, ///< The first extra mouse trigger
            XButton2, ///< The second extra mouse trigger

            TriggerCount ///< Keep last -- the total number of mouse triggers
        };

        enum JoystickAxis {
            LX, ///< The X axis of the left joystick
            LY, ///< The Y axis of the left joystick
            RX, ///< The X axis of the right joystick
            RY, ///< The Y axis of the right joystick
            LT, ///< The left index trigger
            RT, ///< The right index trigger
        };

        enum JoystickTrigger {
            JoystickA, ///< The A button
            JoystickB, ///< The B button
            JoystickX, ///< The X button
            JoystickY, ///< The Y button
            LB,        ///< The left bumper
            RB,        ///< The right bumper
            SELECT,    ///< The select button
            START,     ///< The start button
            L3,        ///< The left stick button
            R3,        ///< The right stick button
            UP,        ///< The up button
            DOWN,      ///< The down button
            LEFT,      ///< The left button
            RIGHT,     ///< The right button
        };

        enum TriggerType {
            MOVED = 0,         // * for joystick axis
            PRESSED = 1,       ///< Triggered while the button is pressed
            JUST_PRESSED = 2,  ///< Triggered once when the button is pressed
            RELEASED = 4,      ///< Triggered while the button is released
            JUST_RELEASED = 8, ///< Triggered once when the button is released
        };

        template <typename T>
        class Trigger {
            public:
                Trigger(T trigger, std::uint8_t type, std::int8_t joystickId = -1)
                {
                    this->_trigger = trigger;
                    this->_joystickId = joystickId;
                    this->_type = type;
                    this->_pressed = false;
                }
                virtual ~Trigger() = default;

                void setTrigger(T trigger)
                {
                    this->_trigger = trigger;
                }
                void setJoystickId(std::uint8_t joystickId)
                {
                    this->_joystickId = joystickId;
                }
                void setPressed(bool pressed)
                {
                    this->_pressed = pressed;
                }
                bool isPressed(void)
                {
                    return this->_pressed;
                }
                void setType(std::uint8_t type)
                {
                    this->_type = type;
                }
                T getTrigger(void)
                {
                    return this->_trigger;
                }
                std::int8_t getJoystickId(void)
                {
                    return this->_joystickId;
                }
                std::uint8_t getType(void)
                {
                    return this->_type;
                }

                T _trigger;
                std::int8_t _joystickId;
                std::uint8_t _type;
                bool _pressed;
        };
    };
};

#endif /* !TRIGGER_HPP_ */
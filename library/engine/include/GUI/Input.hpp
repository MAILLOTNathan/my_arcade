/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "GUI/AGUI.hpp"
#include "GUI/AText.hpp"
#include "ADisplayModule.hpp"

namespace EGE {
    /// @brief Input TextField class.
    class Input : public AGUI {
        public:
            /// @brief Input constructor.
            /// @param graphic Graphic module used to display.
            /// @param pos Position of the input.
            Input(EGE::IDisplayModule *graphic, const EGE::Vector<int>& pos);
            ~Input();

            /// @brief Add a `character` to the content of the field.
            /// @param c character to be added.
            void addChar(char c);

            /// @brief Remove the last `character` from the content of the field.
            void removeChar();

            /// @brief Draws the field with the given `window`.
            /// @param window Window where the input will be drawn.
            void draw(std::shared_ptr<EGE::IWindow> window);

            /// @brief Get the content of the field.
            std::string getText() const;

            /// @brief Clear the content of the field.
            void removeText();

            /// @brief Reload the field.
            /// @param graphic Graphic module used to display.
            /// @param pos Position of the input.
            void reload(EGE::IDisplayModule *graphic, const EGE::Vector<int>& pos);

        protected:
            EGE::IText *_text;  // Text object contained in the field.
            std::string _input; // Content of the field.
    };
}

#endif /* !INPUT_HPP_ */

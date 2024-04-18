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
    class Input : public AGUI {
        public:
            Input(EGE::IDisplayModule *graphic, const EGE::Vector<int>& pos);
            ~Input();

            void addChar(char c);
            void removeChar();
            void draw(std::shared_ptr<EGE::IWindow> window);
            std::string getText() const;

            void removeText();
            void reload(EGE::IDisplayModule *graphic, const EGE::Vector<int>& pos);

        protected:
            EGE::IText *_text;
            std::string _input;
    };
}

#endif /* !INPUT_HPP_ */

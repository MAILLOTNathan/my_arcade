/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** SFMLButton
*/

#ifndef SFMLBUTTON_HPP_
#define SFMLBUTTON_HPP_

#include "GUI/AButton.hpp"
#include "SFMLWindow.hpp"
#include "SFMLText.hpp"

class Button : public EGE::AButton {
    public:
        Button(const std::string &text, const EGE::Vector<int> &pos);
        ~Button();

        void draw(std::shared_ptr<EGE::IWindow> window) override;

        void normal() override;
        void hover() override;
        void click() override;
};

#endif /* !SFMLBUTTON_HPP_ */

/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** RadioButton
*/

#ifndef RADIOBUTTON_HPP_
#define RADIOBUTTON_HPP_

#include "GUI/IGUI.hpp"
#include "GUI/AButton.hpp"

namespace EGE {
    class RadioButton : public ADrawable {
        public:
            RadioButton();
            ~RadioButton();

            void draw(std::shared_ptr<EGE::IWindow> window);

            std::vector<IButton *> getElements() const;

            void addElement(IButton *element);
            void removeElement(IButton *element);
            void clearElements();
            void selectNextElement();
            void selectPrevElement();
            int getSelectedElement() const;

        protected:
            std::vector<IButton *> _elements;
            int _selectedElement;
        private:
    };
}

#endif /* !RADIOBUTTON_HPP_ */

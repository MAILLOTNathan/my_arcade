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
    /// @brief A simple radio button.
    class RadioButton : public ADrawable {
        public:
            RadioButton();
            ~RadioButton();

            /// @brief Draws the radio button.
            /// @param window The window to draw on.
            void draw(std::shared_ptr<EGE::IWindow> window);

            /// @brief Returns all the buttons in this radio button.
            std::vector<IButton *> getElements() const;

            /// @brief Add a button to this radio button.
            /// @param element A button which has to be added in the `_elements`.
            void addElement(IButton *element);

            /// @brief Remove a button from this radio button.
            /// @param element Button which has to be removed in the `_elements`.
            void removeElement(IButton *element);

            /// @brief Clears all the buttons in the `_elements`.
            void clearElements();

            /// @brief Change the `_selectedElement` value by the element after in the `_elements`.
            void selectNextElement();

            /// @brief Change the `_selectedElement` value by the element before in the `_elements`.
            void selectPrevElement();

            /// @brief Returns the `_selectedElement` value.
            int getSelectedElement() const;

        protected:
            std::vector<IButton *> _elements;   // List of Button for the radio button.
            int _selectedElement;               // Index to the selected element.
        private:
    };
}

#endif /* !RADIOBUTTON_HPP_ */

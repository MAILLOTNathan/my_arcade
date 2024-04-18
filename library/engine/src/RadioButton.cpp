/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** RationButton
*/

#include "GUI/RadioButton.hpp"

EGE::RadioButton::RadioButton()
{
    this->_selectedElement = 0;
}

EGE::RadioButton::~RadioButton()
{
    this->_elements.clear();
}

void EGE::RadioButton::draw(std::shared_ptr<EGE::IWindow> window)
{
    for (auto &elem : _elements) {
        elem->draw(window);
    }
}

void EGE::RadioButton::addElement(EGE::IButton *elem)
{
    this->_elements.push_back(elem);
    if (this->_elements.size() == 1)
        this->_elements[this->_selectedElement]->hover();
}

void EGE::RadioButton::removeElement(EGE::IButton *elem)
{
    this->_elements.erase(std::remove(this->_elements.begin(), this->_elements.end(), elem), this->_elements.end());
}

void EGE::RadioButton::clearElements()
{
    this->_elements.clear();
}

void EGE::RadioButton::selectNextElement()
{
    this->_elements[this->_selectedElement]->normal();
    if (this->_selectedElement + 1 < this->_elements.size())
        this->_selectedElement++;
    else
        this->_selectedElement = 0;
    this->_elements[this->_selectedElement]->hover();
}

void EGE::RadioButton::selectPrevElement()
{
    this->_elements[this->_selectedElement]->normal();
    if (this->_selectedElement - 1 >= 0) {
        this->_selectedElement--;
    } else
        this->_selectedElement = this->_elements.size() - 1;

    this->_elements[this->_selectedElement]->hover();
}

int EGE::RadioButton::getSelectedElement() const
{
    return this->_selectedElement;
}

std::vector<EGE::IButton *> EGE::RadioButton::getElements() const
{
    return this->_elements;
}
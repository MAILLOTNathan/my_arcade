/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** DisplayModule
*/

#include "SFMLDisplayModule.hpp"

DisplayModule::DisplayModule()
{
}

DisplayModule::~DisplayModule()
{
}

void DisplayModule::init()
{
    this->_window = std::make_shared<Window>("arcade", 1920, 1080);
}

EGE::IDrawable *DisplayModule::createSprite(EGE::Ressource *ressource, const EGE::Vector<int> &pos)
{
    return new Sprite(ressource, pos);
}

EGE::IText *DisplayModule::createText(const std::string &text, const EGE::Vector<int> &pos, const EGE::Color &color)
{
    return new Text(text, pos, color);
}

EGE::IButton *DisplayModule::createButton(const std::string &text, const EGE::Vector<int> &pos)
{
    return new Button(text, pos);
}

extern "C" {
    EGE::IDisplayModule *createDisplayModule()
    {
        EGE::IDisplayModule *displayModule = new DisplayModule();
        displayModule->init();
        return displayModule;
    }

    void destroyDisplayModule(EGE::IDisplayModule *displayModule)
    {
        delete displayModule;
    }
}

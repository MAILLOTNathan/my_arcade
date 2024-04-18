/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AGameModule
*/

#include "AGameModule.hpp"

void EGE::AGameModule::getNextFrame()
{
    this->_scoreText->setText("Score: " + std::to_string(this->_score));
    this->_scoreText->draw(this->_display->getWindow());
    for (auto &entity : this->_entities) {
        entity->update(this->_entities, this);
        entity->draw(this->_display);
    }
}

void EGE::AGameModule::reload(EGE::IDisplayModule *displayModule)
{
    this->_display = displayModule;
    this->_msgEnd = this->_display->createText("", EGE::Vector<int>(10, 10), EGE::Color(255, 255, 255));
    this->_scoreText = this->_display->createText("Score: ", EGE::Vector<int>(2, 0), EGE::Color(255, 255, 255));
    for (auto &entity : this->_entities) {
        if (entity != nullptr && entity != (void*)0xffffffffffffffff)
            entity->reload(this->_display, this);
    }
}


void EGE::AGameModule::parseEntities(const std::string &path)
{
    try {
        std::string fileContent = Utils::getFileContent(path);
        std::vector<std::string> objects = Utils::myStrToWordVectorSep(fileContent, '#');

        for (auto &obj : objects) {
            std::vector<std::string> lines;
            std::map<std::string, std::string> properties;

            if (obj.empty())
                continue;

            lines = Utils::myStrToWordVectorSep(obj);

            for (auto &line : lines) {
                std::vector<std::string> property = Utils::myStrToWordVectorSep(line, ':');

                properties[property[0]] = property[1];
            }
            this->_model.push_back(properties);
        }
    } catch (const std::exception &e) {
        std::string message = "AGameModule (parseEntities) \n\t";
        message += e.what();
        throw AGameModuleException(message);
    }
}

void EGE::AGameModule::parseMap(const std::string &path)
{
    try {
        std::string fileContent = Utils::getFileContent(path);
        std::vector<std::string> lines = Utils::myStrToWordVectorSep(fileContent, '\n');
        size_t y = 0;

        for (auto &line : lines) {
            size_t x = 0;
            for (auto &character : line) {
                for (auto &model : this->_model) {
                    if (model["char"][0] == character) {
                        Entity *entity = Factory::createEntity(model, this);

                        entity->init(this->_display, this);
                        entity->setPosition(EGE::Vector<int>(x, y));
                        this->_entities.push_back(entity);
                    }
                }
                x++;
            }
            y++;
        }
    } catch (const std::exception &e) {
        std::string message = "AGameModule (parseMap) \n\t";
        message += e.what();
        throw AGameModuleException(message);
    }
}

void EGE::AGameModule::init(const std::string &gameFolder)
{
    try {
        std::vector<std::string> folderContent = Utils::getContentFolder(gameFolder);
        std::string entitiesFile;
        std::string mapFile;

        for (auto &file : folderContent) {
            if (file.find("entities")!= std::string::npos) {
                entitiesFile = file;
            } else if (file.find("map")!= std::string::npos) {
                mapFile = file;
            } else if (file.find("save")!= std::string::npos) {
                this->_savegame = file;
            }
        }
        this->parseEntities(entitiesFile);
        this->parseMap(mapFile);
    } catch (const std::exception &e) {
        std::string message = "AGameModule (init) \n\t";
        message += e.what();
        throw AGameModuleException(message);
    }
}

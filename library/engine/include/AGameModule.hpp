/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** AGameModule
*/

#ifndef AGAMEMODULE_HPP_
#define AGAMEMODULE_HPP_

#include "IGameModule.hpp"
#include "Utils.hpp"
#include "Error.hpp"
#include "Factory.hpp"

#include <map>

namespace EGE {
    class AGameModuleException : public Error {
        public:
            AGameModuleException(const std::string &message) : Error(message) {}
            ~AGameModuleException() = default;
    };

    /// @brief Abstract class for Game Module.
    class AGameModule : public IGameModule {
        public:
            virtual ~AGameModule() = default;

            /// @brief Displays the next frame of the game.
            virtual void getNextFrame() override;

            /// @brief Load a `Display Module`
            /// @param displayModule `Display Module` used to display the elements of the game.
            virtual void load(EGE::IDisplayModule *displayModule) = 0;

            /// @brief Create a player entity from `properties`
            /// @param properties Description of an entity
            virtual EGE::Entity *createPlayer(std::map<std::string, std::string> &properties) = 0;

            /// @brief Create an enemy entity from `properties`
            /// @param properties Description of an entity
            virtual EGE::Entity *createEnemy(std::map<std::string, std::string> &properties) = 0;

            /// @brief Create an environement entity from `properties`
            /// @param properties Description of an entity
            virtual EGE::Entity *createEnvironment(std::map<std::string, std::string> &properties) = 0;

            /// @brief Create an object entity from `properties`
            /// @param properties Description of an entity
            virtual EGE::Entity *createObject(std::map<std::string, std::string> &properties) = 0;

            /// @brief Reload the entity from the new `Display Module` given.
            /// @param displayModule new `Display Module` used to display the elements of the game.
            void reload(EGE::IDisplayModule *displayModule) override;

            /// @brief Initialize the `Game Module` from the given `gameFolder`.
            /// @param gameFolder Path to a folder containing the configuration files of the game.
            void init(const std::string &gameFolder) override;

            /// @brief Add the given `entity` to the container of the game.
            /// @param entity Entity which have to be added to the container.
            virtual void addEntity(EGE::Entity *entity) override { this->_entities.push_back(entity); }

            /// @brief Remove the given `entity` from the container of the game.
            /// @param entity Entity which have to be removed of the container.
            virtual void removeEntity(EGE::Entity *entity) override {
                this->_entities.erase(std::remove(this->_entities.begin(), this->_entities.end(), entity), this->_entities.end());
            }

            /// @brief Change the score value.
            void setScore(int score) override { this->_score = score; }

            /// @brief Returns the score value.
            int getScore() override { return this->_score; }

            /// @brief Change the state of the game to the given value.
            /// @param state State to be set.
            void setState(STATE_GAME state) {
                this->_state = state;
            }

            /// @brief Returns the current state of the game.
            STATE_GAME getStats(void) { return this->_state; }

            /// @brief Returns the name of the player.
            std::string getNamePlayer(void) { return this->_namePlayer; }

            /// @brief Set the name of the player.
            void setNamePlayer(const std::string &name) { this->_namePlayer = name; }

        protected:
            EGE::IDisplayModule *_display;                          // `Display Module` of the current `Game Module`
            std::vector<EGE::Entity *> _entities;                   // Container of entities which represents all the entities in the game.
            std::vector<std::map<std::string, std::string>> _model; // Data model on which the entities are based on.
            std::string _savegame;                                  // Path to the savegame file.
            STATE_GAME _state;                                      // Current Game State.
            int _score;                                             // Point scored by the player.
            EGE::IText *_scoreText;                                 // Score displayed.
            EGE::IText *_msgEnd;                                    // Message displayed at the end of the game.
            std::string _namePlayer;                                // Name of the player.

        private:
            void parseEntities(const std::string &path);    // Creates the Data model by parsing the file given as parameter.
            void parseMap(const std::string &path);         // Parses the file given as parameter to create entities.
            virtual void loadSavegame() = 0;                // Loads the savegame.

    };
}

#endif /* !AGAMEMODULE_HPP_ */

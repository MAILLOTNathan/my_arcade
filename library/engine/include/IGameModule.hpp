/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include "ADisplayModule.hpp"
#include "Entity.hpp"

namespace EGE {

    /// @brief Interface for Game Module.
    class IGameModule {
        public:
            virtual ~IGameModule() = default;
      
            /// @brief All the state a game can be.
            enum STATE_GAME {
                LOSE, // When the player loose the game.
                WIN,  // When the player win the game.
                RUN   // When the player is playing.
            };

            /// @brief Displays the next frame of the game.
            virtual void getNextFrame() = 0;

            /// @brief Load a `Display Module`
            /// @param displayModule `Display Module` used to display the elements of the game.
            virtual void load(EGE::IDisplayModule *displayModule) = 0;

            /// @brief Reload the entity from the new `Display Module` given.
            /// @param displayModule new `Display Module` used to display the elements of the game.
            virtual void reload(EGE::IDisplayModule *displayModule) = 0;

            /// @brief Initialize the `Game Module` from the given `gameFolder`.
            /// @param gameFolder Path to a folder containing the configuration files of the game.
            virtual void init(const std::string &gameFolder) = 0;

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

            /// @brief Add the given `entity` to the container of the game.
            /// @param entity Entity which have to be added to the container.
            virtual void addEntity(EGE::Entity *entity) = 0;
      
            /// @brief Remove the given `entity` from the container of the game.
            /// @param entity Entity which have to be removed of the container.
            virtual void removeEntity(EGE::Entity *entity) = 0;
      
            /// @brief Change the score value.
            virtual void setScore(int score) = 0;
      
            /// @brief Returns the score value.
            virtual int getScore() = 0;
      
            /// @brief Change the state of the game to the given value.
            /// @param state State to be set.
            virtual void setState(STATE_GAME state) = 0;
      
            /// @brief Returns the current state of the game.
            virtual STATE_GAME getStats(void) = 0;

        protected:
        private:
    };
}

#endif /* !IGAMEMODULE_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Utilis
*/

#ifndef UTILIS_HPP_
#define UTILIS_HPP_

#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <exception>
#include "Error.hpp"

class UtilsException : public Error {
    public:
        UtilsException(const std::string &message) : Error(message) {}
        ~UtilsException() = default;
};

/// @brief Utility functions.
class Utils {
    public:
        /// @brief Get the content of a folder.
        /// @param path Path to the folder.
        static std::vector<std::string> getContentFolder(const std::string &path);

        /// @brief Split a string into a container of strings separated by '\n'.
        /// @param str String to be splitted.
        static std::vector<std::string> myStrToWordVectorSep(const std::string &str);

        /// @brief Split a string into a container of strings separated by the char passed as param.
        /// @param str String to be splitted.
        /// @param sep Character interpreted as a separator.
        static std::vector<std::string> myStrToWordVectorSep(const std::string &str, char sep);

        /// @brief Get the content of a file.
        /// @param filename Path to the file.
        static std::string getFileContent(const std::string &filename);
    protected:
    private:
};

#endif /* !UTILIS_HPP_ */

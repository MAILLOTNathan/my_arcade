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

class Utils {
    public:
        static std::vector<std::string> getContentFolder(const std::string &path);
        static std::vector<std::string> myStrToWordVectorSep(const std::string &str);
        static std::vector<std::string> myStrToWordVectorSep(const std::string &str, char sep);
        static std::string getFileContent(const std::string &filename);
    protected:
    private:
};

#endif /* !UTILIS_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** Utils
*/

#include "Utils.hpp"

std::vector<std::string> Utils::getContentFolder(const std::string &path)
{
    try {
        std::vector<std::string> files;
        std::string file;
        std::filesystem::directory_iterator directory(path);
        for (const auto &entry : directory) {
            file = entry.path();
            files.push_back(file);
        }
        return files;
    } catch (const std::exception &e) {
        std::string message = "Utils (getContentFolder) \n\t";
        message += e.what();
        throw UtilsException(message);
    }
}

std::vector<std::string> Utils::myStrToWordVectorSep(const std::string &str)
{
    try {
        std::string strCpy = str;
        std::vector<std::string> content;
        size_t x = 0;

        for (size_t i = 0; i < strCpy.size(); i++){
            while (std::isspace(strCpy[i]) && i < strCpy.size())
                strCpy.erase(i, 1);
            while (!std::isspace(strCpy[i]) && i < strCpy.size()) {
                i++;
                x++;
            }
            content.push_back(strCpy.substr(i - x, x));
            x = 0;
        }
        return content;
    } catch (const std::exception &e) {
        std::string message = "Utils (myStrToWordVectorSep (separator not specified)) \n\t";
        message += e.what();
        throw UtilsException(message);
    }
}


std::vector<std::string> Utils::myStrToWordVectorSep(const std::string &str, char separator)
{
    try {
        std::string instruction;
        std::vector<std::string> content;
        std::istringstream iss = std::istringstream(str);
        while (std::getline(iss, instruction, separator)) {
            content.push_back(instruction);
        }
        return content;
    } catch (const std::exception &e) {
        std::string message = "Utils (myStrToWordVectorSep (separator specified)) \n\t";
        message += e.what();
        throw UtilsException(message);
    }
}

std::string Utils::getFileContent(const std::string &filename)
{
    try {
        std::ifstream fileStream(filename);
        std::stringstream buffer;
        std::string lines;

        buffer << fileStream.rdbuf();
        lines = buffer.str();
        fileStream.close();

        return lines;
    } catch (const std::exception &e) {
        std::string message = "Utils (getFileContent) \n\t";
        message += e.what();
        throw UtilsException(message);
    }
}

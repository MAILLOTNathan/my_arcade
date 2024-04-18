/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>
#include <exception>

class Error : public std::exception {
    public:
        Error(const std::string &message) : _message(message) {};
        const char *what() const noexcept override { return _message.c_str(); }

    protected:
        std::string _message;
    private:
};

#endif /* !ERROR_HPP_ */

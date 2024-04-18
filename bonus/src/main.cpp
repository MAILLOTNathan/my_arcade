/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-arcade-nathan.maillot
** File description:
** main
*/

#include <iostream>
#include "Library.hpp"
#include "Trigger.hpp"
#include "Core.hpp"
#include "ADisplayModule.hpp"
#include "GUI/AText.hpp"
#include <memory>

int main(int ac, char **av)
{
    try {
        if (ac != 2) {
            throw Error("Usage: ./arcade ./lib.so");
        }
        Core core(av[1]);
        core.loop();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}

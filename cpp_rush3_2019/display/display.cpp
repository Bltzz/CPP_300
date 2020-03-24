/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** display
*/

#include <vector>
#include <algorithm>
#include "../Module/Module.hpp"

void display(std::vector<Module *> *modules)
{
    std::for_each(modules->begin(), modules->end(), [](Module *module) {
        module->draw();
    });
}

void display(std::vector<Module *> *modules, sf::RenderWindow *window)
{
    std::for_each(modules->begin(), modules->end(), [window](Module *module) {
        module->draw(window);
    });
}
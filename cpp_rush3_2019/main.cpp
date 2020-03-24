/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** main
*/

#include <string.h>
#include <iostream>
#include "Module/Module.hpp"
#include "Module/CPUModule.hpp"
#include "Module/MemoryModule.hpp"
#include "Module/InfoModule.hpp"
#include "Module/NetworkModule.hpp"
#include "Module/HeapModule.hpp"
#include "Module/TextualModule.hpp"
#include <vector>
#include <fstream>
#include <string>
#include "front/GWindow.hpp"
#include "display/display.hpp"
#include <ncurses.h>



void init_elements(std::vector<Module *> &modules, GWindow &win)
{
    int it = 0;
    std::for_each(modules.begin(), modules.end(), [modules, win, &it](Module *mod) {
        if (win.isGraphical()) {
            mod->setPos(0, (win.getGraphicWindow()->getSize().y / modules.size()) * it);
            mod->initGraphicElements(win.getGraphicWindow(), modules.size());
        } else {
            mod->initGraphicElements(modules.size());
        }
        it++;
    });
}

void main_loop(bool graphical, std::vector<Module *> &modules)
{
    GWindow win(graphical, "MyGKrellm", 1920, 1080);
    size_t pos12 = 0;
    size_t pos11 = 0;

    init_elements(modules, win);
    if (graphical){
        modules.push_back(new InfoModule());
        modules[modules.size() - 1]->initGraphicElements(win.getGraphicWindow(), 0);
    }
    while (win()) {
        const GEvent event = win.getLastEvent();
        win.draw(&modules);
        if (graphical) {
            if (event.value == "F12"){
                int posXTmp = modules[pos12]->getPosX();
                int posYTmp = modules[pos12]->getPosY();
                modules[pos12]->setPos(modules[pos12 + 1]->getPosX(), modules[pos12 + 1]->getPosY());
                modules[pos12]->changePos(win.getGraphicWindow(), modules.size());
                modules[pos12 + 1]->setPos(posXTmp, posYTmp);
                modules[pos12 + 1]->changePos(win.getGraphicWindow(), modules.size());
                pos12++;
                if (pos12 >= modules.size() - 2)
                    pos12 = 0;
            }
            if (event.value == "F11"){
                int posXTmp = modules[pos11]->getPosX();
                int posYTmp = modules[pos11]->getPosY();
                modules[pos11]->setPos(modules[modules.size() - 2]->getPosX(), modules[modules.size() - 2]->getPosY());
                modules[pos11]->changePos(win.getGraphicWindow(), modules.size());
                modules[modules.size() - 2]->setPos(posXTmp, posYTmp);
                modules[modules.size() - 2]->changePos(win.getGraphicWindow(), modules.size());
                pos11++;
                if (pos11 >= modules.size() - 2)
                    pos11 = 0;
            }
        } else {
            void();
        }
    }
}

void fill_modules(std::vector<Module *> &module_list)
{
    std::string line;
    std::ifstream file("config.txt");

    if (!file.is_open()) {
        std::ofstream output("config.txt");

        if (!output) {
            std::cerr << "can't read / write on the configuration file" << std::endl;
            return;
        }
        output << "CPU\nMemory\n";
        file.open("config.txt");

        if (!file.is_open()) {
            std::cerr << "can't read the configuration file" << std::endl;
            return;
        }
    }
    while (std::getline(file, line)) {
        if (line == "CPU")
            module_list.push_back(new CPUModule());
        else if (line == "Memory")
            module_list.push_back(new MemoryModule());
        else if (line == "Textual")
            module_list.push_back(new TextualModule());
        else if (line == "Heat")
            module_list.push_back(new HeapModule());
        else if (line == "Network")
            module_list.push_back(new NetworkModule());
        else
            std::cerr << "Unrecognized module: " << line << std::endl;
    }
}

int main(int argc, char **argv)
{
    bool graphical = false;
    std::vector<Module *> module_list = {};

    fill_modules(module_list);
    if (argc == 2 && !strcmp(argv[1], "--graphical"))
        graphical = true;
    main_loop(graphical, module_list);
    return 0;
}
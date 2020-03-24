/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** ToyStory.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "ToyStory.hpp"

void ToyStory::tellMeAStory(std::string const &filename, Toy &toy1, bool (Toy::*func1)(const std::string string), Toy &toy2, bool (Toy::*func2)(const std::string string))
{
    std::ifstream file(filename);
    std::string line;
    unsigned int decider = 0;

    if (file.fail()){
        std::cout << "Bad Story" << std::endl;
        return;
    }
    // print pictures
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;

    while (std::getline(file, line)){
        if (line.find("picture:") != std::string::npos){
            std::string picName = line.substr(line.find_last_of(":") + 1);
            if (decider % 2 == 0){ //TOY 1
                if(!toy1.setAscii(picName)){
                    std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what() <<std::endl;
                    continue;
                } else std::cout << toy1.getAscii() << std::endl;
            } else { //TOY 2
                if(!toy2.setAscii(picName)){
                    std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() <<std::endl;
                    continue;
                } else std::cout << toy2.getAscii() << std::endl;
            }
        } else {
            if (decider % 2 == 0){
                if (!((toy1.*func1)(line))){
                    std::cout << toy1.getLastError().where() << ": " << toy1.getLastError().what() <<std::endl;
                    continue;
                }
            } else {
                if (!((toy2.*func2)(line))){
                    std::cout << toy2.getLastError().where() << ": " << toy2.getLastError().what() <<std::endl;
                    continue;
                }
            }
        }
        decider += 1;
    }
}

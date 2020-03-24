/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Main.cpp
*/

#include <iostream>
#include "Toy.hpp"
int main(){
    Toy toto;
    Toy ET(Toy::WOODY, "green", "./woody.txt");
    toto.setName("TOTO !");
    if (toto.getType() == Toy::BASIC_TOY)
        std::cout << "basic toy: " << toto.getName() << std::endl
            << toto.getAscii() << std::endl;
    if (ET.getType() == Toy::WOODY)
        std::cout << "this alien is: " << ET.getName() << std::endl
            << ET.getAscii() << std::endl;
    return 0;
}
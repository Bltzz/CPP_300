/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** ex00
*/

#include "Peon.hpp"
#include "Sorcerer.hpp"
#include <iostream>

Peon::Peon(std::string name) : Victim(name){
    std::cout << "Zog zog." <<std::endl;
}

Peon::~Peon(){
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const{
    std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}

// int  main(){
//     Sorcerer robert("Robert", "the  Magnificent");
//     Victim jim("Jimmy");
//     Peon joe("Joe");
//     std::cout  << robert  << jim  << joe;
//     robert.polymorph(jim);
//     robert.polymorph(joe);
//     return 0;
// }
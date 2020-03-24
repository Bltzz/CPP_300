/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** ex01
*/

#include "Borg.hpp"
#include <iostream>

Borg::Ship::Ship(){
    this->_size = 300;
    this->_maxWarp = 9;
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." <<std::endl;
}

void Borg::Ship::checkCore(){
    if (this->core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else std::cout << "Critical failure imminent." << std::endl;
}
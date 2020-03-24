/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** ex00
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include <iostream>

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp){
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;

    std::cout <<"The ship USS "<< this->getName() << " has been finished."<< std::endl;
    std::cout << "It is "<< this->getLength() <<" m in length and " << this->getWidth()<< " m in width." << std::endl;
    std::cout << "It can go to Warp " << this->getMaxWarp() <<"!" << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core){
    this->core = core;
    std::cout <<"USS " << this->getName() << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore(){
    if(this->core->checkReactor()->isStable())
        std::cout << "USS "<< this->getName() << ": The core is stable at the time."<< std::endl;
    else std::cout << "USS "<< this->getName() << ": The core is unstable at the time."<< std::endl;
}

void Federation::Starfleet::Ship::promote(Captain *captain){
    this->captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->getName() << "." << std::endl;
    }

Federation::Ship::Ship(int length, int width, std::string name){
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;

    std::cout <<"The independent ship "<< this->getName() << " just finished its construction."<< std::endl;
    std::cout << "It is "<< this->getLength() <<" m in length and " << this->getWidth()<< " m in width." << std::endl;
}

void Federation::Ship::setupCore(WarpSystem::Core *core){
    this->core = core;
    std::cout <<this->getName() << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore(){
    if(this->core->checkReactor()->isStable())
        std::cout << this->getName() << ": The core is stable at the time."<< std::endl;
    else std::cout << this->getName() << ": The core is unstable at the time."<< std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name){
    this->_name = name;
}

Federation::Starfleet::Ensign::Ensign(std::string name){
    this->name = name;
    std::cout << "Ensign " << name << ", awaiting orders." <<std::endl;
}

// int main(){
//     Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6);
//     Federation::Starfleet::Captain James("James T. Kirk");
//     Federation::Starfleet::Ensign Ensign("Pavel  Chekov");
//     WarpSystem::QuantumReactor QR;
//     WarpSystem::QuantumReactor QR2;
//     WarpSystem ::Core  core(&QR);
//     WarpSystem ::Core  core2 (&QR2);
//     UssKreog.setupCore (&core);
//     UssKreog.checkCore ();
//     UssKreog.promote (&James);
//     Borg::Ship Cube;
//     Cube.setupCore (& core2);
//     Cube.checkCore ();
//     return  0;
// }
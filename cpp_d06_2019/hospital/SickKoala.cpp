/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** ex02
*/

#include <iostream>
#include "SickKoala.hpp"

SickKoala::SickKoala(std::string name){
    this->name = name;
}

SickKoala::~SickKoala(){
    std::cout << "Mr. "<< this->getName() << ":  Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke(){
    std::cout << "Mr. " << this->getName() << " Gooeeeeerrk !!" << std::endl;
}

bool SickKoala::takeDrug(std::string toCheck){
    if (toCheck.compare("Mars") == 0){
        std::cout << "Mr. " << this->getName() <<": Mars, and it kreogs!" <<std::endl;
        return true;
    }
    else if (toCheck.compare("Buronzand") == 0){
        std::cout << "Mr. " << this->getName() <<": And you'll sleep right away!" <<std::endl;
        return true;
    }
    else {
        std::cout << "Mr. " << this->getName()<< ": Goerkreog!" << std::endl;
        return false;
    }
}

void SickKoala::overDrive(std::string str_overDrive){
    std::string replace = "1337!";
    int first = str_overDrive.find("Kreog!");

    while (first != -1){
        str_overDrive = str_overDrive.replace(first, 6, replace);
        first = str_overDrive.find("Kreog!");
    }
    std::cout << "Mr. " << this->getName() << ": " <<str_overDrive << std::endl;
}
std::string SickKoala::getName(){
    return this->name;
}
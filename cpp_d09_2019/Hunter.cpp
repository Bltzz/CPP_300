/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex02
*/
#include "Hunter.hpp"

Hunter::Hunter(const std::string &name, int level, std::string weapon)
            : Character(name, level), Warrior(name, level, weapon) {
    this->Race = "Elf";
    this->Strength = 9;
    this->Stamina = 9;
    this->Intelligence = 5;
    this->Spirit = 6;
    this->Agility = 25;
    std::cout << this->getName() << " is born from a tree" << std::endl;
}

int Hunter::RangeAttack(){
    if (this->getPower() >= 25){
        this->power -= 25;
        std::cout << this->getName() <<" uses his bow"<< std::endl;
        return (20 + this->Agility);
    }
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
}

void Hunter::RestorePower(){
    this->power = 100;
    std::cout << this->getName() << " meditates" << std::endl;
}


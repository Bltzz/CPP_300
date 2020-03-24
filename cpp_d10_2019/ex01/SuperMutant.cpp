/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** SuperMutant.cpp
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant"){
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant(){
    std::cout << "Aaargh..." << std::endl;

}

void SuperMutant::takeDamage(int damage){
        if (damage > 0){
            this->hitPoints -= (damage - 3);
        if (hitPoints <= 0)
            delete this;
    }
}

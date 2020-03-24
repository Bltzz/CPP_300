/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** RadScorpion.cpp
*/

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion"){
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(){
    std::cout << "* SPROTCH *" << std::endl;

}

void RadScorpion::takeDamage(int damage){
        if (damage > 0){
            this->hitPoints -= (damage - 3);
        if (hitPoints <= 0)
            delete this;
    }
}

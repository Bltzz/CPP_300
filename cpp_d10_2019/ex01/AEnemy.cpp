/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** AEnemy.cpp
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type){
    this->type = type;
    this->hitPoints = hp;
}

AEnemy::~AEnemy(){

}

void AEnemy::takeDamage(int damage){
    if (damage > 0){
        this->hitPoints -= damage;
    }
}

std::string const AEnemy::getType() const{
    return this->type;

}

int AEnemy::getHP() const{
    return this->hitPoints;
}

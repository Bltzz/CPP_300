/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex01
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level) : name(name), level(1),  Range(CLOSE) {
    this->health_points = 100;
    this->level = level;
    this->power = 100;
    this->Race = "Human";
    this->Strength = 5;
    this->Stamina = 5;
    this->Intelligence = 5;
    this->Spirit = 5;
    this->Agility = 5;
    std::cout << this->getName() << " Created"<< std::endl;
}

int Character::CloseAttack(){
    if (this->getPower() >= 10){
        this->power -= 10;
        std::cout << this->getName() <<" strikes with a wooden stick" << std::endl;
        return (10 + this->Strength);
    }
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
}

int Character::RangeAttack(){
    if (this->getPower() >= 10){
        this->power -=10;
        std::cout << this->getName() <<" tosses a stone" << std::endl;
        return (5 + this->Strength);
    }
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
}
void Character::Heal(){
    this->health_points +=50;
    std::cout << this->getName() << " takes a potion" << std::endl;
}
void Character::RestorePower(){
    this->power = 100;
    std::cout << this->getName() << " eats" << std::endl;
}

void Character::TakeDamage(int damage){
    if (damage >= this->getPv())
        std::cout << this->getName() << " out of combat" << std::endl;
    else {
        this->health_points -= damage;
        std::cout << this->getName()<< " takes " << damage << " damage" << std::endl;
    }
}


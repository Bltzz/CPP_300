/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex02
*/
#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, std::string weapon)
            : Character(name, level), weapon_name(weapon) {
    this->Race = "Dwarf";
    this->Strength = 12;
    this->Stamina = 12;
    this->Intelligence = 6;
    this->Spirit = 5;
    this->Agility = 7;
    std::cout << "I'm "<< this->getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

int Warrior::CloseAttack(){
    if (this->getPower() >= 30){
        this->power -= 30;
        std::cout << this->getName() << " strikes with his "<< this->getWeappon() << std::endl;
        return (20 + this->Strength);
    }
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
}

int Warrior::RangeAttack(){
    if (this->getPower() >= 10){
        this->power -= 10;
        std::cout << this->getName() <<" intercepts" << std::endl;
        this->Range = Character::CLOSE;
        return (0);
    }
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
}

// int main()
// {
//     Warrior w("Dwarf", 50);
//     Character c("poney", 42);
//     Character d("Tom", 42);
//     w.RestorePower();
//     c.TakeDamage (w.CloseAttack());
//     c.Heal();
//     c.TakeDamage(w.RangeAttack());
//     c.TakeDamage (200);
//     c.TakeDamage (200);
// }
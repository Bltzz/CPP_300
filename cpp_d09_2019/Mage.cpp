/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex03
*/
#include "Mage.hpp"

Mage::Mage(const std::string &name, int level)
            : Character(name, level){
    this->Race = "Gnome";
    this->Strength = 6;
    this->Stamina = 6;
    this->Intelligence = 12;
    this->Spirit = 11;
    this->Agility = 7;
    std::cout << this->getName() << " teleported" << std::endl;
}

int Mage::CloseAttack(){
    if (this->getPower() >= 10){
        this->power -= 10;
        this->Range = Character::CLOSE;
        std::cout << this->getName() << " blinks" << std::endl;
        return (0);
    }
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
}

int Mage::RangeAttack(){
    if (this->getPower() >= 25){
        this->power -= 25;
        std::cout << this->getName() <<" launches a fire ball" << std::endl;
        return (20 + this->Spirit);
    }
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
}

void Mage::RestorePower(){
    this->power = (getPower() + 50 + this->Intelligence);
    if (this->power > 100)
        this->power = 100;
    std::cout << this->getName() << " takes a mana potion" << std::endl;
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
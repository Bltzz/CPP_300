/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex03
*/
#include "Priest.hpp"

Priest::Priest(const std::string &name, int level)
            : Character(name, level), Mage(name, level){
    this->Race = "Orc";
    this->Strength = 4;
    this->Stamina = 4;
    this->Intelligence = 42;
    this->Spirit = 21;
    this->Agility = 2;
    std::cout << this->getName() << " enters in the order" << std::endl;
}

int Priest::CloseAttack(){
    if (this->getPower() >= 10){
        this->power -= 10;
        std::cout << this->getName() << " uses a spirit explosion"   << std::endl;
        return (10 + this->Spirit);
    }
    std::cout << this->getName() << " out of power" << std::endl;
    return 0;
}

void Priest::Heal(){
    if (this->getPower() >= 10){
        this->power -= 10;
        this->health_points +=70;
        std::cout << this->getName() << " casts a little heal spell" << std::endl;
    }
}

// int main()
// {
//     Priest w("Proest", 50);
//     Character c("poney", 42);
//     Character d("Tom", 42);
//     w.RestorePower();
//     c.TakeDamage (w.CloseAttack());
//     c.Heal();
//     c.TakeDamage(w.RangeAttack());
//     c.TakeDamage (200);
//     c.TakeDamage (200);
// }
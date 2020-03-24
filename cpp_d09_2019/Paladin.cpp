/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex03
*/
#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level, std::string weapon)
            : Character(name, level), Mage(name, level), Priest(name, level), Warrior(name, level, weapon) {
    this->Race = "Human";
    this->Strength = 9;
    this->Stamina = 10;
    this->Intelligence = 10;
    this->Spirit = 10;
    this->Agility = 2;
    std::cout << "the light falls on " << this->getName() << std::endl;
}

int Paladin::Intercept(){
    return this->Warrior::CloseAttack();
}

// int Paladin::CloseAttack(){
//     if (this->getPower() >= 30){
//         this->power -= 30;
//         std::cout << this->getName() << " uses a spirit explosion"   << std::endl;
//         return (this->Strength + 20);
//     }
//     std::cout << this->getName() << " out of power" << std::endl;
//     return 0;
// }

// void Paladin::Heal(){
//     if (this->getPower() >= 10){
//         this->power -= 10;
//         this->health_points +=50;
//         std::cout << this->getName() << " casts a little healspell" << std::endl;
//     }
// }

// int main()
// {
//     Paladin w("Proest", 50);
//     Character c("poney", 42);
//     Character d("Tom", 42);
//     w.RestorePower();
//     c.TakeDamage (w.CloseAttack());
//     c.Heal();
//     c.TakeDamage(w.RangeAttack());
//     c.TakeDamage (200);
//     c.TakeDamage (200);
// }

// int main (){
//     Paladin m("Gurigura", 1, "claws");
//     m.TakeDamage(99);
//     m.CloseAttack();
//     m.RangeAttack();
//     m.RangeAttack();
//     m.Heal();
//     m.RestorePower();
//     m.getPv();
//     m.getPower();
// }
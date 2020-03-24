/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(const std::string &name) : name(name), actionPoints(40), weapon(NULL) {}
Character::~Character(){
    delete weapon;
}

void Character::recoverAP(){
    if (10 + this->actionPoints <= 40)
        this->actionPoints += 10;
    else this->actionPoints = 40;
}

void Character::equip(AWeapon *weapon){
    //this->weapon = NULL;
    this->weapon = weapon;
}

void Character::attack(AEnemy *enemy){
    if (this->weapon && (this->actionPoints > this->getWeapon()->getAPCost())){
        std::cout << this->getName() << " attacks "<< enemy->getType() <<" with a " << this->weapon->getName() << std::endl;
        this->weapon->attack();
        enemy->takeDamage(this->weapon->getDamage());
        this->actionPoints -= this->getWeapon()->getAPCost();
    }
}

std::string const Character::getName() const{
    return this->name;
}

std::ostream &operator<<(std::ostream& os, Character const &c){
    if (c.getWeapon())
        os << c.getName() << " has " << c.getActionPoints() << " AP and wields a " << c.getWeapon()->getName() << std::endl;
    else os << c.getName() << " has " << c.getActionPoints() << " AP and is unarmed" << std::endl;

  return os;
}

/*int main(){
    const auto preda = new Character("Predator");
    const auto prey = new RadScorpion();
    std::cout << *preda;
    AWeapon *pr(new PlasmaRifle());
    AWeapon *pf(new PowerFist());
    preda->equip(pr);
    std::cout << *preda;
    preda->equip(pf);
    preda->attack(prey);
    std::cout << *preda;
    preda->equip(pr);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;
    preda->attack(prey);
    std::cout << *preda;
    return 0;
}
*/
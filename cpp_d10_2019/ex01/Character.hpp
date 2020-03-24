/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Character.hpp
*/

#pragma once
#include <iostream>
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

class Character{
    public:
        Character(const std::string &name);
        ~Character();
        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string const getName() const;
        int getActionPoints() const {return this->actionPoints;}
        AWeapon const *getWeapon() const {return weapon;}
    private:
        std::string const name;
        int actionPoints;
        AWeapon const *weapon;
};
std::ostream &operator<<(std::ostream& os, Character const &c);
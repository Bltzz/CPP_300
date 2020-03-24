/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex03
*/

#pragma once

#include "Priest.hpp"
#include "Warrior.hpp"

class Paladin : virtual public Priest, virtual public Warrior {
    public:
        explicit Paladin(const std::string &name, int level, std::string weapon);
        int Intercept();
        int CloseAttack(){return this->Warrior::CloseAttack();}
        void RestorePower(){this->Warrior::RestorePower();}
        int RangeAttack(){return this->Priest::RangeAttack();}
        void Heal(){this->Priest::Heal();}
        //std::string getName(){return this->name;}
    private:
        std::string name;
};
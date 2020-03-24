/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex01
*/

#pragma once
#include <iostream>

class Character{
    public:
        explicit Character(const std::string &name, int level);
        const std::string &getName() const {return this->name;}
        int getLvl() const {return this->level;}
        int getPv() const {return this->health_points;}
        int getPower() const {return this->power;}

        int CloseAttack();
        int RangeAttack();
        void Heal();
        virtual void RestorePower();
        void TakeDamage(int damage);
    protected:
        enum AttackRange {CLOSE, RANGE};
        std::string name;
        int level;
        int health_points;
        int power;
        std::string Race;
        int Strength;
        int Stamina;
        int Intelligence;
        int Spirit;
        int Agility;

        AttackRange Range;


};
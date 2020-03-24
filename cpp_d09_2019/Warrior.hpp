/*
** EPITECH PROJECT, 2019
** cpp_d09_2019
** File description:
** ex02
*/

#pragma once

#include "Character.hpp"

class Warrior : virtual public Character {
    public:
        explicit Warrior(const std::string &name, int level, std::string weapon = "hammer");
        virtual int CloseAttack();
        int RangeAttack();

        std::string getWeappon(){return this->weapon_name;}
    protected:
        const std::string weapon_name;

};
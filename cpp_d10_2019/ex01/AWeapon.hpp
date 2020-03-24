/*
** EPITECH PROJECT, 2019
** cpp_pool_d10
** File description:
** AWeapon.hpp
*/
#pragma once
#include <iostream>

class AWeapon{
    public:
        AWeapon(const std::string &name, int apcost, int damage);
        virtual ~AWeapon();
        std::string const getName() const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0;
    protected:
        std::string const name;
        int const damage;
        int const actionPoints;
};

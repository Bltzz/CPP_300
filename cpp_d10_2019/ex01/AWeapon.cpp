/*
** EPITECH PROJECT, 2019
** cpp_pool_d10
** File description:
** Ex01
** AWeapon.cpp
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage) : name(name), damage(damage), actionPoints(apcost){}
AWeapon::~AWeapon(){}


std::string const AWeapon::getName() const {
    return this->name;
}

int AWeapon::getAPCost() const {
    return this->actionPoints;
}

int AWeapon::getDamage() const {
    return this->damage;
}

void AWeapon::attack() const {}


/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** PlasmaRifle.cpp
*/

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Riffle", 5, 21){}

void PlasmaRifle::attack() const{
    std::cout << "* piouuu piouuu piouuu *"  << std::endl;
}

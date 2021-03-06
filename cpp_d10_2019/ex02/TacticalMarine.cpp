/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** TacticalMarine.cpp
*/

#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine(){
    std::cout << "Tactical Marine ready for battle" << std::endl;
}
TacticalMarine::TacticalMarine(TacticalMarine const &tm){
    std::cout << "Tactical Marine ready for battle" << std::endl;
    (void)tm;
}

TacticalMarine::~TacticalMarine() {
    std::cout << "Aaargh..." <<std::endl;
}

TacticalMarine *TacticalMarine::clone() const{
    return (new TacticalMarine(*this));

}

void TacticalMarine::battleCry() const{
    std::cout << "For the holy PLOT!" <<std::endl;
}

void TacticalMarine::rangedAttack() const{
    std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const{
    std::cout << "* attacks with chainsword *" << std::endl;
}

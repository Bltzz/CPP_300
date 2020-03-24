/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Cure.cpp
*/

#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
}

Cure::Cure(Cure const &cure){
    this->xp_ = xp_;
}

Cure::~Cure(){}


Cure *Cure::clone() const{
     return (new Cure(*this));
}

void Cure::use(ICharacter &target){
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

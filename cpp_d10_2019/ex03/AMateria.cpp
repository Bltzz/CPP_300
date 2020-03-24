/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** AMateria.cpp
*/

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type(type), xp_(0){
}

AMateria::AMateria(AMateria const &materia) : type(materia.getType()){
    this->xp_ = materia.xp_;
}

AMateria::~AMateria(){
}

void AMateria::use(ICharacter &target){
    this->xp_ += 10;
    (void)target;
}

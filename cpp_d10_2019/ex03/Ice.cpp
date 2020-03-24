/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Ice.cpp
*/

#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
}

Ice::Ice(Ice const &ice){
    this->xp_ = xp_;
}

Ice::~Ice(){}

Ice *Ice::clone() const{
     return (new Ice(*this));
}
void Ice::use(ICharacter &target){
    std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
}



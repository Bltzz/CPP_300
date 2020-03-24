/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** AMateria.hpp
*/

#pragma once
#include <iostream>
#include "ICharacter.hpp"

class AMateria {
    public:
        AMateria(const std::string &type);
        AMateria(AMateria const &amateria);
        AMateria();
        virtual ~AMateria();
        const std::string &getType()const {return this->type;}
        unsigned int getXP() const {return this->xp_;}
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
    protected:
        std::string const type;
        unsigned int xp_;

};
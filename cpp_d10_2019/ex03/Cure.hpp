/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Cure.hpp
*/

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria{
    public:
        Cure();
        Cure(const Cure &cure);
        ~Cure();
        Cure *clone() const;
        void use(ICharacter &target);


};
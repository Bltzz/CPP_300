/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** IMateriaSource.hpp
*/

#pragma once
#include "AMateria.hpp"


class IMateriaSource{
    public:
        virtual ~IMateriaSource(){}
        virtual void learnMateria(AMateria *materia) = 0;
        virtual AMateria *createMateria(const std::string &type) = 0;
};
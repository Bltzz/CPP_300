/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** main.cpp
*/

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <memory>

int main(){
    IMateriaSource *src(new MateriaSource());
    src->learnMateria(new Ice);
    src->learnMateria(new Cure);
    std::unique_ptr <ICharacter> perceval(new Character("Perceval"));
    auto tmp = src->createMateria("ice");
    perceval->equip(tmp);
    tmp = src->createMateria("cure");
    perceval->equip(tmp);
    std::unique_ptr <ICharacter> bohort(new Character("Bohort"));
    perceval->use(0, *bohort);
    perceval->use(1, *bohort);
    return 0;
}


/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(std::string name) : Object(name)
{
    _type = TOY;
}

Toy::Toy(const Toy &obj) : Object(obj._name)
{
    _type = TOY;
}

void Toy::setTaken(bool taken)
{
    _taken = taken;
}
/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string name) : Toy(name)
{
    _type |= TEDDY;
    _buff_toy = this;
}

void Teddy::isTaken()
{
    _taken = true;
    std::cout << "gra hu" << std::endl;
}
/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string const pic)
    : Toy(ToyType::BUZZ, name, pic){}

Buzz::Buzz(std::string name) : Toy(ToyType::BUZZ, name, "./buzz.txt") {}
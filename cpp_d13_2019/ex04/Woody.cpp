/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Wodddy.cpp
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string const pic)
    : Toy(ToyType::WOODY, name, pic){}

Woody::Woody(std::string name) : Toy(ToyType::WOODY, name, "./woody.txt") {}

void Woody::speak(std::string const statement) {
    std::cout << "WOODY: " << this->getName() << " \"" << statement << "\"" << std::endl;
}
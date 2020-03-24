/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Woody.hpp
*/

#pragma once
#include "Toy.hpp"

class Woody : public Toy{
    public:
        Woody(std::string const name);
        Woody(std::string const name, std::string const pic);
        ~Woody(){}

        void speak(std::string const statement);

};
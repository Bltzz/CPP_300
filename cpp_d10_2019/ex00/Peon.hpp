/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** ex00
*/
#pragma once
#include "Victim.hpp"
#include <iostream>

class Peon : public Victim{
    public:
        Peon(std::string name);
        ~Peon();
        void getPolymorphed() const;
};
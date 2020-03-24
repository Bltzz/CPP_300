/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** header for ex04
*/

#pragma once

#include <iostream>
#include "KoalaNurse.hpp"

class KoalaDoctor
{
    private:
        std::string name;
        bool is_working;
    public:
        KoalaDoctor(std::string name);
        ~KoalaDoctor();
        std::string getName();
        void diagnoses(SickKoala *k);
        void timeCheck();
};
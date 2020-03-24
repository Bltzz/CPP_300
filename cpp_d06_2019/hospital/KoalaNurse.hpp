/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** header for ex03
*/

#pragma once
#include <stdio.h>
#include <iostream>
#include "SickKoala.hpp"

class KoalaNurse
{
private:
    size_t id;
    bool is_working;
public:
    KoalaNurse(size_t id);
    ~KoalaNurse();
    size_t getId();
    void giveDrug(std::string drug, SickKoala *k);\
    std::string readReport(std::string filename);
    void timeCheck();
};
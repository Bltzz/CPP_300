/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** header for ex02
*/

#pragma once
#include <stdio.h>
#include <iostream>

class SickKoala
{
private:
    std::string name;
public:
    SickKoala(std::string name);
    ~SickKoala();
    void poke();
    bool takeDrug(std::string toCheck);
    void overDrive(std::string str_overDrive);
    std::string getName();

};

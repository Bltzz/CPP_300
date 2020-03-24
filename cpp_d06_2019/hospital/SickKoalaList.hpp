/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** header for ex05
*/
#pragma once

#include "SickKoala.hpp"
#include "KoalaDoctor.hpp"
#include <iostream>

class SickKoalaList
{
    private:
        SickKoala *koala;
        SickKoalaList *next;
    public:
        SickKoalaList(SickKoala *koala);
        ~SickKoalaList();

        bool isEnd();
        void append(SickKoalaList *);
        SickKoalaList remove(SickKoalaList *);
        SickKoalaList removeFromName(std::string name);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();
};
/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex01
*/

#pragma once

#include <iostream>

class DroidMemory {
    public:
        DroidMemory();
        DroidMemory(size_t fingerprint, size_t exp);
        ~DroidMemory();
        DroidMemory &operator<<(DroidMemory &dm);
        DroidMemory &operator>>(DroidMemory &dm);
        DroidMemory &operator+=(DroidMemory &dm);
        DroidMemory &operator+=(size_t val);
        DroidMemory operator+(DroidMemory &dm);
        DroidMemory operator+(size_t val);

        void setExp(size_t exp){this->Exp = exp;}
        void setFingerprint(size_t fingerprint){this->Fingerprint = fingerprint;}

        size_t getFingerprint() const {return this->Fingerprint;}
        size_t getExp() const {return this->Exp;}
    private:
        size_t Fingerprint;
        size_t Exp;
};
std::ostream &operator<<(std::ostream& os, DroidMemory &dm);

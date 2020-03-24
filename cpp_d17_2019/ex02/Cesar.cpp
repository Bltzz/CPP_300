/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Cesar.cpp
*/

#include "Cesar.hpp"
#include <iostream>

Cesar::Cesar(){
    reset();
}
Cesar::~Cesar(){}

void Cesar::encryptChar(char plainchar){
    if (plainchar >= 'A' && plainchar <= 'Z')
        plainchar = 'A' + ((plainchar + this->_shift - 'A') % 26);
    else if (plainchar >= 'a' && plainchar <= 'z')
        plainchar = 'a' + ((plainchar + this->_shift - 'a') % 26);
    std::cout << plainchar;
    ++_shift;
}

void Cesar::decryptChar(char cipherchar){
    if (cipherchar >= 'A' && cipherchar <= 'Z'){
        cipherchar = (cipherchar - this->_shift - 'A') % 26;
        if (cipherchar < 0)
            cipherchar += 26;
        cipherchar += 'A';
    }
    else if (cipherchar >= 'a' && cipherchar <= 'z'){
        cipherchar = (cipherchar - this->_shift - 'a') % 26;
        if (cipherchar < 0)
            cipherchar += 26;
        cipherchar += 'a';
    }
    std::cout << cipherchar;
    _shift ++;

}

void Cesar::reset(){
    _shift  = 3;
}

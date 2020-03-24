/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** OneTime.cpp
*/

#include "OneTime.hpp"

OneTime::OneTime(std::string key){
    this->key = key;
    this->_shift = 0;
}

OneTime::~OneTime(){}

void OneTime::encryptChar(char plainchar){
    int tmp_plain = 0;
    int tmp_key = 0;
    if (std::isalpha(plainchar)){
        if (plainchar >= 'a')
            tmp_plain = 'a';
        else tmp_plain = 'A';

        if(this->key[this->_shift] >= 'a')
            tmp_key = 'a';
        else tmp_key = 'A';
        plainchar -= tmp_plain - (key[_shift] - tmp_key);
        if (plainchar < 0)
            plainchar += 26;
        plainchar %= 26;
        plainchar += tmp_plain;
    }
    std::cout << plainchar;
    ++_shift;
    _shift %= key.size();
}

void OneTime::decryptChar(char cipherchar){
    int tmp_plain = 0;
    int tmp_key = 0;
    if (isalpha(cipherchar)){
        if (cipherchar >= 'a')
            tmp_plain = 'z';
        else tmp_plain = 'Z';

        if(key[_shift] >= 'a')
            tmp_key = 'a';
        else tmp_key = 'A';
        cipherchar -= tmp_plain + (key[_shift] - tmp_key);
        //  if (cipherchar < 0)
        //     cipherchar += 26;
        cipherchar %= 26;
        cipherchar += tmp_plain;
    }
    std::cout << cipherchar;
    ++_shift;
    _shift %= key.size();
}

void OneTime::reset(){
    _shift = 0;
}

/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** OneTime.hpp
*/
#pragma once
#include <iostream>
#include "IEncryptionMethod.hpp"

class OneTime : public IEncryptionMethod{
    public:
        OneTime(std::string key);
        virtual ~OneTime();
        virtual void encryptChar(char plainchar);
        virtual void decryptChar(char cipherchar);
        virtual void reset();

    private:
        std::string key;
        int _shift = 0;
};
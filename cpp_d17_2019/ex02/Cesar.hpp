/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Cesar.hpp
*/
#pragma once
#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod{
    public:
        Cesar();
        virtual ~Cesar();
        void encryptChar(char plainchar);
		void decryptChar(char cipherchar);
		void reset();

    private:
        int _shift;
};
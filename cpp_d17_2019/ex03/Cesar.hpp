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
        virtual void encryptChar(char plainchar) override;
		virtual void decryptChar(char cipherchar) override;
		virtual void reset();

    private:
        int _shift;
};
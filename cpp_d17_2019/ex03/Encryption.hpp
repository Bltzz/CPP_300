/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Encryption.hpp
*/
#pragma once
#include "IEncryptionMethod.hpp"
#include <iostream>


typedef void (IEncryptionMethod::*t_type_of_cryption)(char);

class Encryption{
    public:
        Encryption(IEncryptionMethod &, t_type_of_cryption);
        virtual ~Encryption() {}

        void operator()(char c);

        static void encryptString(IEncryptionMethod &algo, std::string const &str_to_crypt);
        static void decryptString(IEncryptionMethod &algo, std::string const &str_to_crypt);
    private:
        IEncryptionMethod *algo;
        t_type_of_cryption type;
};
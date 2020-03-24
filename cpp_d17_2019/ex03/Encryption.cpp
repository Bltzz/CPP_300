/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Encryption.cpp
*/

#include "Encryption.hpp"
#include <bits/stdc++.h>

void Encryption::encryptString(IEncryptionMethod &algo, std::string const &str_to_crypt){
    algo.reset();
    std::for_each(str_to_crypt.begin(), str_to_crypt.end(), Encryption(algo, &IEncryptionMethod::encryptChar));
    std::cout<<std::endl;
}

void Encryption::decryptString(IEncryptionMethod &algo, std::string const &str_to_crypt){
    algo.reset();
    std::for_each(str_to_crypt.begin(), str_to_crypt.end(), Encryption(algo, &IEncryptionMethod::decryptChar));
    std::cout <<std::endl;

}

Encryption::Encryption(IEncryptionMethod &algo, t_type_of_cryption type){
    this->algo = &algo;
    this->type = type;
}

void Encryption::operator()(char c){
    (algo->*type)(c);
}

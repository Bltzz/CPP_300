/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** ex03
*/

#include <iostream>
#include <fstream>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(size_t id){
    this->id = id;
    this->is_working = false;
}

KoalaNurse::~KoalaNurse(){
    std::cout << "Nurse " << this->getId()<< ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *k){
    k->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename){
    std::string koala_name;
    std::ifstream file;
    std::string tmp;
    char drug[256];

    try{
        koala_name = filename.substr(0, filename.find("."));
    }catch (std::exception &e) {
        exit(1);
    }
    file.open(filename);
    if (!file.is_open() || std::string::npos == filename.find(".report"))
        exit(1);
    for (int i = 0; file.get(drug[i]); i++)

    if (drug == NULL)
        exit(1);
    file.close();
    std::cout << "Nurse " << this->getId() <<": Kreog! Mr. " << koala_name << "needs a " << drug <<"!" << std::endl;
    tmp = drug;
    return tmp;
}

void KoalaNurse::timeCheck(){
    if (this->is_working)
        std::cout << "Nurse " << this->getId() <<": Time to get to work!"<< std::endl;
    else
        std::cout << "Nurse " << this->getId() <<": Time to go home to my eucalyptus forest!"<< std::endl;
    this->is_working = !this->is_working;
}

size_t KoalaNurse::getId(){
    return this->id;
}
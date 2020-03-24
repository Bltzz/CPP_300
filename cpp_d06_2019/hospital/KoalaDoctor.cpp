/*
** EPITECH PROJECT, 2019
** cpp_d06_2019
** File description:
** ex04
*/

#include <iostream>
#include <fstream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name){
    this->name = name;
    this->is_working = false;
    std::cout << "Dr. "<< name <<": I'm Dr. " << name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor(){

}
void KoalaDoctor::diagnoses(SickKoala *k){
    std::ofstream new_file;
    std::string filename = k->getName() + ".report";
    std::string drugs[] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};

    std::cout << "Dr. " << this->getName() << ": So what's goerking you Mr. "<<k->getName()<<"?" << std::endl;
    k->poke();
    new_file.open(filename);
    new_file << drugs[random()%5] << std::endl;
    new_file.close();


}

void KoalaDoctor::timeCheck(){
    if (this->is_working)
        std::cout << "Dr. " << this->getName() << ": Time to get to work!"<< std::endl;
    else
        std::cout << "Dr. " << this->getName() <<": Time to go home to my eucalyptus forest!"<< std::endl;
    this->is_working = !this->is_working;
}

std::string KoalaDoctor::getName(){
    return this->name;
}

// int main(){
//     size_t tmp = 12345;
//     KoalaDoctor KD("TOM");
//     KoalaNurse *KN1 = new KoalaNurse(tmp);
//     SickKoala *K1 = new SickKoala("STeve");

//     KD.diagnoses(K1);

//     delete KN1;
//     delete K1;
//     return 0;
// }
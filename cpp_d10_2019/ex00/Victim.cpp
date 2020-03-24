/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** ex00
*/


#include "Victim.hpp"

Victim::Victim(std::string name){
    this->name = name;

    std::cout << "Some random victim called " << this->getName() << " just popped!" << std::endl;
}

Victim::~Victim(){
    std::cout << "Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}

std::ostream &operator<<(std::ostream& os, Victim const &v){
    os << "I'm " << v.getName() << " and I like otters!" << std::endl;
  return os;
}

void Victim::getPolymorphed() const {
    std::cout << this->getName() <<" has been turned into a cute little sheep!" << std::endl;
}

/*
** EPITECH PROJECT, 2019
** cpp_d10_2019
** File description:
** ex00
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title){
    this->name = name;
    this->title = title;

    std::cout << this->name << ", " << this->title << ", is born!"<< std::endl;
}

Sorcerer::~Sorcerer(){
    std::cout << this->name << ", "<< this->title <<", is dead. Consequences will never be the same!" << std::endl;
}

std::ostream &operator<<(std::ostream& os, Sorcerer const &s){
    os << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies!" << std::endl;
  return os;
}

void Sorcerer::polymorph(const Victim &victim) const{
        victim.getPolymorphed();
}


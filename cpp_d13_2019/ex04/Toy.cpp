/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy() : type(BASIC_TOY), name("toy"), pic(Picture()) {}

Toy::Toy(ToyType const type, std::string name, std::string const pic) : type(type), name(name), pic(Picture(pic)) {}

Toy::Toy(Toy const &t) : name(t.name), type(t.type), pic(t.pic) {}

Toy::~Toy(){}


void Toy::setName(std::string const &name){
    this->name = name;
}

bool Toy::setAscii(std::string const &file){
    return (this->pic.getPictureFromFile(file));
}


Toy::ToyType Toy::getType() const{
    return this->type;
}

std::string Toy::getName() const{
    return this->name;
}

std::string Toy::getAscii() const{
    return this->getPicture().getData();
}

void Toy::speak(std::string statement){
    std::cout << this->getName() << " \"" << statement << "\"" << std::endl;
}

Toy &Toy::operator<<(std::string newStr){

    this->pic.setData(newStr);
    return *this;
}


std::ostream &operator<<(std::ostream& os, Toy const &t){
    os << t.getName() << "\n" << t.getAscii() << std::endl;
  return os;
}
Toy &Toy::operator=(const Toy &t){
    this->name = t.getName();
    this->pic = t.pic;
    return *this;
}
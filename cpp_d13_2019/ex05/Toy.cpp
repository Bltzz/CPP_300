/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

std::ostream &operator<<(std::ostream& os, Toy const &t){
    os << t.getName() << "\n" << t.getAscii() << std::endl;
  return os;
}

Toy::Toy() : type(BASIC_TOY), name("toy"), pic(Picture()) {
    //this->error = NULL;
}

Toy::Toy(ToyType const type, std::string name, std::string const pic) : type(type), name(name), pic(Picture(pic)) {
    //this->error = NULL;
}

Toy::Toy(Toy const &t) : name(t.name), type(t.type), pic(t.pic), error(t.error) {}


Toy::~Toy(){}


void Toy::setName(std::string const &name){
    this->name = name;
}

bool Toy::setAscii(std::string const &file){
    bool tmp = this->pic.getPictureFromFile(file);
    if (tmp)
        return true;
    else{
        this->error.type = Error::PICTURE;
        return false;
    }
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

bool Toy::speak_es(std::string statement){
    (void)statement;
    this->error.type = Error::SPEAK;
    return false;
}

Toy &Toy::operator<<(std::string newStr){
    this->pic.setData(newStr);
    return *this;
}

Toy &Toy::operator=(const Toy &t){
    this->name = t.getName();
    this->pic = t.pic;
    return *this;
}


Toy::Error Toy::getLastError() const{
    return this->error;
}

std::string const Toy::Error::what() const{
    if (this->type == ErrorType::SPEAK)
        return "wrong mode";
    else if (this->type == ErrorType::PICTURE)
        return "bad new illustration";
    else return "";
}

std::string const Toy::Error::where() const{
    if (this->type == ErrorType::SPEAK)
        return "speak_es";
    else if (this->type == ErrorType::PICTURE)
        return "setAscii";
    else return "";
}

//Toy::Error::Error() : type(UNKNOWN){}
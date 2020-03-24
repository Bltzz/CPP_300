/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex00
*/

#include "Droid.hpp"
#include <iostream>

Droid::Droid() : _serial(""), Energy(50), Attack(25), Toughness(15), status(new std::string("Standing by")) {
    std::cout << "Droid '' Activated" << std::endl;
}

Droid::Droid(std::string serial) : Attack(25), Toughness(15){
    this->_serial = serial;
    this->Energy = 50;
    this->status = new std::string("Standing by");
    std::cout << "Droid '" << serial << "' Activated" << std::endl;
}

Droid::Droid(Droid const &orig) : _serial(orig._serial), Energy(orig.Energy), Attack(25), Toughness(15) {
    this->setStatus(NULL);
    this->status = new std::string(*orig.status);
    std::cout << "Droid '" << this->getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(){
    std::cout << "Droid '" << this->getId()<< "' Destroyed" << std::endl;
}

std::ostream &operator<<(std::ostream& os, Droid const &droid)
{
  os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
  return os;
}

bool Droid::operator==(Droid const &d) const {
     if ((this->_serial.compare(d._serial) == 0) && this->Energy == d.Energy && this->Attack == d.Attack && this->Toughness == d.Toughness && (this->getStatus()->compare(*d.status) == 0))
        return true;
    return false;
}

bool Droid::operator!=(Droid const &d) const {
     if ((this->_serial.compare(d._serial) == 0) && this->Energy == d.Energy && this->Attack == d.Attack && this->Toughness == d.Toughness && (this->getStatus()->compare(*d.status) == 0))
        return false;
    return true;
}

Droid &Droid::operator=(Droid const &d){
    if(this == &d)
        return *this;
    this->status = d.status;
    this->setEnergy(d.Energy);
    this->setId(d._serial);

    return *this;
}

Droid &Droid::operator<<(size_t &reload){
    size_t val;

    if (this->getEnergy() >= 100){
        this->setEnergy(100);
        return *this;
    }
    if ((this->getEnergy() + reload) >= 100)
        val = 100 - this->getEnergy();
    else val = reload;
    this->setEnergy(this->getEnergy() + val);
    reload -= val;
    return *this;
}

// int main (){
//     Droid d;
//     Droid d1("Avenger");
//     Droid d3(d1);
//     size_t Durasel = 200;
//     std::cout << d << std::endl;
//     std::cout << d1 << std::endl;

//     std::cout << d3 << std::endl;
//     d = d1;
//     d.setStatus(new std::string("Kill Kill Kill!")) ;
//     d << Durasel ;
//     std::cout << d << " --" << Durasel << std::endl ;
//     Droid d2 = d;
//     d.setId("Rex");
//     std::cout << (d2!=d) << std::endl;
//     return 0;
// }
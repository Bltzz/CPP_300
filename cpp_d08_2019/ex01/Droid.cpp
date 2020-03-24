/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex01
*/

#include "Droid.hpp"
#include <iostream>

Droid::Droid(std::string serial) : Attack(25), Toughness(15){
    this->_serial = serial;
    this->Energy = 50;
    this->status = new std::string("Standing By");
    std::cout << "Droid '" << serial << "' Activated" << std::endl;
    this->BattleData = new DroidMemory();
}

Droid::Droid(Droid const &orig) : Attack(orig.Attack), Toughness(orig.Toughness) {
    this->_serial = orig._serial;
    this->Energy = 50;
    this->status = new std::string(*orig.status);
    std::cout << "Droid '" << this->getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(){
    delete this->status;
    std::cout << "Droid '" << this->getId()<< "' Destroyed" << std::endl;
}

std::ostream &operator<<(std::ostream& os, Droid const &droid)
{
  os << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
  return os;
}

bool Droid::operator==(Droid const &d) const {
     if (this->getStatus()->compare(*d.status) == 0)
        return true;
    return false;
}

bool Droid::operator!=(Droid const &d) const {
     if (this->getStatus()->compare(*d.status) == 0)
        return false;
    return true;
}

Droid &Droid::operator=(const Droid &d){
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



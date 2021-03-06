/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex03
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : Fingerprint(random()), Exp(0) {}

DroidMemory::DroidMemory(size_t fingerprint, size_t exp) : Fingerprint(fingerprint), Exp(exp) {}

DroidMemory::~DroidMemory(){}

DroidMemory &DroidMemory::operator<<(DroidMemory &dm){
    this->setExp(this->getExp() + dm.getExp());
    this->Fingerprint ^= dm.getFingerprint();
    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &dm){
    dm.setExp(this->getExp() + dm.getExp());
    dm.Fingerprint ^= this->getFingerprint();
    return dm;
}

DroidMemory &DroidMemory::operator+=(DroidMemory &dm){
    return (*this << dm);
}

DroidMemory &DroidMemory::operator+=(size_t val){
    this->setExp(this->getExp() + val);
    this->Fingerprint ^= val;
    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory &dm){
    DroidMemory tmp;
    tmp = (*this += dm);
    return tmp;
}

DroidMemory DroidMemory::operator+(size_t val){
    DroidMemory tmp;
    tmp = (*this += val);
    return tmp;
}

bool DroidMemory::operator==(DroidMemory const &dm) const {
    if (this->getFingerprint() == dm.getFingerprint() && this->getExp() == dm.getExp())
        return true;
    else return false;
}

bool DroidMemory::operator!=(DroidMemory const &dm) const {
    if (this->getFingerprint() == dm.getFingerprint() && this->getExp() == dm.getExp())
        return false;
    else return true;
}

bool DroidMemory::operator<(DroidMemory const &dm) const {
    return (this->getExp() < dm.getExp());
}

bool DroidMemory::operator>(DroidMemory const &dm) const {
    return (this->getExp() > dm.getExp());
}

bool DroidMemory::operator<=(DroidMemory const &dm) const {
    return (this->getExp() <= dm.getExp());
}

bool DroidMemory::operator>=(DroidMemory const &dm) const {
    return (this->getExp() >= dm.getExp());
}

bool DroidMemory::operator==(size_t val) const {
    return (this->getExp() == val);
}
bool DroidMemory::operator!=(size_t val) const {
    return (this->getExp() != val);
}
bool DroidMemory::operator<(size_t val) const {
    return (this->getExp() < val);
}
bool DroidMemory::operator>(size_t val) const {
    return (this->getExp() > val);
}
bool DroidMemory::operator<=(size_t val) const {
    return (this->getExp() <= val);
}
bool DroidMemory::operator>=(size_t val) const {
    return (this->getExp() >= val);
}

std::ostream &operator<<(std::ostream& os, DroidMemory const &dm)
{
  os << "DroidMemory '" << dm.getFingerprint() << "', " << dm.getExp();
  return os;
}
// int main ()
// {
// DroidMemory mem1;
// mem1 += 42;
// DroidMemory mem2 = mem1;
// std :: cout << mem1 << std :: endl ;
// DroidMemory mem3;
// mem3 << mem1;
// mem3 >> mem1;
// mem3 << mem1;
// std::cout << mem3 << std::endl;
// std::cout << mem1 << std::endl;
// }

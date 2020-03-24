/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex03
*/

#include "Droid.hpp"
#include <iostream>

Droid::Droid(std::string serial) : Attack(25), Toughness(15){
    this->_serial = serial;
    this->Energy = 50;
    this->status = new std::string("Standing By");
    this->BattleData = new DroidMemory;
    std::cout << "Droid '" << serial << "' Activated" << std::endl;
}

Droid::Droid(Droid const &orig) : Attack(orig.Attack), Toughness(orig.Toughness){
    this->_serial = orig._serial;
    this->status = new std::string(orig.status->c_str());
    this->BattleData = new DroidMemory(*orig.BattleData);
    if (this->getEnergy() < 50)
        this->setEnergy(50);
    std::cout << "Droid '" << this->getId() << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(){
    delete this->status;
    delete this->BattleData;
    std::cout << "Droid '" << this->getId()<< "' Destroyed" << std::endl;
}

std::ostream &operator<<(std::ostream& os, Droid &droid)
{
  os << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", " << droid.getEnergy();
  return os;
}

bool Droid::operator==(Droid const &d) const {
     if (this->getStatus().compare(*d.status) == 0)
        return true;
    return false;
}

bool Droid::operator!=(Droid const &d) const {
     if (this->getStatus().compare(*d.status) == 0)
        return false;
    return true;
}

Droid Droid::operator=(Droid * const d){
    if (this->getStatus())
        delete this->status;

    this->status = new std::string(d->status->c_str());
    if (this->BattleData)
        delete this->BattleData;
    this->setEnergy(d->Energy);
    this->setId(d->_serial);
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

bool Droid::operator()(const std::string *taskName, size_t reqSkill){
    if (this->getBattleData()->getExp() >= reqSkill){
        if (this->getEnergy() > 10){
            this->setEnergy(this->getEnergy() - 10);
            this->setTask(*taskName);
            this->getBattleData()->setExp(this->getBattleData()->getExp() + 0.5*reqSkill);
            this->setStatus(new std::string(*taskName + " - Completed!"));
            return true;
        } else {
            this->setEnergy(0);
            this->setStatus(new std::string ("Battery Low"));
            return false;
        }
    } else {
        if (this->getEnergy() > 10)
            this->setEnergy(this->getEnergy() - 10);
        else this->setEnergy(0);
        this->setStatus(new std::string(*taskName + " - Failed!"));
        this->getBattleData()->setExp(this->getBattleData()->getExp() + reqSkill);
    }
    return false;
}

/*
##########################################################################
TEST METHODS
##########################################################################

static void testMemory ()
{
    DroidMemory mem1 ;
    mem1 += 42;
    std::cout << mem1 << std::endl;
    DroidMemory mem2;
    mem2 << mem1;
    mem2 >> mem1;
    mem2 << mem1;
    std :: cout << mem2 << std::endl;
    std :: cout << mem1 << std::endl;
    DroidMemory mem3 = mem1;
    DroidMemory mem4;
    mem4 = mem1 + mem3;
}

static void testDroids()
{
    Droid d("rudolf");
    Droid d2("gaston");
    size_t DuraSell = 40;

    d << DuraSell;
    d.setStatus(new std::string("having some reset"));
    d2.setStatus(new std::string("having some reset"));
    if (d2 != d && !(d == d2))
        std::cout << "a droid is a droid, all its matter is what it 's doing" << std::endl;

    d(new std::string("take a coffee"), 20);
    std::cout << d << std::endl;
    while (d(new std::string("Patrol around"), 20)){
        if (!d(new std::string("Shoot some ennemies"), 50))
            d(new std::string("Run Away"), 20);
        std::cout << d << std::endl;
    }
    std::cout << d << std::endl;
}
int main ()
{
    testMemory() ;
    testDroids() ;
    return 0;
}

#####################################################################
*/

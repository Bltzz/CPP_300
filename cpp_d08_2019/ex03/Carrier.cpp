/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex03
*/

#include "Carrier.hpp"
#include <math.h>

Carrier::Carrier() : id(""), Energy(300), Attack(100), Toughness(90) {
    this->Speed = 0;
    for (int i = 0; i < 5; i++){
        this->Droids[i] = NULL;
    }
}

Carrier::Carrier(std::string id) : Energy(300), Attack(100), Toughness(90) {
    this->id = id;
    this->Speed = 0;
    for (int i = 0; i < 5; i++)
        this->Droids[i] = NULL;
}

Carrier::~Carrier(){
    for (int i= 0; i<5; i++){
        this->Droids[i] = NULL;
    }
}

Carrier Carrier::operator<<(Droid *d){
    Droid *tmp = d;
    this->setSpeed(100);
    for (int i = 0; i < 5 && (this->Droids[i] == nullptr); i++){
            this->Droids[i] = tmp;
            this->setSpeed(100 - 10 * this->getNbrDroids());
            break;
    }
    this->setSpeed(100 - 10 * this->getNbrDroids());
    return *this;
}

Carrier Carrier::operator>>(Droid * &d){
    (void)d;
    for (int i = 0; i < 5; i++){
        if (this->Droids[i] != nullptr){
            d = this->Droids[i];
            this->Droids[i] = NULL;
            if (this->getNbrDroids() != 0)
                this->setSpeed(100 - 10 * this->getNbrDroids());
            else this->setSpeed(0);
            return *this;
        }
    }
    return *this;
}

Droid &Carrier::operator[](Droid const d) const {
    for (int i = 0; i < 5; i++){
        if (this->Droids[i] == &d){
            return *this->Droids[i];
        } else {
            delete this->Droids[i];
            return *this->Droids[i];
        }
    }
    return *this->Droids[1];
}

Droid &Carrier::operator[](int pos) const{
   return *this->Droids[pos];
}

Carrier &Carrier::operator~(){
    std::cout << "Carrier '" << this->getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; i++){
        std::cout << "[" << i << "] : ";
        if (this->Droids[i] == NULL)
            std::cout << "Free";
        else std::cout << *this->Droids[i];
        std::cout << std::endl;
    }
    if (this->getNbrDroids() != 0)
        this->setSpeed(100 + 10 * this->getNbrDroids());
    else this->setSpeed(0);
    return *this;
}

size_t Carrier::getNbrDroids() const {
    size_t counter = 0;
        for (int i = 0; i < 5; i++){
            if (&this->getDroids()[i] != nullptr){
                counter++;
            }
        }
        return counter;
}

bool Carrier::operator()(int x, int y){
    size_t calcEnergy = (abs(x) + abs(y)) * (10 * this->getNbrDroids());
    if (this->getEnergy() > calcEnergy || this->getSpeed() == 0){
        this->setEnergy(this->getEnergy() - calcEnergy);
        this->setX(x);
        this->setY(y);
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream& os, Carrier const &c)
{
    if (c.getNbrDroids())
        std::cout << "Carrier '" << c.getId() << "'" << std::endl;
    else std::cout << "Carrier '" << c.getId()<< "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; i++){
        if (&c.getDroids()[i] != nullptr)
            std::cout << "["<< i<< "] : Droid "<< c.getDroids()[i].getId()<< ", "<< c.getDroids()[i].getStatus() << ", " << c.getDroids()[i].getEnergy() <<std::endl;
        else
         std::cout << "["<< i<< "] : Free" <<std::endl;
    }
    std::cout << "Speed : " << c.getSpeed() << ", Energy : "<< c.getEnergy() << std::endl;
  return os;
}
/*
######################################
TEST Methods
######################################
*/
int main(){
    Carrier c("HellExpress");
    Droid *d1 = new Droid ( "Commander" ) ;
    Droid *d2 = new Droid ( "Sergent" ) ;
    Droid *d3 = new Droid ( "Troufiont" ) ;
    Droid *d4 = new Droid ( "Groupie" ) ;
    Droid *d5 = new Droid ( "BeerHolder" ) ;

    c << d1 << d2 << d3 << d4 << d5;
    c.getNbrDroids();
    std::cout << c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3 ;
    printf("####################\n");
    std::cout << c.getSpeed() << std::endl;
    printf("$$$$$$$$$$$$$$$$$$$$$$\n");
    c[0] = d1;
    printf("####################\n");
    std::cout << (~c).getSpeed() <<std::endl;
    printf("####################\n");
    c (4 , 2);
    std::cout << c << std::endl ;
    c(-15, 4);
    std :: cout << c << std :: endl ;
    c[3] = 0;
    c[4] = 0;
    (~c)(-15, 4);
    std::cout << c << std::endl ;
    return 0;
}


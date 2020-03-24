/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex03
*/

#pragma once
#include "Droid.hpp"
#include <iostream>

class Carrier{
    public:
        Carrier();
        Carrier(std::string id);
        ~Carrier();
        Carrier operator<<(Droid *d);
        Carrier operator>>(Droid * &d);
        bool operator()(int x, int y);


        Droid &operator[](Droid const d) const;
        Droid &operator[](int pos) const;
        Carrier &operator~();

        void setId(std::string ID){this->id = ID;}
        void setEnergy(size_t energy){this->Energy = energy;}
        void setSpeed(size_t speed){this->Speed = speed;}
        void setX(int x){this->x = x;}
        void setY(int y){this->y = y;}

        std::string getId() const {return this->id;}
        size_t getEnergy() const {return this->Energy;}
        size_t getAttack() const {return this->Attack;}
        size_t getToughness() const {return this->Toughness;}
        size_t getSpeed() const {return this->Speed;}
        Droid *getDroids() const {return *this->Droids;}
        size_t getNbrDroids() const;
        int getX() const {return this->x;}
        int getY() const {return this->y;}

    private:
        std::string id;
        size_t Energy;
        size_t const Attack;
        size_t const Toughness;
        size_t Speed;
        Droid *Droids[5];
        int x;
        int y;
};
std::ostream &operator<<(std::ostream& os, Carrier const &c);

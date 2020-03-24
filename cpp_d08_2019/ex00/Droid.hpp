/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex00
*/

#pragma once
#include <iostream>
#include <fstream>

class Droid{
    private:
        std::string _serial;
        size_t Energy;
        size_t const Attack;
        size_t const Toughness;
        std::string *status;

    public:
        Droid();
        Droid(std::string serial);
        Droid(Droid const &);
        ~Droid();
        bool operator==(Droid const &d) const;
        bool operator!=(Droid const &d) const;
        Droid &operator=(Droid const &d);
        Droid &operator<<(size_t &reload);
        void setId(std::string serial){this->_serial = serial;}
        void setStatus(std::string *newStatus){this->status = newStatus;}
        void setEnergy(size_t energy){
            if(energy <= 100)
                this->Energy = energy;
            else this->Energy = 100;
        }

        std::string getId() const {return this->_serial;}
        size_t getEnergy() const {return Energy;}
        size_t getAttack() const {return Attack;}
        size_t getToughness() const {return Toughness;}
        std::string *getStatus() const {return this->status;}
};
        std::ostream &operator<<(std::ostream& os, Droid const &droid);

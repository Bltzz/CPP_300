/*
** EPITECH PROJECT, 2019
** cpp_d08_2019
** File description:
** ex03
*/

#pragma once
#include <iostream>
#include <fstream>
#include "DroidMemory.hpp"

class Droid{
    public:
        explicit Droid(std::string serial);
        Droid(Droid const &orig);
        ~Droid();
        bool operator==(Droid const &d) const ;
        bool operator!=(Droid const &d) const ;
        Droid operator=(Droid * const d);
        Droid &operator<<(size_t &reload);
        bool operator()(const std::string *taskName, size_t reqSkill);

        void setId(std::string serial){this->_serial = serial;}
        void setEnergy(size_t energy){this->Energy = energy;}
        void setStatus(std::string *newStatus){
            delete this->status;
            this->status = newStatus;
        }
        void setBattleData(DroidMemory *dm){this->BattleData = dm;}
        void setTask(std::string task){this->task = task;}

        std::string getId() const {return this->_serial;}
        size_t getEnergy() const {return this->Energy;}
        size_t getAttack() const {return this->Attack;}
        size_t getToughness() const {return this->Toughness;}
        std::string getStatus() const {return *this->status;}
        DroidMemory *getBattleData() const {return this->BattleData;}
        std::string getTask() const {return this->task;}

    private:
        std::string _serial;
        size_t Energy;
        size_t const Attack;
        size_t const Toughness;
        std::string *status;
        DroidMemory *BattleData;
        std::string task;
};
        std::ostream &operator<<(std::ostream& os, Droid &droid);

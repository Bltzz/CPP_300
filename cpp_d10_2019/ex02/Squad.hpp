/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Squad.hpp
*/

#pragma once
#include "ISquad.hpp"

class Squad : public ISquad{
    public:
        Squad(Squad &s);
        Squad();
        virtual ~Squad();
        int getCount() const {return this->count;}
        ISpaceMarine* getUnit(int pos);
        int push(ISpaceMarine *m);
        Squad &operator=(Squad const &s);


    protected:
        int count;
        int size;
        ISpaceMarine **arrOfMarines;
        void resizeArrOfMarines();
};
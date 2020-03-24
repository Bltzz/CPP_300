/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Squad.cpp
*/
#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include <iostream>
#include <memory>

Squad::Squad(Squad &s){
    this->count = s.count;
    this->size = s.size;
    this->arrOfMarines = new ISpaceMarine*[s.size];
    this->arrOfMarines = s.arrOfMarines;
    for (int i =0; i< s.size ; i++)
        this->arrOfMarines[i] = NULL;
    for (int j = 0; j < this->size; j++){
        this->arrOfMarines[j] = s.arrOfMarines[j];
        delete(s.arrOfMarines[j]);
    }
}

Squad::Squad() : count(0), size(10) {
    this->arrOfMarines = new ISpaceMarine*[size];
    for (int i = 0; i < size; i++)
        this->arrOfMarines[i] = NULL;
}

Squad::~Squad(){
    for (int i = 0; i < size; i++)
        delete(this->arrOfMarines[i]);
    delete[] arrOfMarines;
}

ISpaceMarine *Squad::getUnit(int pos){
    if (pos > this->size || pos < 0)
        return NULL;
    return(this->arrOfMarines[pos]);
}

int Squad::push(ISpaceMarine *m){
    if (!m)
        return this->count;
    if (this->count >= this->size)
        resizeArrOfMarines();
     for (int i = 0; i < count; i++){
        if (this->arrOfMarines[i] == m)
            return(count);
    }
    this->arrOfMarines[count] = m;
    count += 1;
    return count;
}

Squad &Squad::operator=(Squad const &s){
    for (int i = 0; i < this->count; i++)
        delete (this->arrOfMarines[i]);
    delete[] this->arrOfMarines;
    for (int i = 0; i < this->count; i++)
        this->arrOfMarines[i] = s.arrOfMarines[i];
    return *this;
}

void Squad::resizeArrOfMarines(){
    int i;
    size_t tmp_size = size * 1.5;
    ISpaceMarine **tmp = new ISpaceMarine *[tmp_size];

    for (i = 0; i < (int) size; i++)
        tmp[i] = this->arrOfMarines[i];
    while (i < (int) tmp_size){
        tmp[i] = NULL;
        i++;
    }
    delete[] this->arrOfMarines;
    this->arrOfMarines = tmp;
    this->size = tmp_size;
}



/*
############################################################

*/

int main(){
    std::unique_ptr <ISquad> vlc(new Squad);
    vlc->push(new TacticalMarine);
    vlc->push(new AssaultTerminator);
    for (int i = 0; i < vlc->getCount(); ++i){
        const auto cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    return 0;
}
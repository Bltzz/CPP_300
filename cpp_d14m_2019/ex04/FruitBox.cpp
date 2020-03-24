/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** FruitBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int len){
    this->size = len;
    this->numFruit = 0;
    this->listOfFruit = nullptr;
}

FruitBox::~FruitBox(){}

int FruitBox::nbFruits(){
    int counter = 0;
    while (listOfFruit->next){
        counter++;
        this->listOfFruit = listOfFruit->next;
    }
    return counter;
}

bool FruitBox::putFruit(Fruit *f) {
    FruitNode *tmp = this->listOfFruit;
    FruitNode *tmp2 = new FruitNode();
    if (this->numFruit == this->size)
        return false;
    if (!tmp){
        this->listOfFruit = new FruitNode();
        this->listOfFruit->current = f;
        this->listOfFruit->next = nullptr;
        numFruit++;
        return true;
    }
    while (tmp->next && tmp->current != f)
        tmp = tmp->next;
    if (tmp->current == f)
        return false;
    tmp2->current = f;
    tmp2->next = NULL;
    tmp->next = tmp2;
    numFruit++;

    return true;
}

Fruit *FruitBox::pickFruit(){
    Fruit *f;

    if (this->numFruit == 0)
        return nullptr;
    if (this->listOfFruit)
        f = this->listOfFruit->current;
    else f = nullptr;

    this->listOfFruit->current = nullptr;
    if (this->listOfFruit != 0)
        this->listOfFruit = this->listOfFruit->next;
    this->numFruit -= 1;
    return f;
}
FruitNode *FruitBox::head(){
    if (!this->listOfFruit)
        return 0;
    return this->listOfFruit;
}

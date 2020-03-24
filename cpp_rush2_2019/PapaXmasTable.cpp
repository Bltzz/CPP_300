/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** PapaXmasTable.cpp
*/
#include "PapaXmasTable.hpp"

PapaXmasTable::PapaXmasTable(){
    for (int i = 0; i < 11; i++){

        _objOnTable[i] = NULL;
        _names[i] = "";

    }
}
/*
PapaXmasTable::~PapaXmasTable(){
    //???? delete _names;
}*/

Object **PapaXmasTable::getTable(){
    return this->_objOnTable;

}

Object * PapaXmasTable::Take(int type){
    Object *tmp;
    for (int i = 0; i < 10; i++){
        if (_objOnTable[i] != NULL && (_objOnTable[i]->getType() & type)){
            _objOnTable[i]->isTaken();
            tmp = _objOnTable[i];
            _objOnTable[i] = NULL;
            this->fillStringArray();
            return tmp;
        }
    }
    std::cerr << "Table is empty!" << std::endl;
    return NULL;
}

Object * PapaXmasTable::Take(){
    Object *tmp;
    for (int i = 0; i < 10; i++){
        if (_objOnTable[i] != NULL){
            _objOnTable[i]->isTaken();
            tmp = _objOnTable[i];
            _objOnTable[i] = NULL;
            this->fillStringArray();
            return tmp;
        }
    }
    std::cerr << "Table is empty!" << std::endl;
    return NULL;
}

void PapaXmasTable::fillStringArray(){
    for (int i = 0; i < 10; i++)
        _names[i] = "";
    for (int i = 0; i < 10; i++){
        if (_objOnTable){
            _names[i] = _objOnTable[i]->getName();
        }
    }
}

std::string * PapaXmasTable::Look(){
    return  _names;
}


bool PapaXmasTable::Put(Object *object){
    for (int i = 0; i < 10; i++){
        if (_objOnTable[i] == NULL){
            _objOnTable[i] = object;
            this->fillStringArray();
            return true;
        }
    }
    std::cerr << "To many items! Table will collapse!" << std::endl;
    return false;
}

ITable *createTable(){
    /*ITable *tmp = new ITable;
    tmp->Put(new LittlePony("Steve"));
    tmp->Put(new Teddy("Steve"));
    //...//
    //tmp->Put(new Box("TEST"));
    return tmp;*/
    return NULL;
}

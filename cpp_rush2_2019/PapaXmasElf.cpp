/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** PapaXmasElf.cpp
*/
/*
#include "PapaXmasElf.hpp"
#include "ITable.hpp"

PapaXmasElf::PapaXmasElf(){
    _table = createTable();
    _conveyorBelt = createConveyorBelt();
    _gift = NULL;
}

bool PapaXmasElf::startToWork() {
    while ((this->toyIsAvailable() || this->giftIsAvailable()) && this->checkSpaceOnTable()){
        if(this->giftIsAvailable()){
            makeAGift();
            _conveyorBelt->Put(_gift);
            _conveyorBelt->OUT();
            _gift = NULL;
        } else {
            if (!TakeAWrap())
                return false;
        }
    }
    std::cout << "" <<std::endl; //no time to search for the sentence.
    return true;
}

std::string const PapaXmasElf::getName() const {
    return this->_name;
}

bool PapaXmasElf::boxIsAvailable() {
    if (_conveyorBelt->Look().compare("BOX"))
        return true;
    std::string *tmp = _table->Look();
    for (int i = 0; !tmp[i].empty(); i++){
        if(tmp[i].compare("BOX"))
            return true;
    }
    return false;

}
bool PapaXmasElf::paperIsAvailable() {
        if (_conveyorBelt->Look().compare("GIFTPAPER"))
        return true;
    std::string *tmp = _table->Look();
    for (int i = 0; !tmp[i].empty(); i++){
        if(tmp[i].compare("GIFTPAPER"))
            return true;
    }
    return false;
}
bool PapaXmasElf::toyIsAvailable() {
    if (_conveyorBelt->Look().compare("LITTLEPONY") || _conveyorBelt->Look().compare("TEDDY"))
        return true;
    std::string *tmp = _table->Look();
    for (int i = 0; !tmp[i].empty(); i++){
        if(tmp[i].compare("LITTLEPONY") || _conveyorBelt->Look().compare("TEDDY"))
            return true;
    }
    return false;
}
bool PapaXmasElf::giftIsAvailable() {
    return (toyIsAvailable() && paperIsAvailable() && boxIsAvailable());
}

bool PapaXmasElf::checkSpaceOnTable() {
   /* for (int i = 0; i < 10; i++){
        if (_table[i] == NULL) /// !!!!!
            return true;
    }*//*
    return false;
}

Object * PapaXmasElf::takeToy() {
    for (int i = 0; i < 10; i++){
        //if(_table[i].Look().compare("LITTLEPONY") || _table[i].Look().compare("TEDDY"))  /// !!!!!
        //    return _table[i].Take[i];
    }
    return NULL;
}
Object * PapaXmasElf::takeBox() {
    for (int i = 0; i < 10; i++){
       // if(_table[i].Look().compare("GIFTPAPER")) /// !!!!!
      //      return _table[i].Take[i];
    }
    return NULL;

}
Object * PapaXmasElf::takePaper() {

}

void PapaXmasElf::makeAGift() {
    Object *toy = takeToy();
    Object *box = takeBox();
    Object *paper = takePaper();
    /*box->openMe();
    box->wrapMeThat(toy);
    box->closeMe();
    paper->wrapMeThat(box);
    _gift = paper;

}

bool PapaXmasElf::TakeAWrap() {
    _conveyorBelt->IN();
  if (!_table->Put(_conveyorBelt->Take()))
    return false;
  return true;
}*/
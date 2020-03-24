/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** PapaXmasConveyorBelt.cpp
*/

#include "PapaXmasConveyorBelt.hpp"


PapaXmasConveyorBelt::PapaXmasConveyorBelt(){
    this->_obj = NULL;
}

/*PapaXmasConveyorBelt::~PapaXmasConveyorBelt(){
    this->_obj = NULL;
}*/

Object * PapaXmasConveyorBelt::Take(){
    Object *buf = this->_obj;
    this->_obj =NULL;
    if (buf == NULL)
        std::cerr << "error :Nothing to take!" <<std::endl;
    return buf;

}

bool PapaXmasConveyorBelt::Put(Object *object){
    if(this->_obj == NULL){
        this->_obj = object;
        return true;
    }
    else std::cout << "error :Unfourtunately, there is no more space available on the Conveyor Belt." << std::endl;
    return false;
}

Wrap *PapaXmasConveyorBelt::IN(){
    if (_obj == NULL) {
        std::cout << "error :No object in the ConvoyerBelt" << std::endl;
        return NULL;
    }
    if (_obj->getType() & TOY)
        return new Box();
    if (_obj->getType() & BOX)
        return new GiftPaper();
    return NULL;
}

bool PapaXmasConveyorBelt::OUT(){
    int obj_des_crip = 0;
    int toy_type = 0;
    
    if(_obj){
        if (_obj->getType() & G_PAPER) {
            if (_obj->ret_buff_wrap()->openMe()->getType() & BOX) {
                    toy_type = _obj->ret_buff_wrap()->openMe()->ret_buff_wrap()->openMe()->getType() & TEDDY ? 0 : 1;
                    convert(2, toy_type, _obj->ret_buff_wrap()->openMe()->ret_buff_wrap()->openMe()->getName());
            }
        }else if (_obj->getType() & BOX) {
            toy_type = _obj->ret_buff_wrap()->openMe()->getType() & TEDDY ? 0 : 1;
            convert(1, toy_type, _obj->ret_buff_wrap()->openMe()->getName());
        } else
            convert(0, _obj->getType() & TEDDY ? 0 : 1, _obj->getName());
        _obj = NULL;
        return true;
    }
    std::cout << "error :No object in the ConvoyerBelt" << std::endl;
    return false;
}

std::string const PapaXmasConveyorBelt::Look() const{
    if (this->_obj)
        return this->_obj->getName();
    else
        return "Nothing";
}

IConveyorBelt *createConveyorBelt(){
    return new PapaXmasConveyorBelt;
}
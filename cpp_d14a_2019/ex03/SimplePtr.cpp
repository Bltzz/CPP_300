/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** SimplePtr.cpp
*/

#include "SimplePtr.hpp"


SimplePtr::SimplePtr(BaseComponent *rawPtr){
        this->_rawPtr = rawPtr;
}

SimplePtr::~SimplePtr(){
    delete this->_rawPtr;
}

BaseComponent *SimplePtr::get() const{
    return this->_rawPtr;
}

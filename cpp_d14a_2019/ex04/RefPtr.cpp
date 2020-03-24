/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** RefPtr.cpp
*/
#include "RefPtr.hpp"

RefPtr::RefPtr(BaseComponent *rawPtr){
    this->counter = 0;
    this->_rawPtr = rawPtr;
}

RefPtr::RefPtr(RefPtr const &other){
    this->counter = other.counter + 1;
    this->_rawPtr = other._rawPtr;
}


RefPtr &RefPtr::operator=(RefPtr const &other){
    this->_rawPtr = other._rawPtr;
    this->counter = other.counter + 1;
    return *this;
}

RefPtr::~RefPtr(){
    counter--;
    if (counter == 0 && this->_rawPtr != nullptr)
        delete this->_rawPtr;
}

BaseComponent *RefPtr::get() const{
    return this->_rawPtr;
}
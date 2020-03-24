/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** DomesticKoala.cpp
*/

#include "DomesticKoala.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action) : _action(action), _knownAction(512){}

DomesticKoala::DomesticKoala(const DomesticKoala &tmp) : _action(tmp._action), _knownAction(tmp._knownAction){}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &tmp) {
    this->_action = tmp._action;
    this->_knownAction = tmp._knownAction;
    return *this;
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action){
    _knownAction[command] = action;
}

void DomesticKoala::unlearnAction(unsigned char command){
    this->_knownAction[command] = NULL;
}

void DomesticKoala::doAction(unsigned char command, const std::string &param){
    methodPointer_t tmp = _knownAction[command];
    if (tmp)
        (_action.*tmp)(param);
}

const std::vector<DomesticKoala::methodPointer_t> *DomesticKoala::getActions() const{
    return (&_knownAction);
}

void DomesticKoala::setKoalaAction(KoalaAction &action){
    this->_action = action;
}

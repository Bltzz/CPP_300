/*
** EPITECH PROJECT, 2019
** cpp_d07m_2019
** File description:
** ex00
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(){
    this->_stability = true;
}

void WarpSystem::QuantumReactor::setStability(bool stability){
    this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *coreReactor){
    this->_coreReactor = coreReactor;
}
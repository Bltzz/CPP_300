/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** BaseComponent.cpp
*/

#include <stdexcept>
#include <iostream>
#include "SimplePtr.hpp"
#include "AtmosphereRegulator.hpp"
#include "WaterReclaimer.hpp"


BaseComponent::~BaseComponent()
{}

// int main(){
//     try {
//         // Use  your  auto  delete  here
//         SimplePtr regulator(new AtmosphereRegulator);
//         SimplePtr reclaimer(new WaterReclaimer);
//         // The  code  above  shouldn't be  changed.
//         throw std::runtime_error("An error occured here!");
//     }catch  (std::runtime_error &e) {
//         //std::cerr << e.what() << std::endl;
        
//     }
//     return 0;
// }
#include "BaseComponent.hpp"

#include <exception>
#include <iostream>
#include "RefPtr.hpp"
#include "Oxygenator.hpp"
#include <cassert>


BaseComponent::~BaseComponent()
{
}



int main(){
    try{
        RefPtr oxygenator = new Oxygenator;
        BaseComponent *raw = oxygenator.get();
        RefPtr other(raw);
        RefPtr useless;
        RefPtr lastOne;
        lastOne = other;
        assert(lastOne.get() == raw);
        (void)useless;
        //delete &oxygenator;
        throw std::runtime_error("An error occured here!");
    } catch (std::runtime_error &e) {
        std::cout<< "TEst"<<std::endl;
     }
    return  0;}
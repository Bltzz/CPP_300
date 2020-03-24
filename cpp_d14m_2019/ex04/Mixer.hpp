/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Mixer.hpp
*/
#pragma once
#include "MixerBase.hpp"

class Mixer : public MixerBase {
    public:
        Mixer() : MixerBase() {
            this->_plugged = false;
            this->_mixfunc = nullptr;
        }
        ~Mixer();
        int mix(FruitBox &fruits) const;

        void setPlug(bool plugged) {this->_plugged = plugged;}
        bool isPlugged() const {return this->_plugged;}

    private:

};
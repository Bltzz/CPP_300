/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Event.cpp
*/

#include "Event.hpp"

Event::Event() : time(0), event_name("") {}

Event::Event(unsigned int time, const std::string &event) : time(time), event_name(event) {}

Event::~Event(){}

Event::Event(const Event &other){
    this->time = other.time;
    this->event_name = other.event_name;
}

Event &Event::operator=(const Event &rhs){
    this->time = rhs.time;
    this->event_name = rhs.event_name;
    return *this;
}

unsigned int Event::getTime() const {return this->time;}

const std::string &Event::getEvent() const {return this->event_name;}

void Event::setTime(unsigned int time){
    this->time = time;
}

void Event::setEvent(const std::string &event){
    this->event_name = event;
}

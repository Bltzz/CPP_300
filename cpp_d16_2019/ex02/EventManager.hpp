/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** EventManager.hpp
*/

#pragma once
#include "Event.hpp"
#include <list>
#include <iostream>

class EventManager{
    public:
        EventManager();
        ~EventManager();
        EventManager(EventManager const &other);
        EventManager &operator=(EventManager const &rhs);
        void addEvent(const Event &e);
        void removeEventsAt(unsigned int time);
        void dumpEvents() const;
        void dumpEventAt(unsigned int time) const;
        void addTime(unsigned int time);
        void addEventList(std::list<Event> &events);

        //inline bool check (const Event &event);
        unsigned int getTime() const {return this->_time;}
        std::list<Event> getEvent() const {return event_list;}

    private:
        unsigned int _time;
        std::list<Event> event_list;
};
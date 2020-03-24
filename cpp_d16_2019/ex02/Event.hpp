/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** Event.hpp
*/
#pragma once
#include <iostream>

class Event{
    public:
        Event();
        Event(unsigned int time, const std::string &event);
        ~Event();
        Event(const Event &other);
        Event &operator=(const Event &rhs);
        unsigned int getTime() const;
        const std::string &getEvent() const;
        void setTime(unsigned int time);
        void setEvent(const std::string &event);
    private:
        unsigned int time;
        std::string event_name;
};
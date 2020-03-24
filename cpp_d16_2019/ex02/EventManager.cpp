/*
** EPITECH PROJECT, 2019
** cpp_pool
** File description:
** EventManager.cpp
*/
#include "EventManager.hpp"

//auto it = std::find(l.begin(), l.end(), 16);

EventManager::EventManager(){
    this->event_list = {};
    this->_time = 0;
}

EventManager::~EventManager(){
    event_list.clear();
}

EventManager::EventManager(EventManager const &other){
    if(!event_list.empty())
        event_list.clear();
    this->event_list = other.event_list;
    _time = other._time;
}

EventManager &EventManager::operator=(EventManager const &rhs){
    if(!event_list.empty())
        event_list.clear();
    this->event_list = rhs.event_list;
    _time = rhs._time;
    return *this;
}

inline bool sortTime(const Event &a, const Event &b)
{
    if (a.getTime() <= b.getTime())
        return(true);
    return(false);
}

void EventManager::addEvent(const Event &e){
    event_list.push_back(e);
    event_list.sort(sortTime);
}

void EventManager::removeEventsAt(unsigned int time){
    for (std::list<Event>::const_iterator it = event_list.begin(); it != event_list.end(); it++){
        if (it->getTime() == time){
            it = event_list.erase(it);
            it--;
        }
    }
}

void EventManager::dumpEvents() const{

    for (std::list<Event>::const_iterator it = event_list.begin(); it != event_list.end(); it++){
        std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
    }
}

void EventManager::dumpEventAt(unsigned int time) const{
    for (std::list<Event>::const_iterator it = event_list.begin(); it != event_list.end(); it++){
        if (it->getTime() == time)
            std::cout << it->getTime() << ": " << it->getEvent() << std::endl;
    }
}


// inline bool EventManager::check(const Event &event){
//     return _time > event.getTime();
// }

void EventManager::addTime(unsigned int time){
    // for (Event ev : this->event_list){
    //     if (ev.getTime() > this->_time && ev.getTime() <= (this->getTime() + time)){

    //         //std::cout << ev.getEvent() << std::endl;
    //     }
    // }
     //unsigned int r = _time;
	// event_list.remove_if([r](const Event &event) {
	// 	    return r >= event.getTime();
	// 	});

    _time += time;
    for (auto it = event_list.begin(); it != event_list.end() && it->getTime() <= _time; it++){
        std::cout << it->getEvent() << std::endl;
        it = event_list.erase(it);
        it--;
    }
}

void EventManager::addEventList(std::list<Event> &events){
    //events.merge(event_list);

    for (std::list<Event>::const_iterator it = events.begin(); it != events.end(); ++it){
        if (it->getTime() > _time)
            event_list.push_back(*it);
    }
    event_list.sort(sortTime);
}


/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** GWindow
*/

#ifndef GWindow_HPP_
#define GWindow_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include "Module/Module.hpp"

enum EventType {
    NONE,
    KEYPRESS
};

typedef struct
{
    EventType event_type;
    std::string value;
} GEvent;

class GWindow {
	public:
		GWindow(bool, const std::string &, int, int);
		~GWindow();

        bool operator()();
        void eventHandle();
        void draw(std::vector<Module *> *);

        bool isGraphical() const { return this->_graphical; };
        sf::RenderWindow *getGraphicWindow() const { return this->_sfml_Window; };

        const GEvent &getLastEvent() const { return this->_event; };
	protected:
	private:
        GEvent _event;
        bool _graphical;
        sf::RenderWindow *_sfml_Window;
        bool _moduleEditing = false;
        bool _isOpen = false;
};

#endif /* !GWindow_HPP_ */

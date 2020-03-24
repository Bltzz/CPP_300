/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** GWindow
*/

#include "GWindow.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <X11/Xatom.h>
#include <X11/extensions/shape.h>
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include "../Module/Module.hpp"
#include <unistd.h>
#include <iostream>

bool setTransparency(Window wnd, unsigned char alpha)
{
    Display* display = XOpenDisplay(NULL);
    unsigned long opacity = (0xffffffff / 0xff) * alpha;
    Atom property = XInternAtom(display, "_NET_WM_GWindow_OPACITY", false);

    if (property != None) {
        XChangeProperty(display, wnd, property, XA_CARDINAL, 32, PropModeReplace, (unsigned char*)&opacity, 1);
        XFlush(display);
        XCloseDisplay(display);
        return true;
    } else {
        XCloseDisplay(display);
        return false;
    }
}

GWindow::GWindow(bool graphical, const std::string &title, int width, int height)
{
    this->_graphical = graphical;

    if (graphical) {
        sf::Texture texture;
        sf::Vector2u size;

        this->_sfml_Window = new sf::RenderWindow(sf::VideoMode(width, height), title);
        this->_sfml_Window->setFramerateLimit(60);
        setTransparency(this->_sfml_Window->getSystemHandle(), 210);
    } else {
        initscr();
        noecho();
        curs_set(FALSE);
        keypad(stdscr, TRUE);
        nodelay(stdscr, TRUE);
        _isOpen = true;
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        init_pair(3, COLOR_GREEN, COLOR_GREEN);
        init_pair(4, COLOR_RED, COLOR_RED);
    }
}

GWindow::~GWindow()
{
}

void GWindow::eventHandle()
{
    if (this->_graphical) {
        sf::Event event;

        while (this->_sfml_Window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                this->_sfml_Window->close();
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F12)){
                this->_event.event_type = KEYPRESS;
                this->_event.value = "F12";
            }
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11)){
                this->_event.event_type = KEYPRESS;
                this->_event.value = "F11";
            }
        }
    } else {
        int ch = getch();
        if (ch == 'q') {
            refresh();
            endwin();
            _isOpen = false;
        }
        if (ch == 'm') {
            _moduleEditing = !_moduleEditing;
        }
    }
}

bool GWindow::operator()()
{
    bool ret;

    if (this->_graphical) {
        this->_event.event_type = NONE;
        this->_event.value = "";
        this->_sfml_Window->display();
        ret = this->_sfml_Window->isOpen();
    } else {
        ret = _isOpen;
    }
    this->eventHandle();
    return ret;
}

void GWindow::draw(std::vector<Module *> *modules)
{
    int height = 0;

    if (this->_graphical) {
        this->_sfml_Window->clear(sf::Color(sf::Uint32(0x2c3e50)));
    } else {
        erase();
    }
    std::for_each(modules->begin(), modules->end(), [this, &height](Module *module) {
        module->fillModule();
        if (this->isGraphical()) {
            module->draw(this->getGraphicWindow());
        } else {
            module->setPos(0, height);
            module->draw();
            height += module->getHeight() + 1;
        }
    });
    usleep(100000);
}
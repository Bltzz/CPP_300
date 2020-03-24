/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TextualModule
*/

#include "TextualModule.hpp"
#include <iostream>
#include <ncurses.h>
#include "getInfo.hpp"

TextualModule::TextualModule()
{
    initModule();
}

TextualModule::~TextualModule()
{
}

void TextualModule::fillModule()
{
}

void TextualModule::initModule()
{
    sysStats sys = getSysInfo();
    usrStats usr = {getUsr(), getHost()};
    std::string date = getTime();
    setValues(sys, usr, date);
    _height = 4;
}

void TextualModule::setValues(sysStats sys, usrStats usr, std::string date)
{
    _infos.usr = usr.first;
    _infos.host = usr.second;
    _infos.os = sys.first;
    _infos.kernel = sys.second;
    _infos.date = date;
}

void TextualModule::draw()
{
    mvwprintw(stdscr, getPosY(), getPosX(), "----- User Informations ");
    for (int i = 24; i < COLS; i++) {
        mvwprintw(stdscr, getPosY(), i, "-");
    }
    mvwprintw(stdscr, getPosY() + 1, getPosX() + (COLS / 2) - 10, "%s@%s", _infos.usr.c_str(), _infos.host.c_str());
    mvwprintw(stdscr, getPosY() + 3, getPosX() + (COLS / 5) + 10, "OS: %s", _infos.os.c_str());
    mvwprintw(stdscr, getPosY() + 3, getPosX() + 3 * (COLS / 5), "Kernel version: %s", _infos.kernel.c_str());
    mvwprintw(stdscr, getPosY() + 4, getPosX() + (COLS / 2) - 10, "%s", _infos.date.c_str());
    
}

void TextualModule::initGraphicElements(size_t moduleNb)
{
    (void)moduleNb;
}

void TextualModule::changePos(sf::RenderWindow *win, size_t moduleNb)
{

    int posY = (350 / moduleNb);

    _tile.setPosition(_x, _y);
    for (size_t i = 0; i < 3; i++) {
        sf::Text title = _userInfo.front();
        _userInfo.pop_front();
        title.setPosition(win->getSize().x / 2, _y + posY);
        _userInfo.push_back(title);
        posY += 33;
    };
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y));
}

void TextualModule::initGraphicElements(sf::RenderWindow *win, size_t moduleNb)
{
    std::string tmp;
    _tile = *new sf::RectangleShape(sf::Vector2f(win->getSize().x, win->getSize().y / moduleNb));
    _tile.setOutlineColor(sf::Color::White);
    _tile.setOutlineThickness(1);
    _tile.setFillColor(sf::Color::Transparent);
    _tile.setPosition(_x, _y);
    int posY = (350 / moduleNb);

    _font = *new sf::Font;
    _font.loadFromFile("ressources/Anton.ttf");
    for (size_t i = 0; i < 4; i++) {
        if (i == 0)
            tmp = _infos.usr + "@" + _infos.host;
        else if (i == 1)
            tmp = "OS: " + _infos.os;
        else if (i == 2)
            tmp = "Kernel version: " + _infos.kernel;
        else if (i == 3)
            tmp = "Date: " + _infos.date;
        sf::Text title(tmp, _font, 20);

        title.setOrigin(100, 0);
        title.setPosition(win->getSize().x / 2, _y + posY);
        posY += 33;
        _userInfo.push_back(title);
    };
    _font_title = *new sf::Font;
    _font_title.loadFromFile("ressources/Quicksand.ttf");
    _moduleTitle = *new sf::Text("User Info", _font_title, 30);
    _moduleTitle.setOrigin(_moduleTitle.getLocalBounds().width / 2, 0);
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y + 10));
}

void TextualModule::draw(sf::RenderWindow *win)
{
    win->draw(_tile);
    win->draw(_moduleTitle);
    std::for_each(_userInfo.begin(), _userInfo.end(), [win](sf::Text info){
        win->draw(info);
    });
}

/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** HeapModule
*/

#include "HeapModule.hpp"
#include <iostream>
#include <string>
#include <ncurses.h>
#include "getInfo.hpp"

HeapModule::HeapModule()
{
    fillModule();
}

HeapModule::~HeapModule()
{
}

void HeapModule::fillModule()
{
    std::vector<std::string> heap = getHeap();
    this->setValues(heap);
}

void HeapModule::setValues(std::vector<std::string> &stat)
{
    this->_infos.clear();
    for (size_t i = 0; i < stat.size(); i++) {
        this->_infos.push_back({ atof(stat[i].c_str()) / 1000 });
    }
}

void HeapModule::draw()
{
    mvwprintw(stdscr, getPosY(), getPosX(), "----- Temperature ");
    for (int i = 18; i < COLS; i++) {
        mvwprintw(stdscr, getPosY(), i, "-");
    }
    for (size_t i = 0; i < _infos.size(); i++)
        mvwprintw(stdscr, getPosY() + 2 + i, getPosX() + 5, "temperature 1 : %.1fC", _infos[i].temperature);
    this->_height = _infos.size() + 3;
}

void HeapModule::changePos(sf::RenderWindow *win, size_t moduleNb)
{
    int posY = (350 / moduleNb);

    _tile.setPosition(_x, _y);
    for (size_t i = 0; i < _infos.size(); i++) {
        sf::Text title = _tempCelsius.front();
        _tempCelsius.pop_front();
        title.setPosition(win->getSize().x / 2, _y + posY);
        posY += 33;
        _tempCelsius.push_back(title);
    };
    _moduleTitle.setPosition(sf::Vector2f(win->getSize().x / (moduleNb * 2) + _x, _y));
}

void HeapModule::initGraphicElements(size_t) {}

void HeapModule::initGraphicElements(sf::RenderWindow *win, size_t moduleNb)
{
    std::string tmp;
    int posY = (350 / moduleNb);
    int index = 0;
    int posX = 100;

    _tile = *new sf::RectangleShape(sf::Vector2f(win->getSize().x, win->getSize().y / moduleNb));
    _tile.setOutlineColor(sf::Color::White);
    _tile.setOutlineThickness(1);
    _tile.setFillColor(sf::Color::Transparent);
    _tile.setPosition(_x, _y);
    _font = *new sf::Font;
    _font.loadFromFile("ressources/Anton.ttf");
    for (size_t i = 0; i < _infos.size(); i++) {
        tmp = std::to_string(_infos[i].temperature) + "°c";
        sf::Text title(tmp, _font, 20);
        // title.setOrigin(100, 0);
        title.setPosition(_x + posX, _y + posY);
        if (i != 0 && i % 4 == 0) {
            posX = 100;
            posY += (300 / moduleNb);
        } else {
            posX += win->getSize().x / 8;
        }
        _tempCelsius.push_back(title);
    };
    _font_title = *new sf::Font;
    _font_title.loadFromFile("ressources/Quicksand.ttf");
    _moduleTitle = *new sf::Text("Temperature", _font, 30);
    _moduleTitle.setOrigin(_moduleTitle.getLocalBounds().width / 2, 0);
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y + 10));
}

void HeapModule::draw(sf::RenderWindow *win)
{
    win->draw(_tile);
    win->draw(_moduleTitle);

    std::for_each(_tempCelsius.begin(), _tempCelsius.end(), [win, this](sf::Text Temp){
        win->draw(Temp);
    });
}

/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** MemoryModule
*/

#include "MemoryModule.hpp"
#include <math.h>
#include <ncurses.h>
#include <iostream>
#include "getInfo.hpp"

MemoryModule::MemoryModule()
{
    this->_height = 4;
}

MemoryModule::~MemoryModule()
{
}

void MemoryModule::fillModule()
{
    std::map<std::string, std::string> mem = get_mem_info();
    setValues(mem);
}

void MemoryModule::setValues(std::map<std::string, std::string> &mem)
{
    _infos.memTotal = stoi(mem["MemTotal"]);
    _infos.memFree = stoi(mem["MemFree"]);
    _infos.memUsed = _infos.memTotal - _infos.memFree;
    _infos.swapTotal = stoi(mem["SwapTotal"]);
    _infos.swapFree = stoi(mem["SwapFree"]);
    _infos.swapUsed = _infos.swapTotal - _infos.swapFree;
}

void MemoryModule::draw()
{
    mvwprintw(stdscr, getPosY(), getPosX(), "----- Memory Informations ");
    for (int i = 26; i < COLS; i++) {
        mvwprintw(stdscr, getPosY(), i, "-");
    }
    mvwprintw(stdscr, getPosY() + 2, getPosX() + 5, "Memory used : %d\ttotal : %d", _infos.memUsed, _infos.memTotal);
    mvwprintw(stdscr, getPosY() + 3, getPosX() + 5, "Swap   used : %d\ttotal : %d", _infos.swapUsed, _infos.swapTotal);
}

void MemoryModule::changePos(sf::RenderWindow *win, size_t moduleNb)
{
    int pos = (win->getSize().x / 4);

    _tile.setPosition(_x, _y);
    for (size_t i = 0; i < 2; i++) {
        sf::Text title = _typeNames.front();
        _typeNames.pop_front();
        title.setPosition(sf::Vector2f(_x + pos, win->getSize().y / (moduleNb * 2) + _y));
        _typeNames.push_back(title);

        sf::RectangleShape memBarBack = _usage_backgrounds.front();
        _usage_backgrounds.pop_front();
        memBarBack.setPosition(sf::Vector2f(_x + pos, win->getSize().y / (moduleNb * 2) + _y));
        _usage_backgrounds.push_back(memBarBack);

        sf::RectangleShape memBarFront = _usage_front.front();
        _usage_front.pop_front();
        memBarFront.setPosition(sf::Vector2f(_x + pos - 2, win->getSize().y / (moduleNb * 2) + _y - 2));
        _usage_front.push_back(memBarFront);
        pos += (win->getSize().x / 2);
    }
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y));
}

void MemoryModule::initGraphicElements(size_t moduleNb)
{
    (void)moduleNb;
}

void MemoryModule::initGraphicElements(sf::RenderWindow *win, size_t moduleNb)
{
    int pos = (win->getSize().x / 4);

    _tile = *new sf::RectangleShape(sf::Vector2f(win->getSize().x, win->getSize().y / moduleNb));
    _tile.setOutlineColor(sf::Color::White);
    _tile.setOutlineThickness(1);
    _tile.setFillColor(sf::Color::Transparent);
    _tile.setPosition(_x, _y);
    _font = *new sf::Font;
    _font.loadFromFile("ressources/Anton.ttf");
    for (size_t i = 0; i < 2; i++) {
        sf::RectangleShape memBarBack(sf::Vector2f(_tile.getSize().x / 3, 20));
        memBarBack.setOrigin(sf::Vector2f(memBarBack.getLocalBounds().width / 2, memBarBack.getLocalBounds().height / 2));
        memBarBack.setFillColor(sf::Color::Transparent);
        memBarBack.setOutlineColor(sf::Color::White);
        memBarBack.setOutlineThickness(1.1);
        memBarBack.setPosition(sf::Vector2f(_x + pos, win->getSize().y / (moduleNb * 2) + _y));
        _usage_backgrounds.push_back(memBarBack);
        sf::RectangleShape memBarFront(sf::Vector2f(0, 20));
        memBarFront.setOrigin(sf::Vector2f(memBarBack.getLocalBounds().width / 2, memBarBack.getLocalBounds().height / 2));
        memBarFront.setFillColor(sf::Color(125, 125, 125, 255));
        memBarFront.setFillColor(sf::Color(125, 125, 125, 255));
        memBarFront.setOutlineThickness(1);
        memBarFront.setPosition(sf::Vector2f(_x + pos - 2, win->getSize().y / (moduleNb * 2) + _y - 2));
        _usage_front.push_back(memBarFront);
        sf::Text title(i == 0 ? "mem :" : "swap :", _font, 20);
        title.setOrigin(title.getLocalBounds().width + 10 + memBarBack.getLocalBounds().width / 2, 12);
        title.setPosition(sf::Vector2f(_x + pos, win->getSize().y / (moduleNb * 2) + _y));
        _typeNames.push_back(title);
        pos += (win->getSize().x / 2);
    };
    _font_title = *new sf::Font;
    _font_title.loadFromFile("ressources/Quicksand.ttf");
    _moduleTitle = *new sf::Text("Memory Usage", _font_title, 30);
    _moduleTitle.setOrigin(_moduleTitle.getLocalBounds().width / 2, 0);
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y + 10));
}

void MemoryModule::draw(sf::RenderWindow *win)
{
    win->draw(_tile);
    win->draw(_moduleTitle);
    std::for_each(_typeNames.begin(), _typeNames.end(), [win, this](sf::Text currentNames){
        win->draw(currentNames);
    });
    int it = 0;
    std::for_each(_usage_backgrounds.begin(), _usage_backgrounds.end(), [win, this](sf::RectangleShape memBarBack){
        win->draw(memBarBack);
    });
    std::for_each(_usage_front.begin(), _usage_front.end(), [win, this, &it](sf::RectangleShape memBarFront){
        float value = it == 0 ? (float)((float)_infos.memUsed / (float)_infos.memTotal) : (float)((float)_infos.swapUsed / (float)_infos.swapTotal);
        if (value >= 0.9)
            memBarFront.setFillColor(sf::Color::Red);
        else if (value >= 0.75)
            memBarFront.setFillColor(sf::Color::Yellow);
        else
            memBarFront.setFillColor(sf::Color::Green);
        memBarFront.setSize(sf::Vector2f((value * _tile.getSize().x / 3), 20));
        win->draw(memBarFront);
        it++;
    });
}

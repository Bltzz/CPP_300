/*
** EPITECH PROJECT, 2019
** cpp_rush3_2019
** File description:
** NetworkModule.cpp
*/

#include <ncurses.h>
#include "NetworkModule.hpp"
#include "getInfo.hpp"

NetworkModule::NetworkModule()
{
    initModule();
}

NetworkModule::~NetworkModule(){}

void NetworkModule::draw(){
    int y = getPosY();
    int x = getPosX();

    mvwprintw(stdscr, getPosY(), getPosX(), "----- Network Usage ");
    for (int i = 24; i < COLS; i++) {
        mvwprintw(stdscr, getPosY(), i, "-");
    }
    mvwprintw(stdscr, y++, x, "mode: %s", _infos.type.c_str());
    mvwprintw(stdscr, y++, x, "Reception of Bytes:\t\t%ld", _infos.received_bytes);
    mvwprintw(stdscr, y++, x, "Tansmission of Bytes:\t\t%ld", _infos.transmitted_bytes);
    mvwprintw(stdscr, y++, x, "Reception of Packets:\t\t%ld", _infos.received_packets);
    mvwprintw(stdscr, y++, x, "Transmission of Packets:\t%ld", _infos.transmitted_packets);
}

void NetworkModule::fillModule()
{
}

void NetworkModule::initModule(){
    Stats wifi = getWifiStats();
    Stats eth = getEthernetStats();
    if (wifi[0] == 0)
        setValues(eth, "ethernet");
    else
        setValues(wifi, "wifi");
}

void NetworkModule::setValues(Stats &net, std::string type){
    _infos.inPercent = net[0] - _infos.received_bytes;
    _infos.inPercentPack = net[1] - _infos.received_packets;
    _infos.outPercent = net[3] - _infos.transmitted_bytes;
    _infos.inPercentPack = net[4] - _infos.transmitted_packets;
    _infos.type = type;
    _infos.received_bytes = net[0];
    _infos.received_packets = net[1];
    _infos.received_drops = net[2];
    _infos.transmitted_bytes = net[3];
    _infos.transmitted_packets = net[4];
    _height = 7;
}


void NetworkModule::initGraphicElements(size_t){

}

void NetworkModule::changePos(sf::RenderWindow *win, size_t moduleNb)
{
    int posY = (350 / moduleNb);

    _tile.setPosition(_x, _y);
    for (size_t i = 0; i < 4; i++) {
        sf::Text title = _netInfo.front();
        _netInfo.pop_front();
        title.setPosition(win->getSize().x / 2, _y + posY);
        _netInfo.push_back(title);
        posY += 33;
    };
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y));
}

void NetworkModule::initGraphicElements(sf::RenderWindow *win, size_t moduleNb)
{
    std::string tmp;
    int posY = (350 / moduleNb);

    _tile = *new sf::RectangleShape(sf::Vector2f(win->getSize().x, win->getSize().y / moduleNb));
    _tile.setOutlineColor(sf::Color::White);
    _tile.setOutlineThickness(1);
    _tile.setFillColor(sf::Color::Transparent);
    _tile.setPosition(_x, _y);
    _font = *new sf::Font;
    _font.loadFromFile("ressources/Anton.ttf");
    for (size_t i = 0; i < 4; i++) {
        if (i == 0)
            tmp = "Received Byte: " + std::to_string(_infos.received_bytes);
        else if (i == 1)
            tmp = "Transmitted Bytes: " + std::to_string(_infos.transmitted_bytes);
        else if (i == 2)
            tmp = "Received Packets: " + std::to_string(_infos.received_packets);
        else if (i == 3)
            tmp = "Transmitted Packets: " + std::to_string(_infos.transmitted_packets);
        sf::Text title(tmp, _font, 20);

        title.setOrigin(100, 0);
        title.setPosition(win->getSize().x / 2, _y + posY);
        posY += 33;
        _netInfo.push_back(title);
    };
    _font_title = *new sf::Font;
    _font_title.loadFromFile("ressources/Quicksand.ttf");
    _moduleTitle = *new sf::Text("User Info", _font_title, 30);
    _moduleTitle.setOrigin(_moduleTitle.getLocalBounds().width / 2, 0);
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y + 10));
}

void NetworkModule::draw(sf::RenderWindow *win)
{
    win->draw(_tile);
    win->draw(_moduleTitle);
    std::for_each(_netInfo.begin(), _netInfo.end(), [win](sf::Text info){
        win->draw(info);
    });
}
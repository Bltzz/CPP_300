/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CPUModule
*/

#include "CPUModule.hpp"
#include <iostream>
#include <string>
#include <ncurses.h>
#include "getInfo.hpp"

CPUModule::CPUModule()
{
    std::vector<std::vector<std::string>> test = get_stat_info();
    initValues(test);
}

CPUModule::~CPUModule()
{
}

void CPUModule::initValues(std::vector<std::vector<std::string>> &stat)
{
    size_t i = 0;
    for (; i < stat.size(); i++) {
        CPUModuleInfos add;
        add.usage = 0;
        add.title = stat[i][0];
        add._active_time = get_active_time(stat[i]);
        add._idle_time = get_idle_time(stat[i]);
        _infos.push_back(add);
    }
    _num_CPU = static_cast<int>(stat.size());
    _height = (_num_CPU / 4) * 3 + 4;
}

void CPUModule::fillModule()
{
    std::vector<std::map<std::string, std::string>> cpu = get_cpu_info();
    std::vector<std::vector<std::string>> stat = get_stat_info();
    setValues(cpu, stat);
}

void CPUModule::setValues(std::vector<std::map<std::string, std::string>> &info, std::vector<std::vector<std::string>> &stat)
{
    (void)info;
    for (size_t i = 0; i < stat.size(); i++) {
        _infos[i].model_name = *new std::string(getVal(&info, "model name", i));
        float active = static_cast<float>((float)get_active_time(stat[i]) - (float)_infos[i]._active_time);
        float idle = static_cast<float>((float)get_idle_time(stat[i]) - (float)_infos[i]._idle_time);
        float total = active + idle;
        if (active == 0) {
            break;
        }
        _infos[i].usage = 100.f * (active / total);
        _infos[i]._active_time = get_active_time(stat[i]);
        _infos[i]._idle_time = get_idle_time(stat[i]);
    }
}

void disp_percentage(float f, int x, int y, int count)
{
    int beg = x;
    int width = COLS / count - 7;
    int col = 3;
    if (f == 100)
        col = 4;
    mvwprintw(stdscr, x++, y, "[");
    for (; (x - beg) < width; x++) {
        if (100.f * ((x - beg) / static_cast<float>(width)) <= f) {
            attron(COLOR_PAIR(col));
            printw("|");
            attroff(COLOR_PAIR(col));
        }
        else
            printw(" ");
    }
    printw("]%.1f%%", f);
}

void CPUModule::draw()
{
    mvwprintw(stdscr, getPosY(), getPosX(), "----- CPU Usage ");
    for (int i = 16; i < COLS; i++) {
        mvwprintw(stdscr, getPosY(), i, "-");
    }
    mvwprintw(stdscr, getPosY() + 1, getPosX() + (COLS / 4), "%s : (%s)", _infos[0].title.c_str(), _infos[0].model_name.c_str());
    disp_percentage(_infos[0].usage, getPosY() + 3, getPosX() + (COLS / 4), 2);
    for (int i = 1; i < _num_CPU; ){
        for (int j = 0; j < 4 && i < _num_CPU; j++){
            mvwprintw(stdscr, getPosY() + 3 + (3 * ((i - 1) / 4)) + 2, getPosX() + (COLS / 4) * ((i - 1) % 4), "%s :", _infos[i].title.c_str());
            disp_percentage(_infos[i].usage, getPosY() + 4 + (3 * ((i - 1) / 4)) + 2, getPosX() + (COLS / 4) * ((i - 1) % 4), 4);
            i++;
        }
    }
}

void CPUModule::changeSinglePos(sf::RenderWindow *win, int _x, int _y, int posX, int posY, size_t moduleNb)
{
        sf::Text title =_cpu_names.front();
        _cpu_names.pop_front();
        title.setPosition(sf::Vector2f(_x + posX, win->getSize().y / (moduleNb * 2) + _y + posY));
        _cpu_names.push_back(title);

        sf::RectangleShape cpuBarBack = _usage_backgrounds.front();
        _usage_backgrounds.pop_front();
        cpuBarBack.setPosition(sf::Vector2f(_x + posX, win->getSize().y / (moduleNb * 2) + _y + posY));
        _usage_backgrounds.push_back(cpuBarBack);

        sf::RectangleShape cpuBarFront = _usage_front.front();
        _usage_front.pop_front();
        cpuBarFront.setPosition(sf::Vector2f(_x + posX - 2, win->getSize().y / (moduleNb * 2) + _y + posY - 2));
        _usage_front.push_back(cpuBarFront);
}

void CPUModule::changePos(sf::RenderWindow *win, size_t moduleNb)
{
    int posX = (win->getSize().x / _infos.size()) + 50;
    int index = 0;
    int posY = 10;
    _tile.setPosition(_x, _y);

    moduleNb -= 1;
    this->changeSinglePos(win, _x, _y, win->getSize().x / 2 - ((win->getSize().x / 2 - 200) / 6) , -75, moduleNb);
    std::for_each(_infos.begin() + 1, _infos.end(), [&win, &index, &posX, &posY, moduleNb, this, size = _infos.size()](CPUModuleInfos infos){
        (void)infos;
        this->changeSinglePos(win, _x, _y, posX, posY, moduleNb);
        index++;
        if (index != 0 && index % 4 == 0) {
            posX = (win->getSize().x / size) + 50;
            posY += (100 / moduleNb);
        } else {
            posX += (win->getSize().x / size) + 250;
        }
    });
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y));
}

void CPUModule::initGraphicElements(size_t moduleNb)
{
    (void)moduleNb;
}

void CPUModule::setBar(sf::RenderWindow *win, int _x, int _y, int posX, int posY, size_t moduleNb, sf::Font *_font, CPUModuleInfos *infos)
{
    sf::RectangleShape cpuBarBack(sf::Vector2f(win->getSize().x / 4 - 200, 20));
    cpuBarBack.setFillColor(sf::Color::Transparent);
    cpuBarBack.setOutlineColor(sf::Color::White);
    cpuBarBack.setOutlineThickness(1.1);
    cpuBarBack.setPosition(sf::Vector2f(_x + posX, win->getSize().y / (moduleNb * 2) + _y + posY));
    this->_usage_backgrounds.push_back(cpuBarBack);
    sf::RectangleShape cpuBarFront(sf::Vector2f(0, 20));
    cpuBarFront.setFillColor(sf::Color(125, 125, 125, 255));
    cpuBarFront.setOutlineThickness(0.5);
    cpuBarFront.setPosition(sf::Vector2f(_x + posX - 2, win->getSize().y / (moduleNb * 2) + _y + posY - 2));
    this->_usage_front.push_back(cpuBarFront);
    sf::Text title(infos->title + " :", *_font, 20);
    title.setOrigin(title.getLocalBounds().width + 10, 0);
    title.setPosition(sf::Vector2f(_x + posX, win->getSize().y / (moduleNb * 2) + _y + posY));
    this->_cpu_names.push_back(title);
}

void CPUModule::initGraphicElements(sf::RenderWindow *win, size_t moduleNb)
{
    int posX = (win->getSize().x / _infos.size()) + 50;
    int index = 0;
    int posY = 0;

    _tile = *new sf::RectangleShape(sf::Vector2f(win->getSize().x, win->getSize().y / moduleNb));
    _tile.setOutlineColor(sf::Color::White);
    _tile.setOutlineThickness(1);
    _tile.setFillColor(sf::Color::Transparent);
    _tile.setPosition(_x, _y);

    _font = *new sf::Font;
    _font.loadFromFile("ressources/Anton.ttf");
    this->setBar(win, _x, _y, win->getSize().x / 2 - ((win->getSize().x / 2 - 200) / 6) , -75 , moduleNb, &_font, this->_infos.begin().base());
    std::for_each(_infos.begin() + 1, _infos.end(), [&win, &posX, &posY, moduleNb, &index, this, size = _infos.size()](CPUModuleInfos infos){
        this->setBar(win, _x, _y, posX, posY, moduleNb, &_font, &infos);
        index++;
        if (index != 0 && index % 4 == 0) {
            posX = (win->getSize().x / _infos.size()) + 50;
            posY += (100 / moduleNb);
        } else {
            posX += (win->getSize().x / size) + 250;
        }
    });
    _font_title = *new sf::Font;
    _font_title.loadFromFile("ressources/Quicksand.ttf");
    _moduleTitle = *new sf::Text("CPU Usage", _font_title, 30);
    _moduleTitle.setOrigin(_moduleTitle.getLocalBounds().width / 2, 0);
    _moduleTitle.setPosition(sf::Vector2f(_x + _tile.getSize().x / 2, _y + 10));
}

void CPUModule::draw(sf::RenderWindow *win)
{
    win->draw(_tile);
    win->draw(_moduleTitle);
    std::for_each(_cpu_names.begin(), _cpu_names.end(), [win, this](sf::Text currentNames){
        win->draw(currentNames);
    });
    int it = 0;
    std::for_each(_usage_backgrounds.begin(), _usage_backgrounds.end(), [win, this](sf::RectangleShape cpuBarBack){
        win->draw(cpuBarBack);
    });
    std::for_each(_usage_front.begin(), _usage_front.end(), [win, this, &it](sf::RectangleShape cpuBarFront){
        float value = (_infos[it].usage / 100) * (win->getSize().x / 4 - 200);
        if (_infos[it].usage >= 90)
            cpuBarFront.setFillColor(sf::Color::Red);
        else if (_infos[it].usage >= 75)
            cpuBarFront.setFillColor(sf::Color::Yellow);
        else
            cpuBarFront.setFillColor(sf::Color::Green);
        cpuBarFront.setSize(sf::Vector2f(value, cpuBarFront.getSize().y));
        win->draw(cpuBarFront);
        it++;
    });
}

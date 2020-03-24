/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** getInfo
*/

#ifndef GETINFO_HPP_
#define GETINFO_HPP_

#include <map>
#include "config.hpp"

std::vector<line_t> get_cpu_info();
std::string getVal(std::vector<line_t> *info, const std::string &key, int cpuNumber);
line_t get_mem_info();
std::vector<std::vector<std::string>> get_stat_info();
size_t get_idle_time(std::vector<std::string> &var);
size_t get_active_time(std::vector<std::string> &var);
//heap
std::vector<std::string> getHeap();
//usr host
std::string getUsr();
std::string getHost();
// os, kernel
std::pair<std::string, std::string> getSysInfo();
// wifi stats, ethernet stats
std::vector<size_t> getWifiStats();
std::vector<size_t> getEthernetStats();
// date
std::string getTime();

#endif /* !GETINFO_HPP_ */

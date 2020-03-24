/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** config
*/

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <iostream>
#include <map>
#include <vector>

using config_t = std::map<std::string, std::string>;
using line_t = std::map<std::string, std::string>;

config_t get_config(const std::string &path);
bool check_config(config_t config);

std::vector<std::string> get_disp(std::string toParse);
bool is_disp(std::vector<std::string> disp, std::string str);
line_t apply_config(config_t config);

#endif /* !CONFIG_HPP_ */

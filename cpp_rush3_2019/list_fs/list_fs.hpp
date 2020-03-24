/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** list_files
*/

#ifndef LIST_FILES_HPP_
#define LIST_FILES_HPP_

#include <filesystem>
#include <string>

std::vector<std::string> list_files(const std::string &path);
std::vector<std::string> list_dir(const std::string &path);
std::vector<std::string> list_fs(const std::string &path);

#endif /* !LIST_FILES_HPP_ */

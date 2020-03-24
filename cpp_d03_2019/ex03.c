/*
** EPITECH PROJECT, 2020
** d03_strings
** File description:
** ex03
*/

#include <stddef.h>
#include <string.h>
#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (strlen(this->str) > pos)
        return (this->str[pos]);
    else return (-1);
}

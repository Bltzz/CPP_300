/*
** EPITECH PROJECT, 2020
** d03_strings
** File description:
** ex05
*/

#include "string.h"
#include <string.h>

int size(const string_t *this)
{
    if (this == NULL)
        return (-1);
    else return strlen(this->str);
}

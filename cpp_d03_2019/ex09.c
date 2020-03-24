/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex09
*/

#include <string.h>
#include "string.h"

int empty(const string_t *this)
{
    if (this->str == NULL)
        return 1;
    else return 0;
}

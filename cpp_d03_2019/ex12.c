/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex12
*/

#include "string.h"
#include <string.h>
#include <stdlib.h>

int to_int(const string_t *this)
{
    return (atoi(this->str));
}


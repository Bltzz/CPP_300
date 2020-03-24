/*
** EPITECH PROJECT, 2020
** d03_strings
** File description:
** ex04
*/


#include "string.h"
#include <stdlib.h>
#include <string.h>

void clear(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
    this->str = strdup("");
}



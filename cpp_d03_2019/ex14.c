/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex14
*/

#include <stdio.h>
#include "string.h"

void print(const string_t *this)
{
    if (this->str == NULL)
        return;
    printf("%s", this->str);
}

/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex01
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"

void assign_s(string_t *this , const  string_t *str)
{
    if (str->str == NULL)
        return;
    assign_c(this, str->str);
}

void assign_c(string_t *this , const  char *s)
{
    if (this->str != NULL)
        free(this->str);
    this->str = strdup(s);
}


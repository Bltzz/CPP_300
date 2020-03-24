/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex10
*/


#include "string.h"
#include <string.h>

int find_c(const string_t *this, const char *str, size_t pos);

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return find_c(this, str->str, pos);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    if (this->str && (strlen(this->str) > pos)){
        if (strstr(&this->str[pos], str) != NULL)
            return ((strstr(&this->str[pos], str)) - (this->str));
        }
    return (-1);
}

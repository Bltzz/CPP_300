/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex15
*/

#include <string.h>
#include "string.h"

void join_c(string_t *this, char delim, const char * const *tab)
{
    if (this->str == NULL || tab == NULL)
        return;
    const char tmp_delim = delim;
    strcat(this->str, &tmp_delim);
    strcat(this->str, *tab);
}


void join_s(string_t *this, char delim, const string_t * const *tab)
{
     if (this->str == NULL || (*tab)->str == NULL)
        return;
    const char tmp_delim = delim;
    strcat(this->str, &tmp_delim);
    strcat(this->str, (*tab)->str);
}

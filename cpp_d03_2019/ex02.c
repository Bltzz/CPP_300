/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex03
*/

#include <stdlib.h>
#include <string.h>
#include "string.h"

void append_c(string_t *this, const char *ap);

void append_s(string_t *this, const string_t *ap){
    append_c(this, ap->str);
}

void append_c(string_t *this, const char *ap){
    this->str = realloc(this->str, strlen(this->str) * strlen(ap));
    this->str = strcat(this->str, ap);

}

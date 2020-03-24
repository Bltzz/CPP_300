/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex07
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos){
    size_t counter = 0;

    if (strlen(this->str) > pos)
        return 0;
    for (size_t i = pos; i < n && this->str[i] != '\0'; i++){
        s[i - pos] = this->str[i];
        counter++;
    }
    if (this->str[pos + counter] == '\0')
        s[counter++] = '\0';
    return counter;
}

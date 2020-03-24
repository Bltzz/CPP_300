/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex11
*/

#include "string.h"
#include <string.h>
#include <stdlib.h>

void insert_c(string_t *this , size_t pos , const  char *str){
    size_t len_of_str_to_insert = strlen(str);
    if (strlen(this->str) < pos){
        this->str = strcat(this->str, str);
    } else{
        for (size_t i = pos; i < len_of_str_to_insert; i++){
            this->str[i] = str[i - pos];
        }
    }
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    insert_c(this, pos, str->str);
}

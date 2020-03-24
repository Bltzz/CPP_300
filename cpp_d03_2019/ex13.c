/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex13
*/

#include "string.h"
#include <string.h>
#include <stdlib.h>

string_t **split_s(const string_t *this, char separator)
{
    size_t nbr_of_str = 0;
    static string_t **ptr_to_struct;
    char **temp;

    if (!this || !this->str)
        return NULL;
    temp = split_c(this, separator);
    if (!temp)
        return NULL;
    while (temp[nbr_of_str])
        nbr_of_str++;
    ptr_to_struct = malloc(sizeof(string_t *) * (nbr_of_str + 1));
    if (!ptr_to_struct)
        return NULL;
    for (size_t i = 0; i < nbr_of_str; i++){
        (*ptr_to_struct[i]).str = strdup(temp[i]);
        free(temp[i]);
    }
    free(temp);
    return ptr_to_struct;
}

char **split_c(const string_t *this, char separator)
{
    char Separator[2];
    size_t size_of_array = 0;
    char *temp = strdup(this->str);
    char **arr_of_ptr;
    Separator[0] = separator;
    Separator[1] = '\0';

    if (!this || !this->str)
        return NULL;
    for (size_t i = 0; i < strlen(this->str); i++){
        if (this->str[i] == separator)
            size_of_array++;
        }
    arr_of_ptr = malloc(sizeof(char *) * (size_of_array + 2));
    if (!arr_of_ptr)
        return NULL;
    arr_of_ptr[0] = strdup(strtok(NULL, Separator));
    if (!arr_of_ptr[0])
        return NULL;
    for (size_t j = 0; j < size_of_array + 1; j++){
        arr_of_ptr[j] = strdup(strtok(NULL, Separator));
        if (!arr_of_ptr[j])
            return NULL;
    }
    arr_of_ptr[size_of_array + 1] = NULL;
    free(temp);
    return (arr_of_ptr);
}

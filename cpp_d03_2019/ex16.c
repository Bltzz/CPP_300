/*
** EPITECH PROJECT, 2020
** d03_my_string
** File description:
** ex16
*/

#include <stdio.h>
#include <string.h>
#include "string.h"

string_t *substr(const string_t *this, int offset, int length)
{
    int len_of_current_str = strlen(this->str);
    int checked_offset;
    int counter = 0;
    int i;
    static string_t substr;
    char tmp;

    if (this->str == NULL || offset > len_of_current_str)
        return NULL;
    if (offset < 0)
        checked_offset = len_of_current_str + offset -1;
    else checked_offset = offset;
    if (length > 0){
        tmp = this->str[checked_offset];
        string_init(&substr, &tmp);
        i = checked_offset + 1;
        while((i <= checked_offset + length + 1) && (this->str[i] != '\0')){
            substr.str[i - checked_offset] = this->str[i];
            counter++;
            i +=1;
        }
        if (this->str[counter + checked_offset] == '\0')
            substr.str[counter++] = '\0';
    } else {
        if ((checked_offset + length) >= 0){
            i = checked_offset + length;
            tmp = this->str[i];
            string_init(&substr, &tmp);
            //printf("INIT %s\n", substr.str);
            while ((i <= checked_offset) && (this->str[i] != '\0')){
                substr.str[1 + i - (checked_offset + length)] = this->str[i + 1];
                counter++;
                i++;
            }
        } else {
            tmp = this->str[0];
            string_init(&substr, &tmp);
            while ((i <= checked_offset) && (this->str[i] != '\0')){
                substr.str[i] = this->str[i];
                counter++;
                i++;
            }
        if (this->str[checked_offset] == '\0')
            substr.str[counter++] = '\0';
        }
    }
    return &substr;
}
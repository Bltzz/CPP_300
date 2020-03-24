/*
** EPITECH PROJECT, 2020
** d03_strings
** File description:
** Test Main method
*/
#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string_t this1;
    string_t this;
    string_t assign;
    string_t begin;
    string_t end;

    //const string_t testJoin;
    //string_init(&testJoin, "TestFor Join");
    //char *str = strdup("hello !");
    string_init(&this1, "Servus !");
    clear(&this1);
    printf("CLEAR: %s, %li \n", this1.str, strlen(this1.str));
    string_destroy(&this1);
    string_init(&this, "Jonas12345");
    string_init(&assign, "assign !");
    string_init(&begin, "hello ");
    string_init(&end, "world !");
    /*printf("%s\n", this.str);
    assign_s(&this, &assign);
    printf("assign_s : %s\n", this.str);
    assign_c(&this, "Servus !");
    printf("assign_c : %s\n", this.str);
    append_s(&begin, &end);
    printf("append_s : %s\n", begin.str);
    append_c(&this, " append_c Was geht!");
    printf("assign_c : %s\n", this.str);
    printf("at : %c\n", at(&this, 2));
    printf("compare_s : %d\n", compare_s(&this, &this));
    printf("compare_c : %d\n", compare_c(&this, "nice try"));
    printf("char copied : %d\n", (int) copy(&begin, str, 5, 6));
    printf("c_str : %s\n", c_str(&this));
    printf("is empty? : %d\n", empty(&this));
    printf("find_s pos : %d\n", find_s(&this, &begin, 3));
    printf("find_c pos : %d\n", find_c(&this, "bon", 2));
    insert_c(&this, 2, "bon");
    printf("insert_c : %s\n", this.str);;
    printf("to_int : %d\n", to_int(&this));
    */

    //join_s(&this, '@', &testJoin);
    //printf("JOIN: %s/n", this.str);

    string_t testSubstr;
    string_init(&testSubstr, "");
    //testSubstr = substr(&this, 2, 1);
    //testSubstr = this.substr(&this, 3, 4);
    printf("\n Substring: -- %s --\n", substr(&this, -1, -33)->str);
    string_destroy(&this);
    string_destroy(&assign);
    string_destroy(&begin);
    string_destroy(&end);
    return (0);
}


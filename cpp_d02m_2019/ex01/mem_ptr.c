/*
** EPITECH PROJECT, 2020
** d02_mem_ptr
** File description:
** ex01
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mem_ptr.h"


void  add_str(const  char *str1 , const  char *str2 , char **res);
void  add_str_struct(str_op_t *str_op);

void  add_str(const  char *str1 , const  char *str2 , char **res)
{  
   *res = malloc(sizeof(str1) + sizeof(str2));
    strcat(*res, str1);
    strcat(*res, str2);

}

void  add_str_struct(str_op_t *str_op)
{  
    str_op->res = malloc(sizeof(str_op->str1) + sizeof(str_op->str2));
    strcat(str_op -> res, str_op -> str1);
    strcat(str_op -> res, str_op -> str2);
}

/*
static void test_add_str(void)
{
    char *str1 = "Hey , ";
    char *str2 = "it  works!";
    char *res;
    add_str(str1 , str2 , &res);
    printf("%s\n", res);
}

static void test_add_str_struct(void)
{
    char *str1 = "Hey , ";
    char *str2 = "it  works!";
    str_op_t  str_op;
    str_op.str1 = str1;
    str_op.str2 = str2;
    add_str_struct (& str_op);
    printf("%s\n", str_op.res);
}

int main(void)
{
    test_add_str ();
    test_add_str_struct ();
    return  (0);
}
//end of main
*/

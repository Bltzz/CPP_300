/*
** EPITECH PROJECT, 2020
** d02_func_ptr
** File description:
** ex03
*/

#include <stdio.h>
#include <string.h>
#include "func_ptr.h"

//prototyped methods in func_ptr.h


void  print_normal(const  char *str){
    printf("%s\n", str);
}

void  print_reverse(const  char *str)
{
    
        for(int i = strlen(str); i >= 0; i--){
    	    if(str[i] != '\0'){
	       	printf("%c", str[i]);
            } else printf("\n");
	}
	printf("\n");
}


void  print_upper(const  char *str)
{
  
       for(int i = 0; i < strlen(str); i++){
           if (str[i] >= 'a' && str[i] <= 'z'){
               printf("%c", str[i]-32);
           }
       }
       printf("\n");
}


void  print_42(const  char *str)
{
    printf("%i\n", 42);
}

void  do_action(action_t  action , const  char *str)
{
    void (*funct[])(const char *str) = {&print_normal, &print_reverse, &print_upper, &print_42};
    funct[action](str);
}

int main(void)
{
    const char *str = "I'm using  function  pointers!";
    do_action(PRINT_NORMAL , str);
    do_action(PRINT_REVERSE , str);
    do_action(PRINT_UPPER , str);
    do_action(PRINT_42 , str);
    return (0);
}

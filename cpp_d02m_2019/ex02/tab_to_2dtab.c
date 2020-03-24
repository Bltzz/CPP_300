/*
** EPITECH PROJECT, 2020
** d02_tab_to_2dtab
** File description:
** ex02
*/

#include <stdio.h>
#include <stdlib.h>

void  tab_to_2dtab(const  int *tab , int  length , int width , int  ***res);

void  tab_to_2dtab(const  int *tab , int  length , int width , int  ***res)
{
    *res = malloc(sizeof(int*) * length);
    int counter_for_array = 0;
    for(int i = 0; i < length; i++){
	(*res)[i] = malloc(sizeof(int) * width);
        for(int j = 0; j < width; j++){
	
	   (*res)[i][j] = tab[counter_for_array];
	    counter_for_array++;
	}
    }
}
/* 
 * Begin of main
int  main(void)
{
    int **tab_2d;
    const int tab [42] = {0, 1, 2, 3, 4, 5,6, 7, 8, 9, 10, 11,12, 13, 14, 15, 16, 17,18, 19, 20, 21, 22, 23,24, 25, 26, 27, 28, 29,30, 31, 32, 33, 34, 35,36, 37, 38, 39, 40, 41};
    tab_to_2dtab(tab , 7, 6, &tab_2d);
    printf("tab2[%d][%d] = %d\n", 0, 0, tab_2d[0][0]);
    printf("tab2[%d][%d] = %d\n", 6, 5, tab_2d[6][5]);
    printf("tab2[%d][%d] = %d\n", 4, 4, tab_2d[4][4]);
    printf("tab2[%d][%d] = %d\n", 0, 3, tab_2d[0][3]);
    printf("tab2[%d][%d] = %d\n", 3, 0, tab_2d[3][0]);
    printf("tab2[%d][%d] = %d\n", 4, 2, tab_2d[4][2]);
    return (0);
}
//end of main
*/

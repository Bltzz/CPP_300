/*
** EPITECH PROJECT, 2020
** d02_add_mul_basic_pointers
** File description:
** getting an idea on pointers
*/

#include <stdio.h>

void  add_mul_4param(int first , int  second , int *sum , int *product);
void  add_mul_2param(int *first , int *second);

void  add_mul_4param(int first , int  second , int *sum , int *product)
{
    *sum = first + second;
    *product = first * second;
}

void  add_mul_2param(int *first , int *second)
{
    int tmp_1;
    int tmp_2;

    tmp_1 = *first;
    tmp_2 = *second;

    *first = tmp_1 + tmp_2;
    *second = tmp_1 * tmp_2;
}

/*
//start of testing functions
static  void  test_4_params(void)
{
    int  first = 5;
    int  second = 6;
    int  sum;
    int  product;
    add_mul_4param(first , second , &sum , &product);
    printf("%d + %d = %d\n", first , second , sum);
    printf("%d * %d = %d\n", first , second , product);
}

static  void  test_2_params(void)
{
    int  first = 5;
    int  second = 6;
    int  add_res = first;
    int  mul_res = second;
    add_mul_2param (&add_res , &mul_res);
    printf("%d + %d = %d\n", first , second , add_res);
    printf("%d * %d = %d\n", first , second , mul_res);
}

int  main(void){
    test_4_params ();
    test_2_params ();
    return  (0);
}
//end of main
*/

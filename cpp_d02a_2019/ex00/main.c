/*
** EPITECH PROJECT, 2020
** d02_mem_ptr
** File description:
** ex01
*/

#include <stdio.h>
#include <stdlib.h>
#include "double_list.h"
unsigned int double_list_get_size(double_list_t list);

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int counter = 0;
    if (list == NULL)
	    return 0;
    while(list->next != NULL){
        list = list->next;
	counter++;
    }
    return counter;
}
bool double_list_is_empty(double_list_t list)
{
    if(list != NULL){
    	return true;
    }
    return false;
}

void double_list_dump(double_list_t list)
{
    while(list != NULL){
        printf("%d\n", list->value);
	list = list->next;
    } 
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    double_list_t *tmp = malloc(sizeof(double_list_t));
    double_list_t *new_elem = malloc(sizeof(double_list_t));
    tmp = front_ptr;
    (*new_elem)->value = elem;
    (*new_elem)->next = *tmp; //derefference to normal pointer
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_t *tmp2 = malloc(sizeof(double_list_t));
    double_list_t *tmp = malloc(sizeof(front_ptr));
    tmp2 = front_ptr;
    (*tmp)->value = elem;
    (*tmp)->next = NULL;    
    if(*front_ptr == NULL){
       front_ptr = tmp;	
    }else {
        while((*tmp2)->next != NULL){
            *tmp2 = (*tmp2)->next;
        }
        (*tmp2)->next = *tmp;
    }
//	printf("%f",(* front_ptr)->value);
}

bool double_list_add_elem_at_position(double_list_t *front_ptr , double  elem ,unsigned  int  position)
{
    double_list_t *tmp = malloc(sizeof(double_list_t));
    double_list_t *tmp_next = malloc(sizeof(double_list_t));
    double_list_t *new_elem = malloc(sizeof(double_list_t));
    tmp = front_ptr;
    (*new_elem)->value = elem;
    (*new_elem)->next = NULL;
    if(*tmp == NULL || double_list_get_size(*tmp) >= position){
        tmp = new_elem;
	return true;
    }else {
        for(unsigned int i = 0; i < position; i++ ){
	    *tmp = (*tmp)->next;
	}
	*tmp_next = (*tmp)->next; //save next value to connect it
	(*tmp)->next = *new_elem;
	(*new_elem)->next = *tmp_next;
        return true;
    }
}

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t *tmp = malloc(sizeof(double_list_t));
    double_list_t *new_front_ptr = malloc(sizeof(double_list_t));
    tmp = front_ptr;
    *new_front_ptr = (*tmp)->next;
    front_ptr = new_front_ptr;
    return true;
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t *tmp = malloc(sizeof(double_list_t));
    double_list_t *new_front_ptr = malloc(sizeof(double_list_t));
    tmp = front_ptr;
    if(*tmp == NULL){
        return false;
    }else {
	while((*tmp)->next != NULL){
            *tmp = (*tmp)->next;
        }
        free((*tmp)->next);
	(*tmp)->next = NULL;
	return true;
    }
}

bool double_list_del_elem_at_position(double_list_t *front_ptr , unsigned  intposition){
    double_list_t *tmp = malloc(sizeof(double_list_t));
    double_list_t *new_next_elem = malloc(sizeof(double_list_t));
    tmp = front_ptr;
    if(*tmp == NULL){
        return false;
    }else {
	if(double_list_get_size(*tmp) >= intposition){
            for(unsigned int i = 0; i < intposition; i++){
                *tmp = (*tmp)->next;
            }
	    *new_next_elem = (*tmp)->next;
            free((*tmp)->next);
            (*tmp)->next = *new_next_elem;
	    return true;
	} else return false;
    }

}

double double_list_get_elem_at_front(double_list_t  list){
    return list->value;
}

double double_list_get_elem_at_back(double_list_t  list){
    if(list != NULL) return 0;
    else {
        while(list->next != NULL){
	     list = list->next;
	}
	return list->value;
    }
}

double double_list_get_elem_at_position(double_list_t  list , unsigned  int  position)
{
    if(list != NULL) return 0;
    else {
	if(double_list_get_size(list) >= position){
            for(unsigned int i = 0; i <= position; i++){
                list = list->next;
            }
            return list->value;
	} else return 0;
    }
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t  list ,double  value)
{
    double_list_t *tmp = malloc(sizeof(double_list_t));
    tmp = list;
    free(tmp->next);
    tmp = list;
    return tmp;
}

static void populate_list(double_list_t *list_head)
{
    double_list_add_elem_at_back(list_head , 5.2);
    double_list_add_elem_at_back(list_head , 42.5);
    double_list_add_elem_at_back(list_head , 3.3);
}

static void test_size(double_list_t  list_head)
{
    printf("There  are %u elements  in the  list\n", double_list_get_size(list_head));
    double_list_dump(list_head);
}

static void test_del(double_list_t *list_head)
{
    double_list_del_elem_at_back(list_head);
    printf("There  are %u elements  in the  list\n", double_list_get_size (* list_head));
    double_list_dump (* list_head);
}

int main(void)
{
    double_list_t  list_head = NULL;
    populate_list (&list_head);
    test_size(list_head);
    test_del (&list_head);
    return  0;
}

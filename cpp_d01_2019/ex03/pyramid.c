/*
** EPITECH PROJECT, 2020
** d01_It_must_be_nice_from_up_there
** File description:
** finding the shortest path in a pyramid of numbers
*/

#include <stdio.h>

//prototyped methods:
int get_min_value(int x, int y);
int recursiv_search(int size, const int **map, int x, int y);
int pyramid_path(int size, const int **map);
//end of prototypes
 
//method to return the smaller value (coz 2 possible ways)
int get_min_value(int x, int y)
{
  if (x < y){
    return (x);
  } else return (y);
}

int recursiv_search(int size, const int **map, int x, int y)
{
    if (x == size -1){ //segmentation fault at "== 0", has to be one less than size to check last array and stop there.
    	return (get_min_value(map[x][y], map[x][y + 1])); // return over all shortest path
    } //
    else return (get_min_value(recursiv_search(size, map, x + 1, y), recursiv_search(size, map, x + 1, y + 1)) + map[x][y]);//recrusivly calling itself to check on further paths 
}

//return result of search
int pyramid_path(int size, const int **map)
{
  return (recursiv_search(size, map, 0, 0));
}

/*
int main(void)
{ 
    int size = 4;
    int arr1[] = {0};
    int arr2[] = {7,4};
    int arr3[] = {2,3,6};
    int arr4[] = {8,5,9,3};
    int const *arr[] = {arr1, arr2, arr3, arr4};
    printf("%d\n", pyramid_path(size, arr));
    return 0;
 }
 */

#include <stdlib.h>
#include <unistd.h>
#include "menger.h"


int main(int ac, char **av){
    if (ac == 3)
    {
    	char *one = av[1];
    	char *two = av[2];
   		int how_many_boxes = atoi(one);
    	int nbr_of_recrusion = atoi(two);
    	int x_cord = 0;
    	int y_cord = 0;
    	menger(y_cord, x_cord, nbr_of_recrusion, how_many_boxes);
    	return 0;
    } else {
	write(2,"Please retry", 11);
        return 84;
    }
}

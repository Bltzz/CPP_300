#include <stdio.h>

void menger(int x_cord, int y_cord, int level, int size)
{
    
    if ((size/3) != 1){
    	size = size/3;
    }else size=1;
    printf("%03d %03d %03d\n", size, x_cord+size, y_cord+size);
    while (level > 1 && size > 0){
	//printf("%03d %03d %03d\n", size, x_cord+size, y_cord+size);
	level--;
        menger(x_cord, y_cord, level, size);
        menger(x_cord, y_cord + size, level, size);
        menger(x_cord, y_cord + 2*size, level, size);
        menger(x_cord + size , y_cord, level, size);
        menger(x_cord + size, y_cord + 2 * size, level, size);
        menger(x_cord + 2* size, y_cord, level, size);
        menger(x_cord + 2 * size, y_cord + size, level, size);
        menger(x_cord + 2 * size, y_cord + 2 * size, level, size);
    }
//    printf("%3d %3d %3d\n", size, x_cord, y_cord);
}

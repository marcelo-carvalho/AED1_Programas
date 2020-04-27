#include <stdio.h>
#include <stdlib.h>

int main(){
    int x,y,z;

    x = y = z =8;
    y = pow(y,3);
    x--;
    y = z--;
    z = --y;
    z -= 2;
    y = (x>z?x:z);

    if(z < x)
        printf("%d %d %d %d", x-1, y, z, 1*1);
    else 
        printf("%d %d %d %d", 1*1, z, y, x-2);
}
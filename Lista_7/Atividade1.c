#include <stdio.h>
#include <stdlib.h>

int main(){
    int x,y,z;
    x = y = z = 15;
    y = pow(y,2);

    x--;
    y = z--;
    z = --y;
    z -= 2*4;
    y = (x>z?x:z);

    if(z < x){
        printf("%d %d %d %d", x, y, z, 1*1);
        printf("\nSoma: %d", x + y);
    }
        
    else {
        printf("%d %d %d %d", 1*1, z, y, x);
        printf("\nSoma: %d", 1*1 + z);
    }
    return 0;
}
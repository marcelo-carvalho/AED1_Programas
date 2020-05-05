#include <stdio.h>
#include <stdlib.h>

int func(int x){
    return (3 * pow(x,3) + 2 * pow(x,2) + (x - 5));
}

int main(){
    int vet[10];

    for(int i =0; i < 10; i ++)
        vet[i] = func(i);

    for(int i=0; i < 10; i ++)
        printf("\nvet[%d] = %d", i, vet[i]);
    
    return 0; 
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[10];
    int aux; 

    for(int i = 0; i < 10; i++){
        if (i % 2 == 0)
            vet[i] = 1;
        else
            vet[i] = 0;
    }

    for(int i = 0; i < 10; i++)
        printf("\nvet[%d] = %d", i, vet[i]);

    return 0;
}
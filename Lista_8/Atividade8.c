#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[15];

    for(int i = 0; i < 15; i++){
        vet[i] = rand() % 10;
    }

    puts("Vetor de 15 elementos gerados aleatoreamente:");
     for(int i = 0; i < 15; i++){
        printf("\nVet[%d] = %d", i+1, vet[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[10];

    puts("Informe 10 numeros inteiros:");
    for(int i = 0; i < 10; i++){
        printf("#[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    puts("\nValores compatíveis com o indice do vetor:");
    for(int i = 0; i < 10; i++){
        if(vet[i] == i)
            printf("\nvet[%d] = %d", i, vet[i]);
    }

    return 0;
}
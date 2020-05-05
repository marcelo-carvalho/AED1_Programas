#include <stdio.h>
#include <stdlib.h>


int main(){
    int vet[10];

    puts("Informe 10 numeros inteiros:");
    for(int i = 0; i < 10; i++){
        printf("#[%d]: ", i+1);
        scanf("%d", &vet[i]);
    }

    puts("\nValores informados em ordem reversa");
    for(int i = 9; i >= 0; i--){
        printf("\nVet[%d] = %d", i+1, vet[i]);
    }

    return 0;
}
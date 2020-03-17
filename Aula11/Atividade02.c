#include <stdio.h>
#include <stdlib.h>

int main(){
    int vetor[10], maior = 0;

    //Preenche o vetor com os 10 numeros informados pelo usuário.
    for(int i =0; i < 10; i++){
        printf("Informe um numero: ");
        scanf("%d", &vetor[i]);
    }

    //Calcula o maior deles
    for(int i = 0; i < 10; i++){
        if(vetor[i] > maior)
            maior = vetor[i];
    }

    printf("\nO maior numero eh: %d", maior);
    return 0;
}
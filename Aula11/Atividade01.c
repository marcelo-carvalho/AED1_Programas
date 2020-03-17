#include <stdio.h>
#include <stdlib.h>

//Necessárias para gerar números aleatórios. 
#include <conio.h>
#include <time.h>

int main(){

    int vetor[100];

    srand(time(NULL));

    //Loop para gerar os 100 números aleatórios
    //Os números serão gerados dentro do internvalo (-100 - 100).
    for(int i = 0; i < 100; i++){
        vetor[i] = (rand() % 201) + (-100);
    }

    //Loop para percorrer o intervalo e imprimeir os números positivos
    for(int i = 0; i < 100; i++){
        if(vetor[i] > 0 )
            printf("\nvetor[%i] = %i", i+1, vetor[i]);
    }
    return 0;
}
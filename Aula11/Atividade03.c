#include <stdio.h>
#include <stdlib.h>

//Necessaria para gerar números aleatórios. 
#include <time.h>

int main(){

    int vetor[20];
    int multiplos_2 = 0;
    int multiplos_3 = 0;
    int nao_multiplos_2_5 = 0;

    srand(time(NULL));

    //Loop para gerar os 100 números aleatórios
    //Os números serão gerados dentro do internvalo (0 - 100).
    for(int i = 0; i < 20; i++){
        vetor[i] = (rand() % 101);
    }

    //Os testes são individuais, caso sejam encadeados em ifs else ifs 
    //alguns testes podem deixar de serem realizados e a solução se torna falsa. 
    for(int i = 0; i < 20; i++){
        if(vetor[i] % 2 == 0)
            multiplos_2++;
        
        if(vetor[i] % 3 == 0)
            multiplos_3++;
        
        if(vetor[i] % 2 != 0 || vetor[i] % 5 != 0)
            nao_multiplos_2_5++;
    }

    printf("A quantidade de numeros multiplos de 2: %d", multiplos_2);
    printf("\nA quantidade de numeros multiplos de 3: %d", multiplos_3);
    printf("\nA quantidade de numeros NAO multiplos de 2 ou 5: %d", multiplos_3);

    return 0;
}
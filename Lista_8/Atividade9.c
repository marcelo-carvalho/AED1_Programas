#include <stdio.h>
#include <stdlib.h>

int main(){
    int vet[15];
    int aux = 0;
    int maior;
    int menor;
    int media = 0;
    int abaixoMedia = 0; 
    int i = 0;

    while(i < 15){
        aux = rand() % 100;
        if(aux >= 15 && aux <= 40){
            vet[i] = aux;
            i++;
        }
    }

    maior = vet[0];
    menor = vet[i];
    for(i = 0; i < 15; i++){
        media += vet[i];
        
        if(vet[i] < menor)
            menor = vet[i];

        if(vet[i] > maior)
            maior = vet[i];    
    }

    media = media / 15;

    for(i = 0; i < 15; i++){
        if(vet[i] < media)
            abaixoMedia++;
    }

    printf("Menor temperatura = %d", menor);
    printf("\nMaior temperatura = %d", maior);
    printf("\nTemperatura media = %d", media);
    printf("\nMedidas abaixo da media = %d", abaixoMedia);
}
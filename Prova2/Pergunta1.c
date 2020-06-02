#include <stdio.h>
#include <stdlib.h>

int somaVetores(int vet1[], int vet2[]);

int main(){
    int vet1[] = {12,6,3,90,12};
    int vet2[] = {0,-1,3,9,6,4};
    int vet3[] = {1,2,2,3,5,6,7,8,9,10};
    int vet4[] = {9,8,5,6,9,7,8,6,7,4,2,3,2,1};

    int soma = somaVetores(vet1, vet2);
    printf("A soma dos valores inguais entre os vetores vet1 e vet2 é: %d", soma);

    soma = somaVetores(vet3, vet4);
    printf("\nA soma dos valores inguais entre os vetores vet3 e vet4 é: %d", soma);

    return 1; 
}

int somaVetores(int vet1[], int vet2[]){
    int i, j;
    int soma = 0;

    for(i = 0; i < sizeof(vet1); i++){
        for(j = 0; j < sizeof(vet2); j++){
            if(vet1[i] == vet2[j]){
                soma += vet2[j];
            }
        }
    }
    return soma;
}
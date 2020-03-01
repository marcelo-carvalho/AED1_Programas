#include <stdio.h>

int main(){
    float A=0, B=0;
    
    //Entradas do programa
    printf("Informe dois valores A e B: \n");
    printf("Valor de A: ");
    scanf("%f", &A);
    printf("Valor de B: ");
    scanf("%f", &B);

    //Saidas do programa  
    printf("\nSoma: %f", A + B);
    printf("\nSubtracao: %f", A - B);
    printf("\nMultiplicao: %f", A * B);
    printf("\nDivisao: %f", A/B);

    return 0;
}
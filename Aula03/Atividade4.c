#include <stdio.h>

int main(){
    int numero1 = 0, numero2 = 0;

    printf("Informe dois numeros maiores que zero.\n");
    printf("Primeiro numero: ");
    scanf("%i", &numero1);

    printf("Secundo numero: ");
    scanf("%i", &numero2);

    printf("numero1 elevado numero2 = %f", pow(numero1,numero2));
}
#include <stdio.h>

int main(){
    int numero = 0;

    printf("Informe um numero: ");
    scanf("%i", &numero);

    //condição se par ou impar 
    if(numero % 2 == 0){
        printf("O numero eh par e ");
    }
    else {
        printf("O numero eh impar e ");
    }

    //condicao para positivo ou negativo
    if(numero >= 0){
        printf("positivo");
    }
    else {
        printf("negativo");
    }

    return 0;
}
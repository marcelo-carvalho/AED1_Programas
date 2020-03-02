#include <stdio.h>

int main(){
    int numero;
    
    printf("Informe um numero: ");
    scanf("%i", &numero);

    //Condição para testar se número é par.
    if(numero % 2 == 0){
        printf("O numero eh par e");
    }

    //Condição para testar se número é impar.
    if(numero % 2 != 0){
        printf("O numero eh impar e");
    }

    //Condição para testar se número é positivo.
    if (numero >= 0) {
        printf(" positivo.");
    }

    //Condição para testar se número é negativoo.
    if(numero < 0) {
        printf(" negativo.");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

//Função determina quantos digitos compõe um número informado.
int quantosDigitos(int A){
    int z = 1;

    if(A == 0)
        return 0;
    else if(A < 10)
        return 1;
    else 
        z += quantosDigitos(A / 10);

    return z;
}

int main(){
    int A;

    printf("Informe um numero: ");
    scanf("%d", &A);
    printf("O numero informado possui %d digitos.", quantosDigitos(A));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

//Função soma os digitos que compçoe um dado numero. 
int somaDigitos(int A){
    int z = 0;

    if(A < 10)
        return A;
    else{
        z = A % 10;
        z += somaDigitos(A / 10);
    }
    return z;
}

int main(){
    int A;

    printf("Informe um numero: ");
    scanf("%d", &A);
    printf("A soma dos digitos do numero eh %d.", somaDigitos(A));
    return 0;
}
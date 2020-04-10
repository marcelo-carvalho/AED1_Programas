#include <stdio.h>
#include <stdlib.h>

void lerValores(int*, int*, int*, int*, int*);
void printValores(int*, int*, int*, int*, int*);
void dobraValres(int*, int*, int*, int*, int*);
void inverteValores(int*, int*, int*, int*, int*);
int * menorValor(int*, int*, int*, int*, int*);

int main(){
    int num1, num2, num3, num4, num5;
    lerValores(&num1, &num2, &num3, &num4, &num5);
    
    puts("Valores lidos\n");
    printValores(&num1, &num2, &num3, &num4, &num5);
    puts("========================================================\n");
    
    puts("Valores dobrados\n");
    dobraValres(&num1, &num2, &num3, &num4, &num5);
    printValores(&num1, &num2, &num3, &num4, &num5);
    puts("========================================================\n");
    
    puts("Valores invertidos\n");
    inverteValores(&num1, &num2, &num3, &num4, &num5);
    printValores(&num1, &num2, &num3, &num4, &num5);
    puts("========================================================\n");

    int *menor = menorValor(&num1, &num2, &num3, &num4, &num5);
    printf("O endereco do menor valor eh: %p", menor);

    return 0;
}

void lerValores(int *num1, int *num2, int *num3, int *num4, int *num5){
    printf("Informe 5 numeros: ");
    scanf("%d %d %d %d %d", num1, num2, num3, num4, num5);
}

void printValores(int *num1, int *num2, int *num3, int *num4, int *num5){
    printf("Numero 1 = %d \t | \t Endereco 1 = %p\n", *num1, num1);
    printf("Numero 2 = %d \t | \t Endereco 2 = %p\n", *num2, num2);
    printf("Numero 3 = %d \t | \t Endereco 3 = %p\n", *num3, num3);
    printf("Numero 4 = %d \t | \t Endereco 4 = %p\n", *num4, num4);
    printf("Numero 5 = %d \t | \t Endereco 5 = %p\n", *num5, num5);
}

void dobraValres(int *num1, int *num2, int *num3, int *num4, int *num5){
    *num1 *= 2;
    *num2 *= 2;
    *num3 *= 2;
    *num4 *= 2;
    *num5 *= 2;
}

void inverteValores(int *num1, int *num2, int *num3, int *num4, int *num5){
    int aux;
    
    aux = *num5;
    *num5 = *num1;
    *num1 = aux;
    aux = *num4;
    *num4 = *num2;
    *num2 = aux;
    *num3 = *num3;
}

int * menorValor(int *num1, int *num2, int *num3, int *num4, int *num5){
    if(*num1 < *num2 && *num1 < *num3 && *num1 < *num4 && *num1 < *num5)
        return  num1;
    else if(*num2 < *num1 && *num2 < *num3 && *num2 < *num4 && *num2 < *num5)
        return  num2;
    else if(*num3 < *num1 && *num3 < *num2 && *num3 < *num4 && *num3 < *num5)
        return  num3;
    else if(*num4 < *num1 && *num4 < *num2 && *num4 < *num3 && *num4 < *num5)
        return  num4;
    else if(*num5 < *num1 && *num5 < *num2 && *num5 < *num3 && *num5 < *num4)
        return  num5;
}
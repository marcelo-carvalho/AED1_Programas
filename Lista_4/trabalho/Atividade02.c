//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 4 - Atividade 2

#include <stdio.h>
#include <stdlib.h>

int main(){
    int number = 0; //number informed by user.
    int reverse = 0; //reverse form of number.

    printf("Enter a number to reverse: ");
    scanf("%d", &number);

    while (number != 0)
    {
        reverse = reverse * 10; //shifts the last number one position higher. 
        reverse = reverse + number % 10; //adds the mod to the last position of reverse.
        number = number / 10; //discards the number in last position. 
    }

    printf("Reverse of the number = %d", reverse);

    return 0;
}
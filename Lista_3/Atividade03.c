//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 3 - Atividade 3          

#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 10;
    int sum = 0;

    do{
        printf("%d\n", count);
        sum += count;
        count--;
    } while(count > 0);
    printf("\nThe sum is: %d", sum);
    return 0;
}
//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 3 - Atividade 2                          

#include <stdio.h>
#include <stdlib.h>


int main(){
    int count = 10;
    int sum = 0;

    while(count > 0){
        printf("%d\n", count);
        sum += count;
        count--;
    }
    printf("\nThe sum is: %d", sum);
    return 0;
}
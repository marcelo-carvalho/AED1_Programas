/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 1                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int numero = 0;
    printf("Informe um numero inteiro maior que 0:   ");

    scanf("%d", &numero);

    if(numero > 0) {
        if(numero % 2 == 0){
            printf("\nO numero informado %d eh par.", numero);
        }
        else{
            printf("\nO numero informado %d eh impar.", numero);
        }
    }
    else{
        printf("O numero informado nao eh valido.");
    }
    return 0;
}
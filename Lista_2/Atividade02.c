/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 2                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int senha = 0;
    printf("Informe a senha:");
    scanf("%d", &senha);

    if(senha == 5555){
        printf("\nACESSO PERMITIDO");
    }
    else{
        printf("\nACESSO NEGADO");
    }

    return 0;
}
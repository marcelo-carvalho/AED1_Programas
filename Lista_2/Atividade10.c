/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 10                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    float num =0;
    printf("Informe um numero fracionairio: ");
    scanf("%f", &num);

    //Faz a separação das partes do número. 
    printf("Parte Inteira: %d", (int) num);
    printf("\nParte Decimal: %f", num - (int) num);
    
    return 0;
}
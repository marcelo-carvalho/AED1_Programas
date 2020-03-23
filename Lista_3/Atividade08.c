//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 3 - Atividade 8

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;//number of lines.
    int count = 1; //number of iterations per line.

    printf("Enter the number of lines: ");
    scanf("%d", &n);

    if(n > 0){
        while(count <= n){
            for(int i = 0; i < count; i++){
                printf("*");
            }
            printf("\n");
            count++;//increments the number of iteractions. 
        }
    }
    else{
        printf("Invalid value, please enter a number greater than 0.");
    }
    return 0;
}
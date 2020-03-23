//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 3 - Atividade 11

#include <stdio.h>
#include <stdlib.h>

int main(){
    int stop = -1;
    int n = 0;

    while(stop != 0){
        if(n % 3 == 2){
            if(n % 5 == 3){
                if(n % 7 == 4){
                   printf("N = %d", n);
                   stop = 0;
                }
            }
        }
        n++;
    }
    return 0;
}
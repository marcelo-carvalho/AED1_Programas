//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 4 - Atividade 5

#include <stdlib.h>
#include <stdio.h>

int main(){
    float num = 100;
    float den = 1;
    float sum = 0;
    int n = 0; //while counter

    while(n <21){
        sum += num / den; //acumulator.
        printf("[n(%d)] --- %0.4f = %0.0f / %0.0f \n", n, sum, num, den);
        den = 1;
        //loop to calculate the fatorial. 
        for(int i =1; i<=n; i++){
            den *= i; 
        }
        n++;
        num--;
    }
    return 0;
}
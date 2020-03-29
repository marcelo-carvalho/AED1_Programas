//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 4 - Atividade 4

#include <stdlib.h>
#include <stdio.h>

int main(){
    int num = 1; 
    int den = 15;
    float sum = 0;

    for(int i = 0; i < 15; i++){
        sum += (float) num/(den*den); //Adding the new terms.
        printf("S[%d]' = %d/%d = %0.2f\n",i+1, num, den*den, sum); //Partial results.
        num *= 2;
        den -= 1;
    }

    printf("S = %0.2f", sum); //Final result.
    return 0;
}
/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 4                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    float x = 0, y = 0;
    printf("Informe os pavalores do par ordenado X e Y: ");
    scanf("%f %f", &x, &y);

    if(x > 0 && y > 0){
        printf("\nO par ordenado se encontra no primeiro quadrante.");
    }
    else if (x > 0 && y < 0){
        printf("\nO par ordenado se encontra no segundo quadrante.");
    }
    else if(x < 0 && y < 0){
        printf("\nO par ordenado se encontra no terceiro quadrante.");
    }
    else if (x < 0 && y > 0){
        printf("\nO par ordenado se encontra no quarto quadrante.");
    }
    else{
        printf("\nO ponto se encontra na origem.");
    }

    return 0;
}
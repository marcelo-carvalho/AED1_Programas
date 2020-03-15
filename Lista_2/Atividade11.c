/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 11                          */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    float distancia = 0;
    
    printf("Informe as coordenadas (X Y) do primeiro ponto: ");
    scanf("%f %f", &x1, &y1);
    printf("Informe as coordenadas (X Y) do segunco ponto: ");
    scanf("%f %f", &x2, &y2);

    //calculo da distancia 
    distancia = sqrt(pow(x2 - x1,2) + pow(y2 - y1, 2));

    printf("A distancia entre os pontos eh: %0.4f", distancia);

    return 0;
}
//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 4 - Atividade 7

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    float px1 = 1;
    float py1 = 1;
    float px2 = 1;
    float py2 = 1;
    float distance = 0;

    //Loop to calculate the distance between points.
    while(px1 !=0 && px2 != 0 && py1 !=0 && py2 != 0){
        printf("Please, enter the values of first point x,y: ");
        scanf("%f,%f", &px1, &py1);
        printf("Please, enter the values of second point x,y: ");
        scanf("%f,%f", &px2, &py2);

        distance = sqrt(pow(px2-px1,2) + pow(py2-py1,2)); //Calculates the distance.
        printf("The distance is: %0.2f\n", distance);
    }
    return 0;  
}
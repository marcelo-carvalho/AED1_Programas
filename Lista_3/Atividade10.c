//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 3 - Atividade 10

#include <stdio.h>
#include <stdlib.h>
//Needed to generate radon numbers.
#include <conio.h>


int main(){
    float sum = 0;
    float avg = 0;

       for(int i=0; i < 100; i++){
            sum += (rand() % 101); ///Generates radon nuber between 0-100.
        }
    avg = sum / 100; //Calculates the average.
    printf("The average is: %f", avg);
}
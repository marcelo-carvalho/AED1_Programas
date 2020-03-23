//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 3 - Atividade 7

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    float avg = 0;
    float grade = 0;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);

    if(n != 0){
        for(int i=0; i<n; i++){
            printf("Enter the grade of the student #%d: ", i+1);
            scanf("%f", &grade);
            avg += grade;
        }
        avg = avg/n;
        printf("The student's grade average is: %0.2f", avg);
    }
    return 0;
}
//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 4 - Atividade 1

#include <stdio.h>
#include <stdlib.h>

int main(){
    int ID;
    float hours;
    float hourly;

    printf("Enter the employee's ID: ");
    scanf("%d", &ID);
    printf("Amount of worked hours: ");
    scanf("%f", &hours);
    printf("Hourly wage: ");
    scanf("%f", &hourly);
    
    if(hourly > 0){
        printf("Employee ID %d's wage is: $%0.2f", ID, hours * hourly);
    }
    else{
        printf("Hourly wage should be greater than 0.");
    }
  
    return 0;
}
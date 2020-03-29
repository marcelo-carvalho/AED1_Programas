//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 4 - Atividade 1

#include <stdio.h>
#include <stdlib.h>

int main(){
    int nextNumber = 0;
    int n = 0;
    int first = 0; //first number of the series.
    int second = 1; //second number of the series.

    printf("Enter a number: ");
    scanf("%d", &n); //number of elements the user wish do display.
    
    
    if(n==1){ //when n = 1.
        printf("Fibonacci's serie:\n");
        printf("%d ", first);
    }
    else if(n==2){ //When n = 2.
        printf("Fibonacci's serie:\n");
        printf("%d ", first);
        printf("%d ", second);
    }
    else if(n > 2){ //when n > 2.
        printf("Fibonacci's serie:\n");
        printf("%d ", first);
        printf("%d ", second);
        for(int i=2; i < n; i++){
            nextNumber = first + second; //calculates the next number of the series.
            printf("%d ", nextNumber);
            first = second;
            second = nextNumber;
        }
    }
    else{
        printf("The number must be greater than 0.");
    }
    return 0;
}
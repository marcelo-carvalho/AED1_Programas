//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 4 - Atividade 3

#include <stdlib.h>
#include <stdio.h>

int main(){
    int number = 0;
    int aux = 0;
    int k = 0;
    int count = 0;

    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Enter the position wishied: ");
    scanf("%d", &k);
    
    aux = number;
    
    while (aux != 0)
    {
        aux = aux / 10; //discards the number in last position.
        count++;
    }

    if(k < count){
        count = 0;
        while (count != k)
        {
            aux = number % 10; //takes the number in the last position.
            number = number / 10; //discards the number in last position.
            count++;
        }
        printf("Reverse of the number = %d", aux);
    }
    else{
        printf("The k value is not valid.");
    }
    return 0;
}
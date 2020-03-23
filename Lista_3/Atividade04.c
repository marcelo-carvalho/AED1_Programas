//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 3 - Atividade 4    

#include <stdio.h>
#include <stdlib.h>

int main(){
    int max = 0;
    int min = 0;
    int sum = 0;

    //Algorthm will keep runing until the right values for the interval being entered. 
    while(1){
        printf("Inform the inferior limit: ");
        scanf("%d", &min);
        printf("Inform the superior limit: ");
        scanf("%d", &max);

        //Tests when user enter wrong values for the interval. 
        if(max < min){
            printf("The entered values are not correct. Please enter again.");
        }
        else{
            for(int i = min; i <= max; i++){
                printf("%d\n", i);
                sum += i;
            }
            printf("Sum is: %d", sum);
            return 0;
        }
    }
}
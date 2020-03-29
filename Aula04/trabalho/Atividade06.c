//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 4 - Atividade 6

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
    float num = 0;
    float den = 1; //must be float since int does not fit '17!'
    float exp = 1; // x^0 = 1.
    int n = 1; //while counter.
    float aux = 0;
    float x = 1;

    printf("To solve e^x, please choose a value for x: ");
    scanf("%f", &x);

    //loop to calculate the somatorio.
    do{
        num = pow(x,n);
        den = 1; //den must receive 1 for each iteration.
        //Loop used to calculate the factorial of the numerator. 
        for(int i =1; i<=n; i++){
            den *= i; 
        }
        aux = num/den; //used to control the while loop.
        printf("[n=%d] --- %0.4f = %0.0f / %0.0f \n", n, aux, num, den);
        n++;
        exp += aux; //acumulator
    } while(aux > pow(10,-4));
    
    printf("e^%0.2f = %0.4f", x, exp);
}
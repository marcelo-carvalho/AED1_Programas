/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 1 - Atividade 10                          */

#include <stdio.h>
#include <math.h>

int main(){

    //Declanrando variáveis
    float altura = 0;
    float peso = 0;
    float IMC = 0;

    //Inputs do usuário.
    printf("Informe o seu peso: ");
    scanf("%f", &peso);
    printf("Informe sua altura em metros: ");
    scanf("%f", &altura);

    //Calculo do IMC.
    IMC = peso / pow(altura, 2);

    //Output para o usuário.
    printf("Seu IMC = %0.4f", IMC);

    return 0;
}
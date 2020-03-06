/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 1 - Atividade 8                          */

#include <stdio.h>

int main(){

    //Declarando as variaveis
    float salario_incial = 0;
    float salario_final = 0;
    float percentual_ajuste = 0;

    //Input do usuario
    printf("Inform seu salario atual: ");
    scanf("%f", &salario_incial);
    printf("Inform o percentual de ajuste: ");
    scanf("%f", &percentual_ajuste);

    //calculo do novo salario
    salario_final = (1 + percentual_ajuste/100) * salario_incial;

    //Output pro usuário.
    printf("Seu novo salario = %0.2f", salario_final);

    return 0;
}
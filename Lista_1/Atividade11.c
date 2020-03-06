/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 1 - Atividade 10                          */

#include <stdio.h>

int main() {

    //Declarando variaveis
    float temp_celsius = 0;
    float temp_fahrenheit = 0;

    //Input do usuario
    printf("Informe a temperatura em graus Celsius: ");
    scanf("%f", &temp_celsius);

    //calculo da conversão
    temp_fahrenheit = (temp_celsius * 9/5) + 32;

    //Output para o usuário
    printf("%0.2f graus Celsius = %0.2f graus Fahrenheit", temp_celsius, temp_fahrenheit);

    return 0;    
}
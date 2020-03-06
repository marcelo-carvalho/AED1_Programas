/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 1 - Atividade 6                          */

#include <stdio.h>

    int main(){

        //Declarando as váriaveis
        int km_Inicial = 0, km_Final = 0;
        int consumo = 0;
        float media_consumo =0;

        //input do usuário.
        printf("Informe o Km Inicial: ");
        scanf("%d", &km_Inicial);
        printf("Informe o Km Final: ");
        scanf("%d", &km_Final);
        printf("Informe o consumo em litros: ");
        scanf("%d", &consumo);

        //Calculo da média de consumo
        media_consumo = (km_Final - km_Inicial) / consumo;

        //Outout para o usuário.
        printf("O consumo medio foi %0.2f Km/L.", media_consumo);
       
        return 0;
    }
#include <stdio.h>
#include <stdlib.h>

int main(){
    float massa_incial;
    float massa_restante;
    int tempo, horas, minutos, segundos;
    
    puts("\n================================================================================");
    puts("Este programa calcual o tempo de decaimento de um elemento com meia vida em 50s.");
    puts("Informe a massa inicial (em gramas) do elemento, lhe sera informado quanto tempo ");
    puts("levara para essa massa inicial decair para menos de 0.5g da massa original.");
    puts("Informe a massa incial.");
    scanf("%f", &massa_incial);

    int i = 1; //Numero de iterações determina inicia em 1 
    massa_restante = massa_incial / 2; //Primeira decaida do elemento, explica i começar em 1.
    
    //Determina o número de iterações necessarias para atingir a massa minima
    while(massa_restante >= 0.5){
        massa_restante /= 2;
        i++; //incremeto das iterações. 
    }

    tempo = i * 50; //Calcula o tempo total em segundos 
    horas = (tempo / 3600); //Determina a quantidade de horas
    minutos = (tempo - (3600 * horas)) / 60; //Determina a quantidade de minutos
    segundos = (tempo - (3600 * horas) - (minutos * 60)); //Determina a quantidade de segundos 

    //Saída do programa.
    printf("\nPara decomentos %0.2f g do elemento foram gastos %d:%d:%d (hh:mm:ss).", massa_incial, horas, minutos, segundos);
    return 0;
}
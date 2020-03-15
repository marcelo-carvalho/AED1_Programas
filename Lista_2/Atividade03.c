/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 3                          */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //precisei incluir essa biblioteca pois estou trabalhando com C e não com C++

int main(){
    int dia =0, mes =0, ano =0;
    bool data_valida = false;

    printf("Informe uma data DD/MM/AAAA: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    //verifica se o ano e os meses estão corretamente atribuidos.
    if(ano == 2020){
        if(mes >=1 && mes <= 12)
            data_valida = true;
        else
            data_valida = false;
    }
    else
        data_valida = false;
   
   //verifica se os dias estão corretamente atribuidos.
    if(data_valida){
        if(mes ==1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
            if(dia >= 1 && dia <= 31)
                data_valida = true;
            else
                data_valida = false;
        }
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11 ){
            if(dia >=1 && dia <= 30)
                data_valida = true;
            else
                data_valida = false;
        }
        else if(mes == 2){
            if(dia >=1 && dia <= 29)
                data_valida = true;
            else
                data_valida = false;
        }
        else{
            data_valida = false;
        }
    }
    
    if(data_valida){
        printf("\nData valida!");
    }
    else{
        printf("\nData invalida!");
    }

    return 0;
}

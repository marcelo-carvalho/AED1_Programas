/* Pontíficia Universidade Católica de Minas Gerais
Engenharia de Computação
Algoritmos e Estrutura de Dados 1 
Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
Lista de Exercíciso 2 - Atividade 12                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int quantidade = 0;
    float valor_final = 0;

    printf("Informa a quantidade de parafusos: ");
    scanf("%d", &quantidade);


    if(quantidade <= 0){
        printf("Valor invalido.");
    }
    else{
        if(quantidade > 100 && quantidade <= 200){
            valor_final = quantidade * 0.5;
            printf("\nValor sem desconto = R$%0.2f", valor_final);
            valor_final -= valor_final * 0.1;
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
        else if(quantidade > 200 && quantidade <= 300){
            valor_final = quantidade * 0.5;
            printf("\nValor sem desconto = R$%0.2f", valor_final);
            valor_final -= valor_final * 0.2;
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
        else if(quantidade > 300 && quantidade <= 400){
            valor_final = quantidade * 0.5;
            printf("\nValor sem desconto = R$%0.2f", valor_final);
            valor_final -= valor_final * 0.3;
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
        else if(quantidade > 400) {
            valor_final = quantidade * 0.5;
            printf("\nValor sem desconto = R$%0.2f", valor_final);
            valor_final -= valor_final * 0.4;
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
        else if (quantidade < 100){
            valor_final = quantidade * 0.5;
            printf("\nValor a pagar = R$%0.2f", valor_final);

        }
    }
    return 0;
}
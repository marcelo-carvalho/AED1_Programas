/* Pontíficia Universidade Católica de Minas Gerais
Engenharia de Computação
Algoritmos e Estrutura de Dados 1 
Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
Lista de Exercíciso 2 - Atividade 10                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int quantidade = 0;
    float valor_final = 0;
    int forma_pagamento = 0;

    printf("Informa a quantidade de parafusos: ");
    scanf("%d", &quantidade);


    if(quantidade <= 0){
        printf("Valor invalido.");
    }
    else{

        printf("Informe a forma de pagamento : "
                "\n[1] - Dinheiro"
                "\n[2] - Cartao Debito"
                "\n[3] - Cartao Credito"
                "\n[4] - Boleto - ");
        scanf("%d", &forma_pagamento);

        if(quantidade > 100 && quantidade <= 200){
            valor_final = quantidade * 0.5;
            printf("\nValor sem desconto = R$%0.2f", valor_final);
            valor_final -= valor_final * 0.1; //Desconto pela quantidade.
            
            //Condições de desconto pela forma de pagamento. 
            if(forma_pagamento == 1){
                valor_final -= valor_final * 0.05;
            }
            else if(forma_pagamento == 2){
                valor_final -= valor_final * 0.03;
            }
            else if(forma_pagamento == 3){
                printf("\nValor a pagar = R$%0.2f", valor_final);
                return 0; //Encerra o programa. 
            }
            else if(forma_pagamento == 4){
                valor_final -= valor_final * 0.02;
            }
            else{
                printf("\nForma de pagamento invalida.");
                return 0; //Encerra o programa. 
            }
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
        else if(quantidade > 200 && quantidade <= 300){
            valor_final = quantidade * 0.5;
            printf("\nValor sem desconto = R$%0.2f", valor_final);
            valor_final -= valor_final * 0.2;
            
            //Condições de desconto pela forma de pagamento. 
            if(forma_pagamento == 1){
                valor_final -= valor_final * 0.05;
            }
            else if(forma_pagamento == 2){
                valor_final -= valor_final * 0.03;
            }
            else if(forma_pagamento == 3){
                printf("\nValor a pagar = R$%0.2f", valor_final);
                return 0; //Encerra o programa. 
            }
            else if(forma_pagamento == 4){
                valor_final -= valor_final * 0.02;
            }
            else{
                printf("\nForma de pagamento invalida.");
                return 0; //Encerra o programa. 
            }
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
        else if(quantidade > 300 && quantidade <= 400){
            valor_final = quantidade * 0.5;
            printf("\nValor sem desconto = R$%0.2f", valor_final);
            valor_final -= valor_final * 0.3;
            
            //Condições de desconto pela forma de pagamento. 
            if(forma_pagamento == 1){
                valor_final -= valor_final * 0.05;
            }
            else if(forma_pagamento == 2){
                valor_final -= valor_final * 0.03;
            }
            else if(forma_pagamento == 3){
                printf("\nValor a pagar = R$%0.2f", valor_final);
                return 0; //Encerra o programa. 
            }
            else if(forma_pagamento == 4){
                valor_final -= valor_final * 0.02;
            }
            else{
                printf("\nForma de pagamento invalida.");
                return 0; //Encerra o programa. 
            }
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
        else if(quantidade > 400) {
            valor_final = quantidade * 0.5;
            printf("\nValor sem desconto = R$%0.2f", valor_final);
            valor_final -= valor_final * 0.4;
            
            //Condições de desconto pela forma de pagamento. 
            if(forma_pagamento == 1){
                valor_final -= valor_final * 0.05;
            }
            else if(forma_pagamento == 2){
                valor_final -= valor_final * 0.03;
            }
            else if(forma_pagamento == 3){
                printf("\nValor a pagar = R$%0.2f", valor_final);
                return 0; //Encerra o programa. 
            }
            else if(forma_pagamento == 4){
                valor_final -= valor_final * 0.02;
            }
            else{
                printf("\nForma de pagamento invalida.");
                return 0; //Encerra o programa. 
            }
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
        else if (quantidade < 100){
            valor_final = quantidade * 0.5;

            //Condições de desconto pela forma de pagamento. 
            if(forma_pagamento == 1){
                valor_final -= valor_final * 0.05;
            }
            else if(forma_pagamento == 2){
                valor_final -= valor_final * 0.03;
            }
            else if(forma_pagamento == 3){
                printf("\nValor a pagar = R$%0.2f", valor_final);
                return 0; //Encerra o programa. 
            }
            else if(forma_pagamento == 4){
                valor_final -= valor_final * 0.02;
            }
            else{
                printf("\nForma de pagamento invalida.");
                return 0; //Encerra o programa. 
            }
            printf("\nValor a pagar = R$%0.2f", valor_final);
        }
    }
    return 0;
}
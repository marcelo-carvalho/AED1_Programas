/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 5                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    char caracter = ' ';

    printf("Informe um caracter: ");
    scanf("%c", &caracter);

    if(caracter >= 48 && caracter <= 57){
        printf("\nO caracter eh numero inteiro entre 0 e 9.");
    }
    else if(caracter >= 65 && caracter <= 90){
        printf("\nO caracter eh uma letra maisucula.");
    }
    else if(caracter >= 97 && caracter <= 122 ){
        printf("\nO caracter eh uma letra minuscula.");
    }
    else{
        printf("\nO caracter eh um caracter especial.");
    }
    return 0;
}
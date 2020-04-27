#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main(void){
    char c;
    float v;
    Calc *calc;

    //Cria calculadora com formato de duas casas decimais.
    calc = calc_cria("%0.2f\n");

    do{
        //lê próximo caractere não branco.
        scanf(" %c", &c);

        //verifica se é operador válido.
        if(c == '+' || c == '-' || c == '*'|| c == '/'){
            calc_operador(calc,c);
        }
        //Devolve caracter lido e tenta ler número.
        else{
            ungetc(c,stdin);      
            if(scanf("%f",&v) == 1)
                calc_operando(calc,v);
        }
    }while(c!='q');
    calc_libera(calc);
    return 0;
}
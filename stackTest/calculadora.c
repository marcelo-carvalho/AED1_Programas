#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"

//A função cria recebe como parâmetro de entrada uma cadeia de caracters
//com o formato utilizado pela calculadora para imprimir os valores. Essa
//função cria uma calculadora inicialmente sem operadorandos na pilha. 
Calc* calc_cria(char* formato){
    Calc* c = (Calc *) malloc(sizeof(Calc));
    strcpy(c->f,formato);
    c->p = pilha_cria(); //Cria pilha vazia.
    return c;
}

//A função operando coloca no topo da pilha o valor passado como parâmetro. 
void calc_operando(Calc *c, float v){
    //Empilha operando
    pilha_push(c->p, v);

    //Imprime topo da pilha
    printf(c->f, v);
}

//Retira os dois valores do topo da pilha, efetua a operação correspondente e
//coloca o resultado no topo da pilha. 
void calc_operador(Calc *c, char op){
    float v1, v2, v;

    //desempilha operandos
    if(pilha_vazia(c->p))
        v2 = 0.0;
    else 
        v2 = pilha_pop(c->p);
    if(pilha_vazia(c->p))
        v1 = 0.0;
    else
        v1 = pilha_pop(c->p);

    //Faz a operação
    switch(op){
        case '+': v = v1 + v2; break;
        case '-': v = v1 - v2; break;
        case '*': v = v1 * v2; break;
        case '/': v = v1 / v2; break;
    }

    //Empilha resultado
    pilha_push(c->p,v);

    //Imprime toda a pilha
    printf(c->f,v);
}

//Libera a memoria usad pela calculadora. 
void calc_libera(Calc *c){
    pilha_libera(c->p);
    free(c);
}
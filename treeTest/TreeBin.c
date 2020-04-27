#include <stdio.h>
#include <stdlib.h>
#include "TreeBin.h"

Arv* arv_criavazia(){
    return NULL;
}

Arv* arv_cria(char c, Arv* sae, Arv* sad){
    Arv* p = (Arv*) malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int arv_vazia(Arv* a){
    return a == NULL;
}

void arv_imprime(Arv* a){
    printf("<");
    if(!arv_vazia(a)){
        printf("%c", a->info); //Mostra raiz
        arv_imprime(a->esq); //Mostra sae
        arv_imprime(a->dir); //Mostra sad
    }
    printf(">");
}

Arv* arv_libera(Arv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq); //Libera sae
        arv_libera(a->dir); //Libera sad
        free(a);
    }
    return NULL;
}

int arv_pertence(Arv* a, char c){
    if(arv_vazia(a))
        return 0; //Árvore vazia: não encontrado
    else 
        return a->info == c ||
                arv_pertence(a->esq, c) ||
                arv_pertence(a->dir, c); 
}
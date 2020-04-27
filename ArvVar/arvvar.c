#include <stdio.h>
#include <Stdlib.h>
#include "arvvar.h"

ArvVar* arvvar_cria(char c){
    ArvVar *a = (ArvVar *) malloc(sizeof(ArvVar));
    a->info = c;
    a->prim = NULL;
    a->prox = NULL;
    return a;
}

void arvvar_insere(ArvVar* a, ArvVar* sa){
    sa->prim = a->prim;
    a->prim = sa;
}

void arvvar_imprime(ArvVar* a){
    ArvVar *p;
    printf("<%c\n", a->info);
    for(p=a->prim; p!= NULL; p=p->prox)
        arvvar_imprime(p); //imprime cada sub-árvore filha.
    printf(">");
}

int arvvar_pertence(ArvVar* a, char c){
    ArvVar* p;
    if(a->info == c)
        return 1;
    else {
        for(p=a->prim;p != NULL; p=p->prox){
            if(arvvar_pertence(p,c))
                return 1;
        }
        return 0;
    }
}

void arvvar_libera(ArvVar* a){
    ArvVar* p = a->prim;
    while(p != NULL){
        ArvVar* t = p->prox;
        arvvar_libera(p);
        p = t;
    }
    free(a);
}
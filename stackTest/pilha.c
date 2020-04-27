#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//Função aloca a estrutura da pilha e iniciliza a lista como sendo vazia.
Pilha* pilha_cria(void){
    Pilha* p = (Pilha *) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

//Cada novo elemento é inserido no início da lista.
void pilha_push(Pilha * p, float v){
    Lista* n = (Lista *) malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

//Retira o ultimo elemento adicionado na pilha.
float pilha_pop(Pilha *p){
    Lista *t;
    float v;
    if(pilha_vazia(p)){
        printf("Pilha vazia.\n");
        exit(1); //Aborta programa.
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

//Testa se a pilha está vazia. 
int pilha_vazia(Pilha* p){
    return (p->prim==NULL);
}

//Libera a pilha devolvndo a memória usada.
void pilha_libera(Pilha* p){
    Lista* q = p->prim;
    while(q!=NULL) {
        Lista * t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

//Imprime conteúdo da pilha
void pilha_iprime(Pilha * p){
    Lista *q;
    for(q=p->prim; q!=NULL; q=q->prox)
        printf("%f\n",q->info);
}
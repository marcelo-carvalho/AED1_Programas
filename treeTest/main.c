#include <stdio.h>
#include <stdlib.h>
#include "TreeBin.h"

int main(){
    Arv * a = arv_cria('a',
            arv_cria('b',
                arv_criavazia(),
                arv_cria('d', arv_criavazia(), arv_criavazia())
            ),
            arv_cria('c',
                arv_cria('e', arv_criavazia(), arv_criavazia()),
                arv_cria('f', arv_criavazia(), arv_criavazia())
            )
        );
    arv_imprime(a);

    a->esq = arv_cria('x',
                arv_cria('y', arv_criavazia(), arv_criavazia()),
                arv_cria('z', arv_criavazia(), arv_criavazia())
            );
    printf("\n");
    arv_imprime(a);

    a->dir->esq = arv_libera(a->dir->esq);
    printf("\n");
    arv_imprime(a);
}
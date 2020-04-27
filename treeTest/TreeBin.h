#include <stdio.h>
#include <stdlib.h>

struct arv{
    char info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

Arv* arv_criavazia();
Arv* arv_cria(char c, Arv* sae, Arv* sad);
int arv_vazia(Arv* a);
void arv_imprime(Arv* a);
Arv* arv_libera(Arv* a);
int arv_pertence(Arv* a, char c);
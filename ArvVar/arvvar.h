struct arvvar {
    char info;
    struct arvvar *prim; //ponteiro para eventual primeiro filho
    struct arvvar *prox; //ponteiro para eventual irmão 
};

typedef struct arvvar ArvVar;

ArvVar* arvvar_cria(char c);
void arvvar_insere(ArvVar* a, ArvVar* sa);
void arvvar_imprime(ArvVar* a);
int arvvar_pertence(ArvVar* a, char c);
void arvvar_libera(ArvVar* a);
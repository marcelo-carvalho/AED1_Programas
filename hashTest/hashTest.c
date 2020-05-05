
#include "hashTest.h"

int le_palavra(FILE* fp, char* s){
    int i = 0;
    int c;

    //Pula caracters que não são letras
    while((c = fgetc(fp)) != EOF) {
        if(isalpha(c))
            break;
    }

    if(c == EOF)
        return 0;
    else 
        s[i++] = c; //Primeira letra já foi capturada

    //Lê os próximas caracteres que são letras
    while (i < NPAL-1 && (c = fgetc(fp)) != EOF && isalpha(c)){
        s[i++] = c;
    }
    s[i] = '\0';
    return 1;
}

void inicializa (Hash tab){
    int i;
    for(i = 0; i < NTAB; i++)
        tab[i] = NULL;
}

int hash (char* s){
    int i;
    int total = 0;
    for(i = 0; s[i] != '\0'; i++)
        total += s[i];
    
    return total % NTAB;
}

Palavra* acessa (Hash tab, char* s){
    Palavra* p;
    int h = hash(s);
    for(p=tab[h]; p != NULL; p = p->prox){
        if(strcmp(p->pal, s) == 0)
            return p;
    }

    //Insere nova palavra no inicio da lista
    p = (Palavra*) malloc(sizeof(Palavra));
    strcpy(p->pal,s);
    p->n = 0;
    p->prox = tab[h];
    tab[h] = p;
    return p;
}

int conta_elems(Hash tab){
    int i;
    int total = 0;
    Palavra *p;
    for(i=0; i < NTAB; i++){
        for(p=tab[i]; p != NULL; p=p->prox)
            total++;
    }
    return total;
}

Palavra** cria_vetor(int n, Hash tab){
    int i, j =0;
    Palavra *p;
    Palavra **vet = (Palavra**) malloc (n*sizeof(Palavra*));

    //Percorre tobela preenchendo vetor
    for(i=0; i < NTAB; i++){
        for(p=tab[i]; p != NULL; p=p->prox)
            vet[j++] = p;
    }
    return vet;
}

int compara (const void* v1, const void* v2){
    Palavra** p1 = (Palavra**)v1;
    Palavra** p2 = (Palavra**)v2;

    if((*p1)->n > (*p2)->n) return -1;
    else if ((*p1)->n < (*p2)->n) return 1;
    else return strcmp((*p1)->pal,(*p2)->pal);
}

void imprime (Hash tab){
    int i;
    int n;
    Palavra** vet;

    //Cria e ordena o vetor
    n = conta_elems(tab);
    vet = cria_vetor(n, tab);
    qsort(vet,n,sizeof(Palavra*), compara);

    //Imprime ocorrências 
    for(i=0; i<n; i++){
        printf("%s = %d\n", vet[i]->pal, vet[i]->n);
    }

    //Libera vetor
    free(vet);
}
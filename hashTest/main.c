#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "hashTest.h"

int main(int argc, char** argv){
    FILE *fp;
    Hash tab;
    char s[NPAL];

    if(argc != 2){
        printf("Arquivo de entrada nao fornecido.\n");
        return 0;
    }

    //Abre arquivo para leitura
    fp = fopen(argv[1], "rt");
    if(fp == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return 0;
    }

    //conta ocorrência das palavras
    inicializa(tab);
    while(le_palavra(fp,s)){
        Palavra* p = acessa(tab,s);
        p->n++;
    }

    //Imprime ordenado
    imprime(tab);

    return 0;
}


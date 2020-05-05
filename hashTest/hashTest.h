#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NPAL 64 //Dimensão máxima de cada palavra
#define NTAB 127 //Dimensão da tabela de dispersão

//Tipo que representa cada palavra
struct palavra {
    char pal[NPAL];
    int n;
    struct palavra* prox; //tratamento de colisão com listas
};
typedef struct palavra Palavra;

//Tipo que representa a tabela de dispersão
typedef Palavra* Hash[NTAB];

//Função para leitura de palavras
int le_palavra(FILE* fp, char* s);

//Inicializa a tabela de dispersão
void inicializa (Hash tab);

//Função para mapear a chave de busca
int hash (char* s);

//Função para acessar os elementos na tabela.
//Caso não exista o elemento este é criado pela função. 
Palavra* acessa (Hash tab, char* s);

//Função para contar o número de palavras armazenadas
int conta_elems(Hash tab);

//Função para criar dinamicamente vetor de ponteiros.
Palavra** cria_vetor(int n, Hash tab);

//Função de comparação usada pela função qsort
int compara (const void* v1, const void* v2);

//Função para imprimir os resultados
void imprime (Hash tab);
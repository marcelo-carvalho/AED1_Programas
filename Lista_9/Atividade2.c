#include <stdio.h>
#include <stdlib.h>

#define N 10 //Constante para limitar o tamanho dos vetores em 10 elementos.

//Função apra encontrar o maior valor de um vetor
//Entrada:
//          *max -> ponteiro onde sera armazenado o maior valor (recomenda-se inicializalo em 0).
//          *vet -> vetor o qual se deseja encontrar o maior valor
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void maximo(int *max, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        return;
    
    if(*max < vet[elem])
        *max = vet[elem];
    maximo(max, vet, ++elem);
}

//Procedimento para preencher um vetor com valores inteiros aleatorios. 
//Entrada:
//          vet -> ponteiro do vetor que se deseja preencher. 
//Como o vetor é passado por referência não existem saídas.
void setVetor(int *vet){
    for(int i = 0; i < N; i++)
        vet[i] = rand() % 100;

    //vet[5] = 3;   //Instrução criada para forçar condição verdadeira. 
}

int main(){
    int vet[N];
    int max = 0;

    setVetor(vet);
    maximo(&max,vet,0);

    printf("Maximo = %d", max);

    for(int i =0; i < N; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
    
    return 0;
}
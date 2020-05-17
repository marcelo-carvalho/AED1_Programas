#include <stdio.h>
#include <stdlib.h>

#define N 10 //Constante para limitar o tamanho dos vetores em 10 elementos.

//Função para fazer a soma dos valores de um vetor
//Entrada:
//          *prod -> ponteiro onde sera armazenado o valor do produto (recomenda-se inicializalo em 1).
//          *vet -> vetor o qual se deseja encontrar o produto
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void produto(int *prod, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        return;
    
    *prod *= vet[elem];
    produto(prod, vet, ++elem);
}

//Procedimento para preencher um vetor com valores inteiros aleatorios. 
//Entrada:
//          vet -> ponteiro do vetor que se deseja preencher. 
//Como o vetor é passado por referência não existem saídas.
void setVetor(int *vet){
    for(int i = 0; i < N; i++)
        vet[i] = rand() % 11;

}

int main(){
    int vet[N];
    int prod = 1;

    setVetor(vet);
    produto(&prod,vet,0);

    printf("Produto = %d\n", prod);

    for(int i =0; i < N; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
    
    return 0;
}
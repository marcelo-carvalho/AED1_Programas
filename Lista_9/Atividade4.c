#include <stdio.h>
#include <stdlib.h>

#define N 10 //Constante para limitar o tamanho dos vetores em 10 elementos.

//Função para fazer a soma dos valores de um vetor
//Entrada:
//          *sum -> ponteiro onde sera armazenado o valor da soma (recomenda-se inicializalo em 0).
//          *vet -> vetor o qual se deseja encontrar o menor valor
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void soma(int *sum, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        return;
    
    *sum += vet[elem];
    soma(sum, vet, ++elem);
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
    int sum = 0;

    setVetor(vet);
    soma(&sum,vet,0);

    printf("Soma = %d\n", sum);

    for(int i =0; i < N; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
    
    return 0;
}
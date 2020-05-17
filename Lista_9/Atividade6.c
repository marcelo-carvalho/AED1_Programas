#include <stdio.h>
#include <stdlib.h>

#define N 10 //Constante para limitar o tamanho dos vetores em 10 elementos.

//Função para encontrar a media dos valores de um vetor
//Entrada:
//          *med -> ponteiro onde sera armazenado o valor da media (recomenda-se inicializalo em 0).
//          *vet -> vetor o qual se deseja encontrar o menor valor
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void media(float *med, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        *med = *med/N;
    else{
        *med += vet[elem];
        media(med, vet, ++elem);
    }
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
    float med = 0;

    setVetor(vet);
    media(&med,vet,0);

    printf("Media = %f\n", med);

    for(int i =0; i < N; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
    
    return 0;
}
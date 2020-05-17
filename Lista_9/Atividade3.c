#include <stdio.h>
#include <stdlib.h>

#define N 10 //Constante para limitar o tamanho dos vetores em 10 elementos.


//Função apra encontrar o menor valor de um vetor
//Entrada:
//          *min -> ponteiro onde sera armazenado o menor valor (recomenda-se inicializalo em 999).
//          *vet -> vetor o qual se deseja encontrar o menor valor
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void minimo(int *min, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        return;
    
    if(*min > vet[elem])
        *min = vet[elem];
    minimo(min, vet, ++elem);
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
    int min = 999;

    setVetor(vet);
    minimo(&min,vet,0);

    printf("Minimo = %d\n", min);

    for(int i =0; i < N; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
    
    return 0;
}
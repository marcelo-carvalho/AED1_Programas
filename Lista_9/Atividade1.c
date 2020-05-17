#include <stdio.h>
#include <stdlib.h>

#define N 10 //Constante para limitar o tamanho dos vetores em 10 elementos. 

//Função recursiva para localizar valor k em um vetor.
//Entradas:
//          k -> valor buscado.
//          vet -> ponteiro do vetor onde se deseja buscar o elemento.
//          elem -> posição inicial do vetor (recomenda-se 0).
//Saidas:
//          elem -> caso valor buscado seja econtrado a posição deste no vetor é retornada.
//          -1 -> caso valor buscado não seja encontrado. 
int busca(int k, int *vet, int elem){
    if(elem >= N)           //Primeira prosição sempre sera a condição de parada da recursão.  
        return -1;
    else if(k == vet[elem]) //Condição para valor encontrado.
        return elem;        
    else                    //Entrada da recursão sempre na ultima condição.
        return busca(k,vet,++elem);    
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

    setVetor(vet);

    int b = busca(3,vet,0);

    if(b != -1)
        printf("\nValor na posicao %d", b);
    else
        printf("\nValor nao encontrando.");

    for(int i =0; i < N; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void bolha (int n, int *v);
void bolha2(int n, int *v);
void bolha_rec(int n, int *v);

int main(){
    int i;
    int v[8] = {25,48,37,12,57,86,33,92};
    bolha_rec(8,v);
    printf("Vetor ordenado: ");
    for(i=0; i<8; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}

void bolha(int n, int *v){
    int j,i;

    for(i=n-1; i>-1; i--){
        for(j=0;j<i; j++){
            if(v[j]>v[j+1]){
                int temp = v[j];    //troca
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

//Esse algoritmo é melhorado uma vez que ele interrompe o processo, se 
//nenhuma troca foi realizada durante a itereação. 
void bolha2(int n, int *v){
    int j,i;

    for(i=n-1; i>-1; i--){
        int troca = 0;
        for(j=0;j<i; j++){
            if(v[j]>v[j+1]){
                int temp = v[j];    //troca
                v[j] = v[j+1];
                v[j+1] = temp;
                troca = 1;
            }
        }
        if(troca == 0) //Não houve troca
            return;
    }
}

//Algoritmo de ordenação bolha utilizando recursividade
void bolha_rec(int n, int *v){
    int j;
    int troca = 0;
    for(j=0;j<n-1;j++){
        if(v[j] > v[j+1]){
            int temp = v[j]; // troca
            v[j] = v[j+1];
            v[j+1] = temp;
            troca = 1;
        }
    }
    if(troca != 0) //houve troca
        bolha_rec(n-1,v);
}
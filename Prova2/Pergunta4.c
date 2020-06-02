#include <stdio.h>
#include <stdlib.h>


int inverte(int z[], int posi);

int main(){
    int tamanho, i;
    int v1[] = {10,30,40,50,90,20};
    int v2[] = {50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};
    int v3[5]; 
    
    tamanho = sizeof(v1) / sizeof(int);
    printf("\nVetor 1:");
    inverte(v1, tamanho - 1);

    tamanho = sizeof(v2) / sizeof(int);
    printf("\nVetor 2:");
    inverte(v2, tamanho - 1);

    printf("\nAGora informe 5 valores para o vetor:");
    for(i = 0; i < 5; i++){
        printf("v[%d] = ", i +1);
        scanf("%d%*c", &v3[i]);
    }

    printf("\nVetor 3:");
    inverte(v3, 4);

    return 1;
}

int inverte(int z[], int posi){
    if(posi < 0)
        return;
    
    if(posi % 2 != 0)
        printf("\tV[%d] = %d", posi, z[posi]);
    
    inverte(z, posi-1);
}
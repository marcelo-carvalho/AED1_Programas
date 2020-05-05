#include <stdio.h>
#include <stdlib.h>

//função de compração de reais
static int comp_reais(const void* p1, const void* p2){
    //converte ponteiros genericos para ponteiros de float
    float *f1 = (float *) p1;
    float *f2 = (float *) p2;
    //dados os ponteiros de float, faz a comparação
    if(*f1 < *f2) return -1;
    else if(*f1 > *f2) return 1;
    else return 0;
}

int main(void){
    int i;
    float v[8] = {25.6, 48.3, 37.7, 12.7, 57.4, 86.6, 33.3, 92.8};
    qsort(v,8,sizeof(float),comp_reais);

    printf("Vetor ordenado: ");
    for(i=0;i<8;i++)
        printf("%g ",v[i]);
    printf("\n");
    return 0;
}
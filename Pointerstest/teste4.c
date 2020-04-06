#include <stdio.h>
#include <stdlib.h>

int main(){
    static int M[5] = {92,81,70,69,58};
    int *p = M; //Cria e inicializa o ponteiro variável

    for(int i=0;i<5;i++)
        printf("%d\n", *(p++)); //Notação ponteiro

    return 0;
}
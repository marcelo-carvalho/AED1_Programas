#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){
    if(n == 0 )
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int vet[30];
    int i;
    puts("Vetor foi reduzido pra 30 posicoes para nao ocorrer overload de memoria...");
    for(i=0; i < 30; i++)
        vet[i] = fibonacci(i);

    for(i = 0; i < 30; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
    
    return 0;
}
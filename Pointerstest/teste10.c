#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pi;

    pi = (int *) malloc(sizeof(int));

    puts("Digite um numero: ");
    scanf("%d", pi);
    printf("\nVoce digitou o numero: %d\n", *pi);

    free(pi);

    return 0;
}

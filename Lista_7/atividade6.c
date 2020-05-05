#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int k, n = 4;
    puts("\n================================================================================");
    puts("Programa para determinar valor de n tal que K^n > n^k para um dado k.");
    printf("Informe um valor para k: ");
    scanf("%d", &k);

    //Garante que k seja sempre > 1
    while(k <= 1){
        printf("\nO valor informa deve ser > 1, informe novo valor: ");
        scanf("%d", &k);
    }

    n = k; //Garante um valor inicial para n > 1 e reduz número de iterações.
    achaN(&k, &n);

    printf("\nN = %d", n);

    return 0;
}

//Procedimento usado para calcular K^n > n^k.
void achaN(int *k, int *n){
    while(1){
        if(pow(*k,*n) > pow(*n,*k))
            break;
        *n = *n + 1;
    }
}
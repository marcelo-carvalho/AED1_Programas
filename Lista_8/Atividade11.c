#include <stdio.h>
#include <stdlib.h>

int testaNumero(int *n){
    if(*n > 9){
        puts("Valor deve ser menor que 9...");
        printf("Informe novo valor: ");
        scanf("%d", n);
        testaNumero(n);
    }
    else if (*n < 0){
        puts("Valor deve ser maior que 0...");
        printf("Informe novo valor: ");
        scanf("%d", n);
        testaNumero(n);
    }
    else 
        return 1;
}

int main(){
    int freq[10] = {0,0,0,0,0,0,0,0,0,0};
    int i, index;

    for (i = 0; i < 10; i++){
        printf("#%d: Digite um numero entre 0 e 9: ", i);
        scanf("%d", &index);
        if(testaNumero(&index))
            freq[index]++;
    }

    for(i = 0; i < 10; i++){
        printf("\n%d apareceu %d vezes", i, freq[i]);
    }
    return 0;
}
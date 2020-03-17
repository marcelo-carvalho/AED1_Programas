#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 0, fatorial = 1;

    printf("Informe um numero inteiro maior que zero: ");
    scanf("%d", &num);

    if(num == 0){
        fatorial = 1;
    }
    else if (num < 0){
        printf("\nValor invalido.");
        return 0;
    }
    else {
        for(int i = num; i > 0; i--){
            fatorial *= i;
        }
    }

    printf("\nO fatorial de %d eh: %d", num, fatorial);
    return 0;
}
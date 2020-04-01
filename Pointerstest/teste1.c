#include <stdio.h>
#include <stdlib.h>

void reajusta20(float *, float*);

int main(){
    float val_preco, val_reaj;
    do{
        printf("\nInsira o preço atual: ");
        scanf("%f", &val_preco);
        reajusta20(&val_preco, &val_reaj);
        printf("\nO preco novo eh %.2f\n", val_preco);
        printf("O aumento foi de %.2f\n", val_reaj);

    }while(val_preco != 0.0);
    return 0;
}

void reajusta20(float *preco, float *reajuste){
    *reajuste = *preco * 0.2;
    *preco *= 1.2;
}
#include <stdio.h>

int main(){
    float base=0, altura=0;

    //Entradas do programa
    printf("Informe os valores de Base e Altura do triangulo: \n");
    printf("Valor da Base: ");
    scanf("%f", &base);
    printf("Valor da Altura: ");
    scanf("%f", &altura);
    
    //Saida do programa
    printf("A area do triangula e %f", (base*altura)/2);

    return 0;
}
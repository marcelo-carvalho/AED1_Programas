#include <stdio.h>

int main(){
    //inicializado as variáveis 
    float b = 0;
    float h = 0;
    float area_triangulo = 0;

    printf("Este programa calcula area de um triangulo, baseado dois dados de entrada:\n");
    printf(" b = base e h = altura.\n");
    printf("Entre o valor de b: ");
    scanf("%f", &b);
    
    printf("Entre o valor de h: ");
    scanf("%f", &h);
    printf("\n");

    //Calculo da área do triângulo
    area_triangulo = (b * h)/2;

    printf("A area do triangulo e igual a %f\n", area_triangulo);
    
    return 0;
}
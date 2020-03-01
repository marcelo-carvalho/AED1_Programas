#include <stdio.h>

#define PI 3.1415

int main(){
    float raio=0, area_circulo=0;

    //Entrada do programa
    printf("Informe o raio do circulo: ");
    scanf("%f", &raio);

    //Saida do programa
    area_circulo = PI * raio * raio;
    printf("A area do circulo e %f", area_circulo);

    return 0;
}
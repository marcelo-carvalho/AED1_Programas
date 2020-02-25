#include <stdio.h>

#define PI 3.1415

int main(){
    float r =0;
    float area_circulo =0;

    printf("Este programa calcula a area de um circulo a partir do valor do raio r.\n");
    printf("Informe o valor de r: ");
    scanf("%f", &r);

    //Calculo da area do circulo
    area_circulo = PI * pow(r,2);

    printf("A area do circulo eh: %f", area_circulo);

    return 0;
}
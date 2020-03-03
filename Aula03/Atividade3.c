#include <stdio.h>
#include <math.h>

int main(){
    float numero = 0;
    
    printf("informe um valor maior que zero: ");
    scanf("%f", &numero);

    //numero digitado ao quadrado
    printf("O numero %f ao quadrado: %0.2f \n", numero, pow(numero,2));

    //numero digitado ao cubo
    printf("O numero %f ao cubo: %0.2f \n", numero, pow(numero,3));

    //a raiz quadrada do numero digitado
    printf("A raiz quadrada do numero: %0.2f \n", sqrt(numero));

    //a raiz cubica do numero digitadao
    printf("A raiz cubica do numero: %0.2f \n", pow(numero,1.0/3));

    return 0;
}
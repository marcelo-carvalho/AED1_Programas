#include <stdio.h>
#include <math.h>

int main(){
    float numero =0;

    //Como não foi passado em aula os comandos de condição, não me dei ao trabalho de tratar as condições
    //para numero positivo e diferente de zero. 
    printf("Digite um numero positivo maior que zero: ");
    scanf("%f", &numero);

    printf("\n O numero ao quadrado: %f", pow(numero,2));
    printf("\n O numero ao cubo: %f", pow(numero,3));

    //A função sqrt da biblioteca math poderia também ser substituida pela função pow(numero,1.0/2).
    printf("\n A raiz quadrada do numero: %f", sqrt(numero));

    //O C quando faz um divisao por dois numeros iteiros tende a retornar outro numero inteiro, 
    //neste caso eu forço um float usando 1.0, assim ele retornará um float. 
    printf("\n A raiz cubica do numero: %f", pow(numero,1.0/3));

    return 0;
}
#include <stdio.h>

int main(){
    int primeiro_numero = 0, segundo_numero =0;

    printf("Informe o primeiro numero: ");
    scanf("%i", &primeiro_numero);
    printf("Informe o segundo numero: ");
    scanf("%i", &segundo_numero);

    //condicao para testar primeiro_numero > segundo_numero
    if(primeiro_numero > segundo_numero){
        printf("%i e maior que %i", primeiro_numero, segundo_numero);
    }
    
    //condicao para testar segundo_numero > primeiro_numero
    if(segundo_numero > primeiro_numero){
        printf("%i e maior que %i", segundo_numero, primeiro_numero);
    }

    //não foi exigida uma condição para numeros iguais, porém seria da seguinte forma:
    /* if(primeiro_numero == segundo_numero){
        printf("Os dois numeros sao iguais");
    }*/
}
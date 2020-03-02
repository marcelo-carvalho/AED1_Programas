#include <stdio.h>

int main(){
    int numero1 =0, numero2=0, numero3=0;

    printf("Primeiro numero: ");
    scanf("%i", &numero1);
    printf("Segundo numero: ");
    scanf("%i", &numero2);
    printf("Terceiro numero: ");
    scanf("%i", &numero3);
    printf("Os numeros em ordem sao: ");

    //Condições para o primeiro número.
    if(numero1 < numero2 && numero1 < numero3){
        printf("%i,", numero1);
        
        if(numero2 < numero3){
            printf(" %i, %i", numero2, numero3);
        }
        else{
            printf(" %i, %i", numero3, numero2);
        }
    }
    else if(numero2 < numero1 && numero2 < numero3){
        printf("%i,", numero2);
        
        if(numero1 > numero3){
            printf(" %i, %i", numero3, numero1);
        }
        else{
             printf(" %i, %i", numero1, numero3);
        }
    }
    else{
        printf("%i,", numero3);
        
        if(numero2 > numero1){
            printf(" %i, %i", numero1, numero2);
        }
        else{
            printf(" %i, %i", numero2, numero1);
        }
    }
    return 0;
}
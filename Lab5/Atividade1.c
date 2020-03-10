#include <stdio.h>

int main(){
    float primeiro = 0;
    float segundo = 0;
    float terceiro = 0;

    printf("Informe o primeiro valor: ");
    scanf("%f", &primeiro);
    printf("Informe o segundo valor: ");
    scanf("%f", &segundo);
    printf("Informe o primeiro valor: ");
    scanf("%f", &terceiro);

    if(primeiro > segundo && primeiro > terceiro){
        printf("O maior elemento eh: %0.2f", primeiro);

        if(segundo > terceiro){
            printf("\nO outro elemento eh: %0.2f", segundo);
            printf("\nO menor elemento eh: %0.2f", terceiro);
        }
        else{
            printf("\nO outro elemento eh: %0.2f", terceiro);
            printf("\nO menor elemento eh: %0.2f", segundo);
        }
    }
    else if(segundo > primeiro && segundo > terceiro){
        printf("\nO maior elemento eh: %0.2f", segundo);

        if(primeiro > terceiro){
            printf("\nO outro elemento eh: %0.2f", primeiro);
            printf("\nO menor elemento eh: %0.2f", terceiro);
        }
        else{
            printf("\nO outro elemento eh: %0.2f", terceiro);
            printf("\nO menor elemento eh: %0.2f", primeiro);
        }
    }
    else {
        printf("\nO maior elemento eh: %0.2f", terceiro);

        if(segundo > primeiro){
            printf("\nO outro elemento eh: %0.2f",segundo);
            printf("\nO menor elemento eh: %0.2f", primeiro);
        }
        else{
            printf("\nO outro elemento eh: %0.2f",primeiro);
            printf("\nO menor elemento eh: %0.2f", segundo);
        }
    }
}
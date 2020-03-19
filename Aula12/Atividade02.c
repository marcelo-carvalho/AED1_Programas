#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char string[50];
    char string_inversa[50];
    int tamanho = 0, index = 0;

    printf("Digite uma string: ");
    scanf("%[^\n]", string);

    //tamanho define o limite de interecação.
    //index define a váriavel a ser decrementada.
    tamanho = strlen(string);
    index = tamanho - 1;

    //Iteração entre as duas strings.
    for(int i=0; i < tamanho ; i++){
        string_inversa[index] = string[i];
        index--;
    }
    
    //Utilizado para finalizar a String invertida. 
    string_inversa[tamanho] = '\0';

    printf("String original: %s", string);
    printf("\nString invertida: %s", string_inversa);
    return 0;
}
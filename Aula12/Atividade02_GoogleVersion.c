#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input[50];
    char output[50];
    int output_index = 0;

    printf("Digite uma string: ");
    scanf("%[^\n]", input);

    for (int i = strlen(input) - 1; i >= 0; i--) {
        output[output_index++] = input[i];
    }
    output[output_index]  = '\0';

    printf("String original: %s\n", input);
    printf("String invertida: %s", output);
    return 0;
}


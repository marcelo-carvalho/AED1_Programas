#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 30

int main(){
    char str[N];
    char invStr[N];
    int i, j, letraDiferente = 1;

    printf("Informe uma string: ");
    scanf("%[^\n]", &str);

    //transforma todas as letras em minúsculas.
    for(i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
    
    //cria uma string invertida. 
    j = strlen(str) - 1;
    for(i = 0; i < strlen(str); i++){
        invStr[i] = str[j];
        j--;
    }
    invStr[i] = '\0';

    //compara todas as letras das duas strings. 
    for(i = 0; i < strlen(str); i ++){
        if(str[i] != invStr[i]){
            letraDiferente = 0;
            break;
        }
    }

    printf("\nPalavra = %s \tPalavra invertida = %s\n", str, invStr);
    
    //teste se existe alguma letra diferente. 
    if(letraDiferente == 1)
        printf("\nA palavra e palindroma.");
    else 
        printf("\nA palavra nao e palindroma.");

    return 0;
}
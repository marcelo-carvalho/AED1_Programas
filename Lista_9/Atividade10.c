#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 30

//Função para determinar se a palavra é palindroma.
int comparaStr(char *str1, char *str2, int elem){
    if(elem > N)
        return 0;
    else if(str1[elem] != str2[elem])
        return 0;
    else if (str1[elem] == str2[elem])
        comparaStr(str1,str2,++elem);

        return 1;
}

//Procedimento para inverter strings
//Entrada:
//          str1 -> string a ser invertida;
//          str2 -> string invertida.
//          ini -> valor da posição inicial da str1 recomenda-se começar em 0.
//          fim -> valor final da posição str1 recomenda-se usar strlen().
void inverteStr(char *str1, char *str2, int ini, int fim){
    char temp;
    if(ini > strlen(str1)){
        return;
    }
    else{
        str2[ini] = str1[fim];
        inverteStr(str1,str2,++ini,--fim);
    }
}

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
    /*j = strlen(str) - 1;
    for(i = 0; i < strlen(str); i++){
        invStr[i] = str[j];
        j--;
    }
    invStr[i] = '\0';*/
    inverteStr(str,invStr,0,strlen(str)-1);
    //invStr[N] = '\0';

    printf("\nPalavra = %s \tPalavra invertida = %s\n", str, invStr);
    
    //teste se existe alguma letra diferente. 
    if(comparaStr(str,invStr,0) == 1)
        printf("\nA palavra e palindroma.");
    else 
        printf("\nA palavra nao e palindroma.");

    return 0;
}
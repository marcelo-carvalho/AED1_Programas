#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char frase[200];
    int conta_palavra = 0;

    printf("Digite uma frase: ");
    
    //Para adicionar a frase uma formatação especial é necessária,
    //[^\n] esta afirmando que tudo pode entrar na string exceto \n.
    scanf("%[^\n]", frase); 

    //Loop faz a contagem de caracters até o \0 e para quando o encontra.
    //As palavras são contadas a partir da quantidade de espaços em branco 
    
    for(int i=0; frase[i] != '\0'; i++){
        if(frase[i] == ' ' && frase[i+1] != ' ')
            conta_palavra++;
    }
    
    //soma-se mais um 1 no final para contar a última palavra.
    printf("Quantidade de palavras: %d", conta_palavra + 1);
    return 0;
}
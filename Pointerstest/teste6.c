#include <stdio.h>
#include <stdlib.h>

char * procura(char *, char); //Protótipo

int main(){
    char str[81], *ptr;

    printf("Digite uma frase: \n");
    gets(str);

    ptr = procura(str, 'h');

    printf("\nA frase começa no endereço: %p\n", str);

    if(ptr){
        printf("\nPrimeira ocorrencia do caractere 'h': %p\n", ptr);
        printf("\nA sua posicao eh: %d\n", ptr-str);
    }
    else
    {
        printf("O caractere 'h' não existe nessa frase.\n");
    }

    return 0;    
}

//Procura um coractere numa frase
char * procura(char *s, char ch){
    while(*s != ch && *s != '\0')
        s++;

    if(*s != '\0')
        return s;
    
    return (char *) 0;
}
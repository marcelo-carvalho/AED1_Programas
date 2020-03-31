#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fptr;
    char titulo[30];
    int regnum;
    double preco;
    fptr = fopen("livros.txt", "w");

    while(1){
        printf("\nDigite titulo, registro e preco do livro: ");
        scanf("%s %d %lf", titulo, &regnum, &preco);
        if(strlen(titulo) <= 1 ) break;
        fprintf(fptr,"%s %d %0.2lf\n", titulo, regnum, preco);
    }
    fclose(fptr);
    return 0;
}
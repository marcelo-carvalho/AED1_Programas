#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Livro{
    char Titulo[50];
    char Autor[50];
    short NumReg;
    double Preco;
} Livro;

Livro GetLivro(){
    Livro livro;
    printf("\n\tDigite o titulo: ");
    gets(livro.Titulo);
    printf("\n\tDigite o nome do Autor: ");
    gets(livro.Autor);
    printf("\n\tDigite o numero de registro: ");
    scanf("%hd",&livro.NumReg);
    printf("\tDigite o preco: ");
    scanf("%lf", &livro.Preco);
    rewind(stdin);
    return livro;
}

int main(){
    Livro livro;
    char resp;
    FILE *fptr;

    if((fptr = fopen("Livro.dat", "wb")) == NULL) exit(1);

    do{
        livro = GetLivro();
        if(fwrite(&livro, sizeof(Livro),1,fptr) != 1) break;
        printf("Mais um livro (s/n)? ");
        resp = getche();
    }while(resp != 'n' && resp != 'N');

    fclose(fptr);
    return 0;
}
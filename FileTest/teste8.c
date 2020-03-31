#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Livro{
    char Titulo[50];
    char Autor[50];
    short NumReg;
    double Preco;
} Livro;

void PrintLivro(Livro livro){
    printf("\n\tTitulo: %s\n", livro.Titulo);
    printf("\tAutor: %s\n", livro.Autor);
    printf("\tNo.Reg: %hd\n", livro.NumReg);
    printf("\tPreco: %.2lf\n", livro.Preco);
}

int main(){
    Livro livro;
    char resp;
    FILE *fptr;

    if((fptr = fopen("Livro.dat", "rb")) == NULL)
        exit(1);

    while(fread(&livro, sizeof(Livro), 1, fptr) == 1)
        PrintLivro(livro);
    
    fclose(fptr);
    return 0;
}
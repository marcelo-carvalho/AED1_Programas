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
    printf("\tDigite o nome do Autor: ");
    gets(livro.Autor);
    printf("\tDigite o numero de registro: ");
    scanf("%hd",&livro.NumReg);
    printf("\tDigite o preco: ");
    scanf("%lf", &livro.Preco);
    rewind(stdin);
    return livro;
}

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

    if((fptr = fopen("Livros.dat", "ab+")) == NULL) 
        exit(1);

    do{
        livro = GetLivro();
        
        if(fwrite(&livro, sizeof(Livro),1,fptr) != 1)
            break;
        
        printf("MAis um livro (s/n)? ");
        resp = getche();
    } while(resp != 'n' && resp != 'N');
    fflush(fptr);
    fseek(fptr,0,0); //Coloca o ponteiro no inicio do arquivo

    puts("\nLISTA DE LIVROS DO ARQUIVO");
    puts("\n=======================================");

    while(fread(&livro, sizeof(Livro),1,fptr)==1)
        PrintLivro(livro);

    return 0;
}
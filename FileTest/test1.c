#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    FILE *fptr; //Ponteiro para o arquivo
    char ch;

    fptr = fopen("arqtxt.txt", "w");
    while((ch=getche())!='\r') //Lê um caractere do teclado
        fputc(ch, fptr);  //Grava caractere no arquivo
    fclose(fptr);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    short int ch;

    fptr = fopen("arqtxt.txt", "r"); //Abre o arquivo TXT

    while((ch = fgetc(fptr)) != EOF) //Lê o caracter do arquivo TXT
        printf("%c", ch); //
    
    fclose(fptr); //Fecha o arquivo TXT.
    
    return 0;
}
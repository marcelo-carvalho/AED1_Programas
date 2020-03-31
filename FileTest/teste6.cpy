#include <stdio.h>
#include <stdlib.h>

void CopiaArquivo(const char* Origem, const char *Destino);

int main(){
    char Origem[] = "teste6.c";
    char Destino[] = "teste6.cpy";

    CopiaArquivo(Origem, Destino);
    return 0;
}

void CopiaArquivo(const char* Origem, const char *Destino){
    unsigned char buffer[1024];
    int BytesLidos;

    FILE *fOrigem, *fDestino;

    if((fOrigem = fopen(Origem, "rb"))==NULL) return;
    if((fDestino = fopen(Destino, "wb")) == NULL ) return;

    do{
        BytesLidos = fread(buffer, sizeof(char), sizeof(buffer), fOrigem);
        fwrite(buffer, sizeof(char), BytesLidos, fDestino);
    }while(BytesLidos);
}
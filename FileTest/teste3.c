#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    fptr = fopen("Testestr.txt", "w");

    fputs("Um grande antído contra o egoísmo\n", fptr);
    fputs("é a generosidade... Dê, mesmo que\n", fptr);
    fputs("isso requeira de vocês um esforço\n", fptr);
    fputs("consciente. Pelo fato de partilhar\n", fptr);
    fputs("tudo o que possui, seu egoísmo se\n", fptr);
    fputs("abandonará.\n",fptr);
    fclose(fptr);
    return 0;
}
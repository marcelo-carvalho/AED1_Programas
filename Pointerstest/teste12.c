#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i;
    printf("Numero de argumentos: %d\n", argc);

    for(i=0; i<argc;i++){
        printf("Argumento numero %d: %s\n", i, argv[i]);
    }
    return 0;
}
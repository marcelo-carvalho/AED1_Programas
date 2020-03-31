#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fptr;
    char str[81];

    if((fptr = fopen("Testestr.txt", "r")) == NULL){
        puts("Não foi possível abri o arquivo.");
        return 0;
    }

    while(fgets(str, 80, fptr) != NULL)
        printf("%s", str);

    fclose(fptr);
    return 0;    
}
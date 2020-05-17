#include <stdio.h>
#include <stdlib.h>

#define N 30

int hashNome(char *nome){
        return (int) (nome[0] /*+ nome[1] + nome[2]*/);
}

int main(){
    char nome1[N];
    char nome2[N];
    char nome3[N];
    int hashNome1, hashNome2, hashNome3;

    printf("Informe o primeira nome: ");
    scanf("%[^\n]", &nome1);
    setbuf(stdin, NULL);
    hashNome1 = hashNome(nome1);
    printf("Informe o segundo nome: ");
    scanf("%[^\n]", &nome2);
    setbuf(stdin, NULL);
    hashNome2 = hashNome(nome2);
    printf("Informe o terceiro nome: ");
    scanf("%[^\n]", &nome3);
    hashNome3 = hashNome(nome3);

    //Condições para exibição das strings ordenadas. 
    if(hashNome1 < hashNome2 && hashNome1 < hashNome3){
        if(hashNome2 < hashNome3){
            printf("%s", nome1);
            printf("\n%s", nome2);
            printf("\n%s", nome3);
        }
        else{
            printf("%s", nome1);
            printf("\n%s", nome3);
            printf("\n%s", nome2);
        }
    }
    else if (hashNome2 < hashNome1 && hashNome2 < hashNome3){
        if(hashNome1 < hashNome3){
            printf("%s", nome2);
            printf("\n%s", nome1);
            printf("\n%s", nome3);
        }
        else{
            printf("%s", nome2);
            printf("\n%s", nome3);
            printf("\n%s", nome1);
        }
    }
    else{
        if(hashNome1 > hashNome2){
            printf("%s", nome3);
            printf("\n%s", nome1);
            printf("\n%s", nome2);
        }
        else{
            printf("%s", nome3);
            printf("\n%s", nome2);
            printf("\n%s", nome1);
        }
    }
    return 0;
}
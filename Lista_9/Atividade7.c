#include <stdio.h>
#include <stdlib.h>

#define N 30

int main(){
    char string1[N];
    char string2[N];
    int strIguais = 1;

    printf("Informe a primeira string: ");
    scanf("%[^\n]s", &string1);
    setbuf(stdin, NULL);
    printf("Informe a segunda string: ");
    scanf("%[^\n]s", &string2);

    for(int i = 0; string1[i] != '\0' || string2[i] != '\0' ; i++){
        if(string1[i] != string2[i]){
            strIguais = 0;
            break;
        }
    }

    if(strIguais == 0){
        puts("As strings sao diferentes.");
        printf("str1 = %s", string1);
        printf("\nstr2 = %s", string2);
    }
    else {
        puts("As strings sao iguais");
        printf("str1 = %s", string1);
        printf("\nstr2 = %s", string2);
    }

    return 0;
}
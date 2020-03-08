#include <stdio.h>

int main(){
    int numero = 0;

    while(numero < 10){
        if(numero % 2 != 0){
            printf("%d\n", numero);
        }
        numero++;
    }
    return 0;
}
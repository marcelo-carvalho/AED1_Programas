#include <stdio.h>

int main(){
    int num = 100;
    int contador = 0;

    while(contador < 10){
        num++;
        contador++;
        printf("%d\n", num);
    }
    return 0;
}
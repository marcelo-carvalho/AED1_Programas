#include <stdio.h>
#include <stdlib.h>

//Calcula e exibe n-enesimo valor de uma progressçao geometrica
int progressao(int a, int r, int n){
    
    int z = a * pow(r,n-1);
    printf("\nN = %d Z = %d", n, z);

    if(n == 1)
        return z;
    else
        z *= progressao(a, r, n-1);
}

int main(){
    int first, r, n;

    printf("Informe o primeiro termo da progressao: ");
    scanf("%d", &first);
    printf("Informe a razao: ");
    scanf("%d", &r);
    printf("Informe o n-esimo termo desejado: ");
    scanf("%d", &n);

    progressao(first,r,n);
    return 0;
}
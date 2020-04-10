#include <stdio.h>
#include <stdlib.h>

int testeNumero(int numero){
    if(numero % 3 == 0){
        if(numero % 5 == 0){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}

int Ffatorial(int numero){
    int fatorial = 1;
    if(numero == 0){
        return 1;
    }
    else if (numero > 0){
        for(int i = numero; i > 0; i--){
            fatorial *= i;
            printf("%d\n", fatorial);
        }
        return fatorial;
    }
    else{
        printf("Numero nao eh valido.");
        return 0;
    }
}

void Pfatprial(int numero, int *fatorial){
    *fatorial = 1;
    if(numero == 0){
            *fatorial = 1;
    }
    else if (numero > 0){
        for(int i = numero; i > 1; i--){
            *fatorial *= i;
        }
    }
}

int main(){
    int numero = 0;
    int fatorialP;
    int fatorialF;

    printf("Informe um numero:");
    scanf("%d", &numero);

    if(testeNumero(numero) == 1)
        printf("Numero eh divisivel por 3 e 5.\n");
    else
        printf("Numero nao eh divisivel por 3 e 5.\n");

    fatorialF = Ffatorial(numero);
    printf("O Ffatorial eh %d\n", fatorialF);

    while(numero > 0){
        Pfatprial(numero, &fatorialP);
        printf("O Pfatorial de %d eh %d\n",numero, fatorialP);
        numero--;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

//Necessárias para gerar números aleatórios. 
#include <conio.h>
#include <time.h>

int main(){

    int M[5][10];
    int V[5] = {0,0,0,0,0};

    srand(time(NULL));

    for(int i=0; i < 5; i++){
        for(int j=0; j<10;j++){
            M[i][j] = (rand() % 101);

            V[i] += M[i][j];
        }
    }

    for(int i=0; i < 5; i++){
        for(int j=0; j<10;j++){
           printf("M[%d][%d] = %d\n", i, j, M[i][j]);
        }
    }

    for(int i=0; i < 5; i++){
        printf("V[%d] = %d\n", i, V[i]);
    }

    for(int i=0; i < 5; i++){
        for(int j=0; j<10;j++){
           printf("M[%d][%d] (%d) * V[%d] (%d) = %d\n", i, j, M[i][j], i, V[i], M[i][j] * V[i] );
        }
    }
}
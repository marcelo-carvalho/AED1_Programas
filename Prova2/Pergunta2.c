#include <stdio.h>
#include <stdlib.h>

#define N 3

int testaSimetria(int mat[][N]);

int main(){
    int mat1[N][N] = { 1,7,3, 7,4,5, 3,5,6}; 
    int mat2[N][N] = { 1,2,3, 4,5,6, 7,8,9};
    
    if(testaSimetria(mat1) == 0)
        puts("Matriz 1 nao e simetrica.");
    else
        puts("Matriz 1 e simetrica.");

    if(testaSimetria(mat2) == 0)
        puts("Matriz 2 nao e simetrica.");
    else
        puts("Matriz 2 e simetrica.");

    return 1;
}

int testaSimetria(int mat[][N]){
    int i, j;
    int trans[N][N];

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            trans[j][i] = mat[i][j]; //Cria a matriz transposta. 
        }
    }

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(trans[i][j] != mat[i][j])
                return 0; //Caso matriz não simétrica
        }
    }

    return 1; //Caso matriz simétrica
}
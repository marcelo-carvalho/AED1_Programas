#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int M[2][3];
    int R[2][3];
    int maior = 0;

    for(int i=0; i < 2; i++){
        for(int j=0; j<3;j++){
            printf("Informe o valor M[%d][%d]]: ", i, j);
            scanf("%d", &M[i][j]);

            if(maior < M[i][j]){
                maior = M[i][j];
            }
        }
    }

    for(int i=0; i < 2; i++){
        for(int j=0; j<3;j++){
            R[i][j] = maior * M[i][j];
        }
    }

    for(int i=0; i < 2; i++){
        for(int j=0; j<3;j++){
           printf("M[%d][%d] = %d\n", i, j, M[i][j]);
        }
    }

    for(int i=0; i < 2; i++){
        for(int j=0; j<3;j++){
           printf("R[%d][%d] = %d\n", i, j, R[i][j]);
        }
    }

    return 0;
}
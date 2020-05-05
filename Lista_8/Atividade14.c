#include <stdio.h>
#include <stdlib.h>

void ordena(int n, int *v){
    int j,i;

    for(i=n-1; i>-1; i--){
        int troca = 0;
        for(j=0;j<i; j++){
            if(v[j]>v[j+1]){
                int temp = v[j];    //troca
                v[j] = v[j+1];
                v[j+1] = temp;
                troca = 1;
            }
        }
        if(troca == 0) //Não houve troca
            return;
    }
}


int main(){
    
    int vet[100];
    int n = 0;
    int i; 

    puts("Informe a quantidade de valores desejado: ");
    scanf("%d", &n);
    

    for(i = 0; i < n; i ++){
        printf("#%d Informe um valor: ", i);
        scanf("%d", &vet[i]);
    }

    ordena(n,vet); 

    printf("Segundo menor valor digitado = %d", vet[1]);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void rapida(int n, int *v);

int main(){
    int i;
    int v[8] = {25,48,37,12,57,86,33,92};
    rapida(8,v);
    printf("Vetor ordenado: ");
    for(i=0; i<8; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}

void rapida(int n, int *v){
    if(n<=1)
        return 1;
    else{
        int x = v[0];
        int a = 1;
        int b = n -1;
        do{
            while(a < n && v[a] <= x) a++;
            while(v[b] > x) b--;
            if(a < b) {
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++; b--;
            }
        }while(a <= b);

        //troca pivô
        v[0] = v[b];
        v[b] = x;

        //ordena subvetores restantes
        rapida(b,v);
        rapida(n-a,&v[a]);
    }
}
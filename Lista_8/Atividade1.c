#include <stdio.h>
#include <stdlib.h>

//Função recursiva que realiza a divisão de dois numeros utilizando 
//da subtração do dividendo pelo divisor. 
int divide(int x, int y){
    int z = 1; 

    if(x < 0)
        x = -x;
    if(y < 0)
        y = -y;

    if(y == 0 || x < y)
        return 0;
    else if(x - y > 0)
        z += divide(x-y, y);
   
    return z;
}

int main(){
    int A, B;
    printf("Informe um dividendo: ");
    scanf("%d", &A);
    printf("Informe um divisior: ");
    scanf("%d", &B);

    printf("A / B = %d", divide(A,B));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float calcFact(int a){
    float fact = 1;
    if(a < 0){
        puts("To calculate factorial the number must be > 0.");
        return 1;
    }
    else if(a == 0){
        return 1;
    }
    else{
        for(int i = 1; i <= a; i++){
            fact *= i;
        }
        return fact;
    }
}

float calcSin(float x){
    float comp = sin(x);
    float sinX = x; 
    int operator = 3;
    int i = 1;
    while(i < 20){
        sinX += (float) (pow(x,operator) / calcFact(operator)) * pow(-1,i);
        operator += 2;
        i++;
        printf("\nsinX: %f", sinX);
        printf("\nOperador: %d", operator);
    }
    return sinX;
}



int main(){
    int x;
    float resultado = 0;
    puts("Numero do fatorial");
    scanf("%i", &x);

    resultado = calcSin(x);
    printf("\nResultado: %f", resultado);
    resultado = sin(x);
    printf("\nsin(x): %f", resultado);
}
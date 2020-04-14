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

//calcSeries: procedimento criado para calcular os vintes primeiros elementos de uma serie infinita. 
//Procedimento irá retornar o resultado da soma dos 20 primieros elementos dessa serie. 
void calcSeries(){
    int count = 0;
    int num = 100;
    float series = 0;
    while (count < 20){
        series += num / calcFact(count);
        printf("%d = %f\n", count, series);
        
        num--;
        count++;
        
    }
    printf("O resultado da serie eh: %f\n", series);
}

int main(){
    printf("\n0! = %f", calcFact(0));
    printf("\n1! = %f", calcFact(1));
    printf("\n2! = %f", calcFact(2));
    printf("\n3! = %f", calcFact(3));
    printf("\n4! = %f", calcFact(4));
    printf("\n5! = %f", calcFact(5));
    calcSeries();
}
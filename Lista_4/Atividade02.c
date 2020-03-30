#include <stdio.h>
#include <stdlib.h>

int main(){
    int A;
    int B;

    printf("Enter the number A: ");
    scanf("%d", &A);
    printf("Enter the number B: ");
    scanf("%d", &B);

    printf("\nA + B = %d", A + B);
    printf("\nA - B = %d", A - B);
    printf("\nA * B = %d", A * B);
    printf("\nA / B = %0.4f", (float) A / B);
    
    return 0;
}
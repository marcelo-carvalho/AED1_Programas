#include <stdio.h>
#include <stdlib.h>

int main(){
    static int M[5] = {92,81,70,69,58};

    for(int i=0;i<5;i++)
        printf("%d\n", *(M+i)); //Notação ponteiro

    return 0;
}
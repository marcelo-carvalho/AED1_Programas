#include <stdio.h>
#include <stdlib.h>

int main() {

    float nota = 0;
    float media = 0;

    for(int i = 0; i < 10; i++){
        printf("Informe a %d nota: ", i+1);
        scanf("%f", &nota);
        if(nota > 0){
            media += nota;
        }
    }
    media = media / 10;
    printf("A media das notas de alunos eh = %0.2f", media);
    return 0;
}
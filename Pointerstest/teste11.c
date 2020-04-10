#include <stdio.h>
#include <stdlib.h>

float media(float *, int); //Protótipo 

int main(){
    float * notas, m;
    int tamanho, i;

    puts("Qual eh o numero de notas? ");
    scanf("%d", &tamanho);

    notas = (float *) calloc(tamanho, sizeof(float));

    for(i=0; i< tamanho; i++){
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", notas+i);
    }

    m = media(notas, tamanho);
    printf("Media das notas: %.2f\n", m);

    free(notas);
    return 0;
}

float media(float *lista, int tamanho){
    int i;
    float m=0.0;
    for(i =0; i < tamanho; i++){
        m += *(lista++);
    }
    return m/tamanho;
}
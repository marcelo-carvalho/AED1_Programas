#include <stdio.h>

int main(){
    int nota = 0;
    char nome[101];

    //
    printf("Informe o nome da disciplina: ");
    scanf("%s", &nome);
    printf("Informe a nota do aluno: ");
    scanf("%i", &nota);

    //Condição para aprovação.
    if(nota >= 60) {
        printf("Aluno Aprovado em %s.", nome);
    }

    //Condição para reprovação.
    if(nota < 60) {
        printf("Aluno Reprovado em %s.", nome);
    }
}
#include <stdio.h>

int main(){
    int nota =0;
    char nome_disciplina[101];

    printf("Informe o nome da disciplina: ");
    scanf("%s", &nome_disciplina);
    printf("Informe a nota do aluno: ");
    scanf("%i", &nota);

    //Condicoes de aprovação e reprovação
    if(nota >= 60){
        printf("Aluno aprovado.");
    }
    else {
        printf("Aluno reprovado");
    }
    return 0;
}
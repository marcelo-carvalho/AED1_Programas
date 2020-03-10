#include <stdio.h>

int main(){
    float trabalho_lab = 0;
    float avaliacao_sems = 0;
    float exame_final = 0;

    printf("Trabalho Laboratorio: ");
    scanf("%f", &trabalho_lab);
    printf("Avaliacao Semestral: ");
    scanf("%f", &avaliacao_sems);
    printf("Exame Final: ");
    scanf("%f", &exame_final);

    float nota_final = trabalho_lab + avaliacao_sems + exame_final;

    printf("Nota: %f - ", nota_final);

    if(nota_final >= 8 && nota_final <= 10)
        printf("Conceito: A");
    else if(nota_final >= 7 && nota_final < 8)
        printf("Conceito: B");
    else if(nota_final >= 6 && nota_final < 7)
        printf("Conceito: C");
    else if(nota_final >= 5 && nota_final < 6)
        printf("Conceito: D");
    else
        printf("Conceito: F");
    
    return 0;
}
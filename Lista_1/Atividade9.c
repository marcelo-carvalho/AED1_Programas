/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 1 - Atividade 9                          */

#include <stdio.h>

int main(){

    //Declando as variáveis.
    float capital = 0;
    float taxa_juros = 0;
    int meses = 0;
    float rendimento =0;
    float montante = 0;


    //Inputs do usuário.
    printf("Inform o capital inicial: ");
    scanf("%f", &capital);
    printf("Inform a taxa de juros ao mes: ");
    scanf("%f", &taxa_juros);
    printf("Informe o numero de meses: ");
    scanf("%i", &meses);

    //Calculo de rendimentos.
    taxa_juros = taxa_juros/100;
    rendimento = capital * taxa_juros * meses;

    //Calculo do montante.
    montante = capital + rendimento;

    //Output para o usuário.
    printf("Os rendimentos totais foram: R$ %0.2f", rendimento);
    printf("\nO montante total foi: R$ %0.2f", montante);

    return 0;
}
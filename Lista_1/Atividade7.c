/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 1 - Atividade 7                          */


#include <stdio.h>;

int main(){
    
    //Declarando váriaveis. 
    float largura1 = 0, comprimento1 = 0;
    float largura2 = 0, comprimento2 = 0;
    float largura3 = 0, comprimento3 = 0;
    float area1 = 0, area2 = 0, area3 = 0, area_total = 0;

    //Input do usuário.
    printf("Informe o comprimento do comodo 1: ");
    scanf("%f", &comprimento1);
    printf("Informe a largura do comodo 1: ");
    scanf("%f", &largura1);

    printf("Informe o comprimento do comodo 2: ");
    scanf("%f", &comprimento2);
    printf("Informe a largura do comodo 2: ");
    scanf("%f", &largura2);

    printf("Informe o comprimento do comodo 3: ");
    scanf("%f", &comprimento3);
    printf("Informe a largura do comodo 3: ");
    scanf("%f", &largura3);

    //Calculo das áreas.
    area1 = comprimento1 * largura1;
    area2 = comprimento2 * largura2;
    area3 = comprimento3 * largura3;
    area_total = area1 +  area2 + area3;

    //Output pro usuário.
    printf("Area do comodo 1 = %0.2f m^2", area1);
    printf("\nArea do comodo 2 = %0.2f m^2", area2);
    printf("\nArea do comodo 3 = %0.2f m^2", area3);
    printf("\nArea total do imovel = %0.2f m^2", area_total);

    return 0;
}
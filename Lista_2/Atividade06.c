/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 6                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int angulo1 = 0, angulo2=0, angulo3=0;

    printf("Informe o valor dos tres angulos do triangulo: ");
    scanf("%d %d %d", &angulo1, &angulo2, &angulo3);

    //Testa se o triangulo é possível.
    if(angulo1 + angulo2 + angulo3 > 180){
        printf("Soma dos angulos maior que 180, valores invalidos.");
    }
    else{
        //testa os possiveis tipos de triangulo. 
        if(angulo1 == 90||angulo2==90||angulo3==90){
            printf("Triangulo Retangulo.");
        }
        else if(angulo1 >90|| angulo2>90|| angulo3> 90){
            printf("Triangulo Obtusangulo.");
        }
        else if(angulo1 < 90 && angulo2 < 90 && angulo3 < 90){
            printf("Triangulo Acutangulo.");
        }
    }
    return 0;
}
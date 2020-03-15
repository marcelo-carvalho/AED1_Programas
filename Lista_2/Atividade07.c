/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 7                          */

#include <stdio.h>
#include <stdlib.h>

int main(){
    float peso = 0, altura = 0, IMC = 0;
    printf("Informe o seu peso em kg: ");
    scanf("%f", &peso);
    printf("Informe sua altura em metros: ");
    scanf("%f", &altura);

    //teste para saber se valores entrados são validos. 
    if(peso > 0 && altura > 0 && altura <= 3.0){
        IMC = peso / (altura * altura);

        //Categorias de IMC
        if(IMC < 18.5){
            printf("\nIMC = %0.2f: Abaixo do peso.", IMC);
        }
        else if (IMC >= 18.5 && IMC < 24.9){
            printf("\nIMC = %0.2f: Peso ideal (Parabens).", IMC);
        }
        else if (IMC >= 25 && IMC < 29.9){
            printf("\nIMC = %0.2f: Levemente acima do peso.", IMC);
        }
        else if (IMC >= 30 && IMC < 34.9){
            printf("\nIMC = %0.2f: Obesidade grau I.", IMC);
        }
        else if (IMC >= 35 && IMC < 39.9 ){
            printf("\nIMC = %f0.2: Obesidade grau II (Severa).", IMC);
        }
        else{
            printf("\nIMC = %f0.2: Obesidade grau III (Morbida).", IMC);
        }
    }
    else{
        printf("\nValores informados nao sao validos.");
    }
    return 0;
}
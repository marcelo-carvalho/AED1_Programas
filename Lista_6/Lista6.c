#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
    int index = 0;
    float num1, num2, num3, maior, menor, avg;
    int A, B, res;
    int a, b, c, d, e;
    
    do{
    index = menu();
        switch(index){
            case 1:
                puts("\nInforme uma sequencia de 3 numeros");
                scanf("%f %f %f", &num1, &num2, &num3);
                primeiraAtividade(num1, num2, num3, &maior, &menor);
                printf("\nMaior: %0.2f \tMenor: %0.2f\n", maior, menor);
                break;
            case 2:
                puts("\nInforme um sequencia de 3 numeros");
                scanf("%f %f %f", &num1, &num2, &num3);
                segundaAtividade(num1, num2, num3, &avg);
                printf("\nMedia: %f", avg);
                break;
            case 3:
                puts("\nInforme uma sequencia de dois numeros binarios.");
                puts("Os numeros so podem ser 0 (FALSO) ou 1 (VERDADEIRO).");
                scanf("%d %d", &A, &B);
                if(validaBoolean(&A, &B) == 1) //Valida os valores recebidos.
                    terceiraAtviidade(A, B, &res);

                printf("\n¬ (A ^ B) = ");
                if(res == 1)
                    printf("VERDADEIRO");
                else
                    printf("FALSO");
                break;
            case 4:
                puts("\nInforme uma sequencia de 5 numeros");
                scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
                quartaAtividade(&a, &b, &c, &d, &e);
                break;
            case 5:
                quintaAtividade();
                break;
            case 6:
                sextaAtividade();
                puts("\nEm miserio1 percebe-se que a variavel local 'x' recebe o valor que foi passando como referencia para a funcao e o impreme na tela.");
                puts("Em misterio2 a variavel local 'y' nao recebe nenhum valor e no contexto do meu computador, o compilador atribui a esta variavel"
                "\no mesmo endereco da variavel local x (da funcao misterio1), imprimindo assim o dado que ja estava ali armazenado.");
                break;
            case 0:
                break;
        }
    } while(index != 0);
    return 0;
}
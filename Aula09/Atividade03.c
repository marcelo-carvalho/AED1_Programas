#include <stdio.h>

int main(){
    int operacao = 0;
    float numero1 = 0;
    float numero2 = 0;

    do{
        //Print das opções do menu
        printf("\aCalculadora basica em C.");
        printf("\n\t1 - Somar");
        printf("\n\t2 - Subtrair");
        printf("\n\t3 - Multiplicar");
        printf("\n\t4 - Dividir");
        printf("\n\t0 - Sair");
        printf("\nEscolha uma operacao: ");
        scanf("%d", &operacao);

        //Input dos numeros para realizar a opera~]ao
        if(operacao != 0 ){
            printf("Informe o primeiro numero: ");
            scanf("%f", &numero1);
            printf("Informe o segundo numero: ");
            scanf("%f", &numero2);
        }
        
        //realizando operações
        switch(operacao){
            case 1: 
                printf("\n\nSoma = %0.2f\n\n", numero1 + numero2);
                operacao = 10;
            break;
            case 2:
                printf("\n\nSubtrair = %0.2f\n\n", numero1 - numero2);
                operacao = 10;
            break;
            case 3: 
                printf("\n\nMultiplicar = %0.2f\n\n", numero1 * numero2);
                operacao = 10;
            break;
            case 4:
                if(numero2 != 0) //condicao para caso de divisao por 0.
                    printf("\n\nDivisao = %0.2f\n\n", numero1 / numero2);
                else
                    printf("\nDivisao por 0.\n\n");
                operacao = 10;
            break;
            case 0:
                //operacao = 0;
                break;
            default:
                printf("\n\nOperacao invalida, selecione uma operacao valida.\n\n");
                operacao = 10;
            break;            
        }
    }while(operacao > 0);
}
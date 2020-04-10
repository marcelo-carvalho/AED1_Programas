#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Descrição: Verifica qual o maior numero e retorna o maior valor.
Tipo de retorno: int
Parametros de entrada: int num1, int num2.
saída: bool
*/
int maiorNumero(int num1, int num2){
    if(num1 > num2)
        return num1;
    else
        return num2;
}

/*Descrição: Verifica um caracter e retorno True se minúscula False caso contrário.
Tipo de retorno: bool
Parametros de entrada: char.
saída: bool
*/
bool checkCase(char ch){
    if(ch >= 'a' && ch <= 'z')
        return true;
    else
        return false;
}

int main(){
    int num1, num2, index;
    char ch;

    do{
        printf("Escolha uma opcao: "
        "\n[1] - Maior numero"
        "\n[2] - Verifica caracter"
        "\n[0] - Sair\n");

        scanf("%d", &index);

        switch(index){
            case 1: 
                printf("Primeiro numero: ");
                scanf("%d", &num1);
                printf("Segundo numero: ");
                scanf("%d", &num2);
                printf("\nO maior numero eh: %d\n", maiorNumero(num1,num2));
                break;
            case 2:
                printf("\nInforme um caracter: ");
                fflush(stdin);
                scanf("%c", &ch);
                
                if(checkCase(ch))
                    printf("\nLetra minuscula.\n");
                else
                    printf("\nLetra maiuscula.\n");
                break;
            case 0:
            printf("\nObrigado por usar\n");
                return 0;
                break;
            default:
                printf("\nOpcao invalida.\n");
                break;
        }
    }while(index != 0);
    return 0;
}
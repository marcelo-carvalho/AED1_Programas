#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


float somar(float operador1, float operador2){
    return operador1 + operador2;
}

float subtrair(float operador1, float operador2){
    return operador1 - operador2;
}

float dividir(float operador1, float operador2){
    return operador1 / operador2;
}

float multiplicar(float operador1, float operador2){
    return operador1 * operador2;
}

void menu(char &index){
    printf("Escolha o que fazer com os numeros: \n"
        "[*] - Multiplicar \n"
        "[/] - Dividir \n"
        "[+] - Somar \n"
        "[-] - Subtrair \n"
        "[0] - Sair\n"
        "Escolha uma opcao: ");
        
    fflush(stdin); // Para limpar o buffer. 
        
    scanf("%c", &index);
}

int main(){

    float numero1 = 0;
    float numero2 = 0; 
    char index;

    printf("Informe o primeiro numero: ");
    scanf("%f", &numero1);
    printf("Informe o segundo numero: ");
    scanf("%f", &numero2);

    //Apresentação do menu.
    while(index != -1){
        
        menu(index);

        //Opções de escolha do usuário. 
        switch(index) {
            case '*':
                printf("\n%0.2f", multiplicar(numero1, numero2));
                index = -1;
                break;
            case '/':
                printf("\n%0.2f", dividir(numero1, numero2));
                index = -1;
                break;
            case '+':
                printf("\n%0.2f", somar(numero1, numero2));
                index = -1;
                break;
            case '-':
                printf("\n%0.2f", subtrair(numero1, numero2));
                index = -1;
                break;
            case '0':
                index = -1;
                break;
            default:
                printf("\nCaractere invalido.");
        }
    }
    
    return 0;
}
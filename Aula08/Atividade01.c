#include <stdio.h>

int main(){

    float numero1 = 0, numero2 = 0; 
    char index;

    printf("Informe o primeiro numero: ");
    scanf("%f", &numero1);
    printf("Informe o segundo numero: ");
    scanf("%f", &numero2);

    //Apresentação do menu.
    printf("Escolha o que fazer com os numeros: \n"
            "[*] - Multiplicar \n"
            "[/] - Dividir \n"
            "[+] - Somar \n"
            "[-] - Subtrair \n"
            "Escolha uma opcao: ");
    
    fflush(stdin); // Para limpar o buffer. 
    
    scanf("%c", &index);

    //Opções de escolha do usuário. 
    switch(index) {
        case '*':
            printf("\n%f", numero1 * numero2);
            break;
        case '/':
            printf("\n%f", numero1 / numero2);
            break;
        case '+':
            printf("\n%f", numero1 + numero2);
            break;
        case '-':
            printf("\n%f", numero1 - numero2);
            break;
        default:
            printf("\nCaractere invalido.");
    }

    return 0;
}
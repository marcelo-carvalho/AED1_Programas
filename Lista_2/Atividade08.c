/* Pontíficia Universidade Católica de Minas Gerais
   Engenharia de Computação
   Algoritmos e Estrutura de Dados 1 
   Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
   Lista de Exercíciso 2 - Atividade 8                          */

#include <stdio.h>
#include <stdlib.h>

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
    if(index == '*')
        printf("\n%f", numero1 * numero2);
    else if(index == '/')
        printf("\n%f", numero1 / numero2);
    else if(index == '+')
        printf("\n%f", numero1 + numero2);
    else if( index == '-')
        printf("\n%f", numero1 - numero2);
    else
        printf("\nCaractere invalido.");

    return 0;
}
//  Pontíficia Universidade Católica de Minas Gerais
//  Engenharia de Computação
//  Algoritmos e Estrutura de Dados 1 
//  Aluno: Marcelo de Carvalho Pereira       Matricula: 687921
//  Lista de Exercíciso 3 - Atividade 5

#include <stdio.h>
#include <stdlib.h>

int main(){
    float number1 = 0, number2 = 0; 
    char index;
    do{
        //Shows the menu.
        printf("Choose an option: \n"
            "[*] - Multiply \n"
            "[/] - Divide \n"
            "[+] - Sum \n"
            "[-] - Subtract \n"
            "[0] - Exit\n"
            "What is your option? ");
        
        fflush(stdin); //Cleans the buffer. 
        scanf("%c", &index);

        //The condition has been created to prevent the regular flow 
        //of the code since '0' has been chosen.
        if(index != '0'){
            printf("Enter the first number: ");
            scanf("%f", &number1);
            printf("Enter the second number: ");
            scanf("%f", &number2);

            switch(index) {
                case '*':
                    printf("\n%f\n", number1 * number2);
                    break;
                case '/':
                    printf("\n%f\n", number1 / number2);
                    break;
                case '+':
                    printf("\n%f\n", number1 + number2);
                    break;
                case '-':
                    printf("\n%f\n", number1 - number2);
                    break;
                default:
                    printf("\nWrong oprtion, chosse a right one.\n");
            }
        }
    }while(index != '0');
    
    printf("Thank you for using the program!");
    return 0;    
}
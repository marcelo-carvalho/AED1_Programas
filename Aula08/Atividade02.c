#include <stdio.h>

int main(){
    int dia = 0;

    printf("Informe um valor para o dia entre 1 e 7: ");
    scanf("%i", &dia);

    switch(dia){
        case 2:
        case 3:
        case 4: 
        case 5: 
        case 6: 
            printf("Dia util.");
            break;
        case 1:
        case 7: 
            printf("Final de semana.");
            break;
        default:
            printf("Dia invalido.");    
    }
    return 0;
}
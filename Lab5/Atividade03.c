#include <stdio.h>

int main(){

    int index = 0;
    float salario =0;

    printf("Informe o código do cargo do funcionario: "
            "\n[1] - Escrituario"
            "\n[2] - Secretario"
            "\n[3] - Caixa"
            "\n[4] - Gerente"
            "\n[5] - Diretor - ");
    scanf("%i", &index);
    printf("Informe o salario do funcionario: ");
    scanf("%f", &salario);

    if(salario<=0 ){
        printf("Valor de salario não eh valido.");
    }
    else{ 
        switch(index){
            case 1: 
                salario = salario * 1.5;
                printf("Codigo: %i \tCargo: Escriturario \tNovo Salario: R$%0.2f", index, salario);
                break;
            case 2: 
                salario = salario * 1.35;
                printf("Codigo: %i \tCargo: Secretario \tNovo Salario: R$%0.2f", index, salario);
                break;
            case 3: 
                salario = salario * 1.20;
                printf("Codigo: %i \tCargo: Caixa \tNovo Salario: R$%0.2f", index, salario);
                break;
            case 4: 
                salario = salario * 1.10;
                printf("Codigo: %i \tCargo: Gerente \tNovo Salario: R$%0.2f", index, salario);
                break;
            case 5: 
                printf("Codigo: %i \tCargo: Diretor \tNovo Salario: R$%0.2f", index, salario);
                break;
            default:
                printf("O codigio não eh valido.");
        }
    }
    return 0;
}
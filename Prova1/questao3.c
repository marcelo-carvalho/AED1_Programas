#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int);

int main(){
    int n, aux;

    puts("\n================================================================================");
    puts("Progama procura o maior numero primo menor que um numeor informado pelo usuario.");
    puts("Informe um numero inteiro: ");
    scanf("%d", &n);

    //Verifica se número é negativo. 
    if(n < 0){
        //loop executa ate numero maior que zero ser atribuido a n.
        do{
            puts("Valor deve ser maior que 0");
            puts("Informe um novo valor.");
        } while(n < 0);
    }

    //Cada loop decrementa uma unidade em aux e testa o novo numero para saber se é primo ou não.
    aux = n;
    while(aux > 0){
        if(ehPrimo(aux) == 1){
            printf("O maior numero primo menor que %d eh: %d", n, aux);
            break;
        }
        aux--;
    }
    return 0;
}

//Função verifica se número é primo.
//Retorna 0 se não for primo.
//Retorna 1 se for primo.
int ehPrimo(int n){

        //Loop testa o resto da divisão de n por todos os numeros menors que n/2.
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                return 0;
            }
        }
    return 1;
}
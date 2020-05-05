#include <stdio.h>
#include <stdlib.h>

int main(){

    float compra = 0;
    float venda = 0;
    float lucro = 0;
    int produto = -1, primeiraFaixa = 0, segundaFaixa = 0, terceiraFaixa = 0;
    
    puts("\n================================================================================");
    puts("Programa para determinar quantidade de produtos vendos por faixa de lucro");
    printf("\nInforme o codigo do produto: ");
    scanf("%d", &produto);
    
    while(produto > 0){
        printf("\nInfor o valor de compra do produto: ");
        scanf("%f", &compra);
        printf("\nInforme o valor de venda do produto: ");
        scanf("%f", &venda);

        lucro = (venda - compra) / compra; //calcula a porcentagem de lucro

        //Determina os intervalos de lucros
        if(lucro < 0.1){
            printf("\n\tProduto: %d \tCompra: R$ %0.2f \tVenda: R$ %0.2f \tLucro: R$ %0.2f / %0.2f%%", produto, compra, venda, venda - compra, lucro * 100);
            primeiraFaixa++;
        }
        else if (lucro >= 0.1 && lucro <= 0.2){
            printf("\n\tProduto: %d \tCompra: R$ %0.2f \tVenda: R$ %0.2f \tLucro: R$ %0.2f / %0.2f%%", produto, compra, venda, venda - compra, lucro * 100);
            segundaFaixa++;
        }
        else{
            printf("\n\tProduto: %d \tCompra: R$ %0.2f \tVenda: R$ %0.2f \tLucro: R$ %0.2f / %0.2f%%", produto, compra, venda, venda - compra, lucro * 100);
            terceiraFaixa++;
        }
        printf("\n\nInforme o codigo do produto: ");
        scanf("%d", &produto);
    }

    printf("\n\tProdutos com lucro < 10%%: %i ", primeiraFaixa);
    printf("\n\tProdutos com lucro >= 10%% e <= 20%%: %i ", segundaFaixa);
    printf("\n\tProdutos com lucro > 20%%: %i ", terceiraFaixa);
    return 0;
}
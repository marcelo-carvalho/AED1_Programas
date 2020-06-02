#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct veiculo{
    char placa[8];
    int ano_modelo;
    char marca[30];
    char modelo[50];
    float valor_mercado;
} Veiculo;

void consultaVeiculo(Veiculo[], float);

int main(){
    Veiculo veiculos[N];
    float valor_mercado;
    int i;

    for(i = 0; i < N; i++){
        printf("Placa: ");
        gets(veiculos[i].placa);
        printf("Ano: ");
        scanf("%d%*c", &veiculos[i].ano_modelo);
        printf("Marca: ");
        gets(veiculos[i].marca);
        printf("Modelo: ");
        gets(veiculos[i].modelo);
        printf("Valor de mercado: ");
        scanf("%f%*c", &veiculos[i].valor_mercado);
    }

    printf("\nInforme um valor de mercado: ");
    scanf("%f%*c", &valor_mercado);
    
    consultaVeiculo(veiculos, valor_mercado);

    return 1;
}


void consultaVeiculo(Veiculo veiculos[], float valor_mercado){
    int i, maior = 0, menor = 0;
    FILE *fp;

    if((fp = fopen("ConsultaVeiculos.txt","w")) == NULL){
        puts("Erro ao criar o arquivo texto.");
        puts("Programa encerrado");
        return;
    }

    for(i = 0; i < N; i++){
        if(veiculos[i].valor_mercado > valor_mercado)
            maior++;
        else 
            menor++;
    }

    fprintf(fp, "Carros com valores maior que o informado: %d", maior);
    fprintf(fp, "\nCarros com valores menores que o informado: %d", menor);

    printf("\nCarros com valores maior que o informado: %d", maior);
    printf("\nCarros com valores menores que o informado: %d", menor);

    fclose(fp);
}
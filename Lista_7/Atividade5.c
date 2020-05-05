#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void distanciaManhattan(int, int, int, int *);

int main(){

    int x, y, n, soma = 0;

    puts("\n================================================================================");
    puts("Programa calcula a soma das distancias de Manhattan de n grupos de dois pontos quaisquer");
    puts("Informe o ponto incial x y: ");
    scanf("%d %d", &x, &y);
    puts("Informe a quantidade de pontos");
    scanf("%d", &n);

    distanciaManhattan(x,y,n,&soma);

    printf("\nSoma das distancias dos pontos = %d", soma);
    return 0;
}

//Procedimento recebe um ponto x y inicial, um valor n e a referência para variavel soma
//Serão realizadas n iterações segundo desejo do usuário e para cada uma sera calculada a
//distância de Manhattan entre o ponto inicial e o ponto informado pelo usuario. Essa distancia
//sera somada ao acumulador soma que retornar para a função main por referência. 
void distanciaManhattan(int x, int y, int n, int *soma){
    int i = 0;
    int x2, y2;

    srand((unsigned)time(NULL));
    
    while(i < n){
        /*printf("\nInforme os valores x y do ponto %d: ", i+1);
        scanf("%d %d", &x2, &y2);*/
        x2 = rand() % 100;
        y2 = rand() % 100;
        *soma += (abs(x - x2) + abs(y - y2)); //Incremento do acumulador com as distâncias. 
        i++;
    }
}
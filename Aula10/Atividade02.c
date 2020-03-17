#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 0, maior = 0, menor = 0;

    printf("Por favor informe uma sequencia de 15 numeros inteiros:");

    //O loop lê as entradas dos usuário e em seguida compara com o 
    //as variáveis maior e menor com o valor de entrada do usuário. 
    for(int i =0; i<15; i++){
        printf("\nInforme o numero %i: ", i+1);
        scanf("%d", &num);
        
        //Em um primeiro loop é necessario armazenar o primeiro valaor
        //nas variáveis maior e menor de forma a termos um ponto de
        //partida para comparação dos demais números. 
        if(i==0){
            maior = num;
            menor = num;
        }
        else{
            if(num > maior)
                maior = num;
            if(num < menor)
                menor = num;
        }
    }

    //Aqui é apresntado os resultados para o usuário. 
    printf("\nO menor numero eh: %d", menor);
    printf("\nO maior numero eh: %d", maior);
    return 0;
}
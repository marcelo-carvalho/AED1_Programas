#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define M 8

struct jogada {
    int x;
    int y;
};
typedef struct jogada Jogada;

void inicializaTabuleiro();
void adicionaJogada(int i);
void setTabuleiro(int i);
int validaJogada(int i);
void imprimeTabuleiro();
void tabuleiroIA();
int setTabuleiroIA(int turno);

Jogada Lista[M];
int Tabuleiro[M][M];

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i = 0;
    inicializaTabuleiro();
    
    while(i < M){
        setJogada(i);
        if(validaJogada(i) == 1){
            i++;
        }
        else{
            puts("A jogada não é valida...");
            puts("Por favor, tente novamente.");
        }
    }
    puts("Parabéns!!");
    puts("Tabuleiro montado com sucesso.");

    return 1;
}

//Procedimento responsável por atribuir o valor zero em todos os elementos da matriz. 
void inicializaTabuleiro(){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            Tabuleiro[i][j] = 0;
        }
    }
}

//Procedimento responsável por inserir o vetor Lista a jogada realizada pelo usuário. 
//Entrada:
//          turno -> indice do vetor de jogadas. 
void setJogada(int turno){
    int x;
    int y;
    int flagValida = -1; 

    printf("Jogada %i", turno+1);
    printf("\nInforme x: ");
    scanf("%d", &x);

    do{
        if(x < 1 || x >= 9){
            printf("\nValor invalido...");
            printf("\nInforme um valor valido para x: ");
            scanf("%d", &x);
            flagValida = -1;
        }
        else{
            flagValida = 1;
        }
    }while(flagValida == -1);

    printf("Informe y: ");
    scanf("%d", &y);

    do{
        if(y < 1 || y >= 9){
            printf("\nValor invalido...");
            printf("\nInforme um valor valido para y: ");
            scanf("%d", &y);
            flagValida = -1;
        }
        else{
            flagValida = 1;
        }
    }while(flagValida == -1);


    Lista[turno].x = x-1;
    Lista[turno].y = y-1;
    setTabuleiro(turno);
}


//Procedimento para inserior na matriz Tabuleiro a jogada informada pelo usuário.
//Entrada:
//          turno -> indice do vetor de jogadas.
void setTabuleiro(int turno){

    if(Tabuleiro[Lista[turno].x][Lista[turno].y] == 0)
        Tabuleiro[Lista[turno].x][Lista[turno].y] = 1;
    else{
        puts("Posição ocuapda.");
        puts("Informe outra jogada.");
        void setJogada(int i);
    }

    imprimeTabuleiro();
}


//Função para validação da jogada realizada, confere se a posição escolha é uma posição valida no tabuleiro.
//Entrada: 
//          turno -> indice do vetor de jogadas.
//Saída: 
//          0 -> Posição invalida.
//          1 -> posição valida. 
int validaJogada(int turno){
    int i = Lista[turno].x + 1; 
    int j = Lista[turno].y;
    
    //Norte
    while(i < M){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Norte");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i++;
    }

    //Sul
    i = Lista[turno].x - 1;
    j = Lista[turno].y;
    while(i >= 0){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Sul");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i--;
    }

    //Leste
    i = Lista[turno].x;
    j = Lista[turno].y + 1;
    while(j < M){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Leste");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        j++;
    }

    //Oeste
    i = Lista[turno].x;
    j = Lista[turno].y - 1;
    while(j >= 0){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Oeste");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        j--;
    }

    //Nordeste
    i = Lista[turno].x + 1;
    j = Lista[turno].y + 1;
    while(i < M && j < M ){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Nordeste.");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i++;
        j++;
    }

    //Noroeste
    i = Lista[turno].x + 1;
    j = Lista[turno].y - 1;
    while(i < M && j >= 0 ){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Noroeste.");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i++;
        j--;
    }

    //Sudeste
    i = Lista[turno].x - 1;
    j = Lista[turno].y + 1;
    while(i >= 0 && j < M ){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Sudeste.");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i--;
        j++;
    }

    //Sudoeste
    i = Lista[turno].x - 1;
    j = Lista[turno].y - 1;
    while(i >= 0 && j >= 0 ){
        if(Tabuleiro[i][j] == 1){
            puts("Falhou no Sudoeste.");
            Tabuleiro[Lista[turno].x][Lista[turno].y] = 0;
            return 0;
        }
        i--;
        j--;
    }
    return 1;
}

//Função para imprimir a matriz Tabuleiro na tela
void imprimeTabuleiro(){
    printf("\n");
    for(int i = M-1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            printf("|%d|", Tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define M 4
#define N 8

void matrizManual(int mat[][M]);
void matrizAutomatico(int mat[][M]);
void imprimeMatriz(int mat[][M]);
void copiaMatriz(int mat[][M], int cop[][M]);
int comparaMatriz(int mat1[][M], int mat2[][M]);
int buscaMatriz(int mat[][M], int k);
int buscaMaiorMatriz(int mat[][M]);
int buscaLinhaMatriz(int mat[][M], int k);
float mediaMatriz(int mat[][M]);
int acimaMediaMatriz(int mat[][M], float media);
int maiorAcimaDiagMatriz(int mat[][M]);
int maiorAbaixoDigMatriz(int mat[][M]);
int somaColunaMatriz(int mat[][M], int col);
void transpostaMatriz(int mat1[][M], int mat2[][M]);

int menu();
int matrizOpcao();

struct jogada {
    int x;
    int y;
};
typedef struct jogada Jogada;

void setJogada(int turno);
void inicializaTabuleiro();
void adicionaJogada(int i);
void setTabuleiro(int i);
int validaJogada(int i);
void imprimeTabuleiro();
void tabuleiroIA();
int setTabuleiroIA(int turno);
void imprimeLista();

Jogada Lista[N];
int Tabuleiro[N][N];

int main(){
    int mat[M][M];
    int mat2[M][M];
    int copia[M][M];
    int transposta[M][M];
    int index, k, cont = 0;
    int i = 0;

    setlocale(LC_ALL, "Portuguese");

    do{
        index = menu();
        switch(index){
            case 1:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);

                copiaMatriz(mat,copia);
                puts("Matriz original.");
                imprimeMatriz(mat);
                puts("Matriz copiada;");
                imprimeMatriz(copia);
                break;
            case 2:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);
                puts("Matriz 2");
                if(matrizOpcao())
                    matrizManual(mat2);
                else
                    matrizAutomatico(mat2);
                if(comparaMatriz(mat,mat2))
                    puts("Matrizes são iguais");
                else 
                    puts("Matrizes são diferentes");
                puts("Matriz 1");
                imprimeMatriz(mat);
                puts("Matriz 2");
                imprimeMatriz(mat2);
                break;
            case 3:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);
                puts("Informe um valor a ser buscado na função.");
                scanf("%d", &k);
                cont = buscaMatriz(mat,k);
                printf("\nO valor %d apareceu %d vazes.", k, cont);
                break;
            case 4:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);
                k = buscaMaiorMatriz(mat);
                int linha = buscaLinhaMatriz(mat,k);
                if(linha != -1)
                    printf("\nO maior valor foi %d e foi encontrado na linha %d\n", k, linha);
                else 
                    puts("Valor não encontrado");
                imprimeMatriz(mat);
                break;
            case 5:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);
                float media = mediaMatriz(mat);
                cont = acimaMediaMatriz(mat, media);
                printf("\nForam encontrados %d valores acima da media %0.2f.\n", cont, media);
                imprimeMatriz(mat);
                break;
            case 6:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);
                int diag = maiorAcimaDiagMatriz(mat);
                printf("\nO maior valor acima da diagonal principal eh: %d\n", diag);
                imprimeMatriz(mat);
                break;
            case 7:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);
                int diagAc = maiorAcimaDiagMatriz(mat);
                int diagBc = maiorAbaixoDigMatriz(mat);
                printf("\nO maior valor acima da diagonal eh %d e o maior valor abaixo da diagonal eh %d;\n", diagAc, diagBc);
                printf("\nO a diferenca entra elas eh %d\n", diagAc - diagBc);
                imprimeMatriz(mat);
                break;
            case 8:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);
                int col = 0;
                int somaCol = 0;
                printf("\nInforme o valor da coluna que se deseja saber a soma dos valores:");
                scanf("%d", &col);
                if(col < M && col > 0){
                    somaCol = somaColunaMatriz(mat,col);
                    printf("\nO Valor da soma eh: %d\n", somaCol);
                    imprimeMatriz(mat);
                }
                else
                    puts("Valor informado de coluna nao eh valido"); 
                break;
            case 9:
                if(matrizOpcao())
                    matrizManual(mat);
                else
                    matrizAutomatico(mat);
                transpostaMatriz(mat,transposta);
                puts("Matriz original");
                imprimeMatriz(mat);
                puts("Matriz transposta");
                imprimeMatriz(transposta);
                break;
            case 10:
                inicializaTabuleiro();
                while(i < N){
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
                imprimeTabuleiro();
                imprimeLista();
                break;
            default:
                index = 0;
                break;
        }
    }while(index != 0);

    return 1;
}

//Procedimento para preencher uma matriz com entradas feitas pelo usuário.
//Entrada:
//          mat -> matriz a ser preenchida. 
void matrizManual(int mat[][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            printf("Mat[%d][%d] = ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
}

//Procedimento para preencher uma matriz automaticamente com números inteiros de 1 a 100.
//Entrada:
//          mat -> matriz a ser preenchida. 
void matrizAutomatico(int mat[][M]){
    srand(time(NULL));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            mat[i][j] = rand() % 100;
        }
    }
}

//Procedimento para imrpimir valores de uma matriz. 
//Entrada:
//          mat -> matriz a ser impressa na tela. 
void imprimeMatriz(int mat[][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            printf("Mat[%d][%d] = %d\t", i,j, mat[i][j]);
        }
        printf("\n");
    } 
}

//Função para copiar uma matriz para outra matriz. 
//Entrada:
//          mat -> matriz contendo valores.
//          cop -> matriz  para onde serão copiados os valores.
void copiaMatriz(int mat[][M], int cop[][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            cop[i][j] = mat[i][j];
        }
    }
}

//Função para comparar duas matrizes.
//Entrada:
//          mat1 -> matriz de referÊncia.
//          mat2 -> matriz a ser comparada.
//Saídas:
//          0 -> mat2 não é igual a mat1.
//          1 -> mat2 é igual a mat1.
int comparaMatriz(int mat1[][M], int mat2[][M]){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(mat1[i][j] != mat2[i][j])
                return 0;
        }
    }
    return 1;
}

//Função procura na matriz o valor k informado para o usuário e retorna 
//quantas vezes este valor foi encontrado na matriz. 
//Entrada:
//          mat -> matriz onde se deseja buscar o valor.
//          k -> valor que se deseja procurar na matriz.
//Saida:
//          count -> quantidade de vezes que o valor k apareceu na matriz.
int buscaMatriz(int mat[][M], int k){
    int cont = 0;
    for(int i =0; i < M; i++){
        for(int j =0; j < M; j++){
            if(mat[i][j] == k)
                cont++;
        }
    }
    return cont;
}

//Função percorre a matriz e compara todos os valores em busca do maior. 
//Entrada: 
//          mat -> matriz que se deseja buscar maior valor. 
//Saída:
//          maior -> retorna o maior valor encontrado na matriz. 
int buscaMaiorMatriz(int mat[][M]){
    int maior = 0;
    for(int i=0; i < M; i ++){
        for(int j=0; j < M; j++){
            if(mat[i][j] > maior)
                maior = mat[i][j];
        }
    }
    return maior;
}

//Função busca por um determinada valor na matriz e retorna a linha onde este valor foi encontrado.
//Entrada:
//          mat -> matriz onde se deseja procurar o valor.
//          k -> valor que se deseja procurar na matriz.
//Saída:
//          retorna a linha, caso valor encontrado.
//          -1 -> caso valor não seja encontrado na matriz. 
int buscaLinhaMatriz(int mat[][M], int k){
    for(int i=0; i < M; i ++){
        for(int j=0; j < M; j++){
            if(mat[i][j] == k)
                return i;
        }
    }
    return -1; //caso valor não encontrado.
}

//Função recebe uma matriz e percorre seus elementos para calcular a media da mesma. 
//Entrada:
//          mat -> matriz da qual se deseja calcular a média. 
//Saída:
//          resultado da media dos elementos da matriz. 
float mediaMatriz(int mat[][M]){
    float media = 0;
    int cont = 0;
    
    for(int i=0; i < M; i++){
        for(int j =0; j < M; j++){
            media += mat[i][j];
            cont++;
        }
    }
    return media/cont;
}

//Função recebe uma matriz e um valor medio, a função irá percorrera os elementos da matriz e comparar 
//cada um deles com o valor media. Caso valor seja maior que media incrementa-se uma unidade na variável cont. 
//Entrada:
//          mat -> matriz que sera analisada. 
//          media -> valor da media para comparar.
//Saída:
//          numero de valores que são maiores que media. 
int acimaMediaMatriz(int mat[][M], float media){
    int cont = 0;
    for(int i =0; i <M; i++){
        for(int j = 0; j <M; j++){
            if(mat[i][j] > media)
                cont++;
        }
    }
    return cont;
}

//Função para determinar o maior valor acima da diagonal principal. 
//Entrada:
//          mat -> matriz a ser analisada. 
//Saíad:
//          retorna o maior valor acima da diagonal principal. 
int maiorAcimaDiagMatriz(int mat[][M]){
    int maior = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < i; j++){
            if(maior < mat[i][j])
                maior = mat[i][j];
        }
    }
    return maior;
}

//Função para determinar o maior valor abaixo da diagonal principal. 
//Entrada:
//          mat -> matriz a ser analisada. 
//Saíad:
//          retorna o maior valor abaixo da diagonal principal. 
int maiorAbaixoDigMatriz(int mat[][M]){
    int maior = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(j < i){
                if(mat[i][j] > maior)
                    maior = mat[i][j];
            }
                
        }
    }
    return maior;
}

//Função para calcular a soma dos valores de uma dada coluna de uma matriz. 
//Entrada:
//          vet -> Matriz a ser analisada.
//          col -> coluna que se deseja saber a soma dos valores.
//Saída: 
//          Resultado da soma dos valores da coluna. 
int somaColunaMatriz(int mat[][M], int col){
    int soma = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            if(j == col)
                soma += mat[i][j];
        }
    }
    return soma;
}

//Procedimento para criar a matriz transposta de uma matriz dada.
//Entradas:
//          mat1 -> matriz original.
//          mat2 -> matriz que recebera a transposta de mat1.
void transpostaMatriz(int mat1[][M], int mat2[][M]){
    for(int i = 0; i < M; i ++){
        for(int j = 0; j < M; j++){
            mat2[j][i] = mat1[i][j];
        }
    }
}


//Função de menu para da forma que matriz sera preenchida.
//Saída:
//          0 -> Matriz preenchida automaticamente.
//          1 -> Matriz preenchida pelo usuário. 
int matrizOpcao(){
    char opcao = '\0';
    int resp = -1;

    do{

        setbuf(stdin,NULL);
        puts("Deseja preecher a matriz manualmente? (S/N)");
        scanf("%c%*c", &opcao);  
        setbuf(stdin,NULL);
        if(opcao == 's' || opcao == 'S')
            resp = 1;
        else if(opcao == 'n' || opcao == 'N')
            resp = 0;
        else{
            puts("Opcao invalida...");
            resp = -1;
        }
    }while(resp == -1);

    return resp;
}


//Função cria um menu com as opções possíveis. 
int menu(){
    int index = 0;
    puts("\n=====================LISTA DE EXERCICIOS 10=====================\n"
             "\nEscolha uma das opcoes abaixo: \n");
    do{
        puts("1 - Atividade 1.\n"
             "2 - Atividade 2.\n"
             "3 - Atividade 3.\n"
             "4 - Atividade 4.\n"
             "5 - Atividade 5.\n"
             "6 - Atividade 6.\n"
             "7 - Atividade 7.\n"
             "8 - Atividade 8.\n"
             "9 - Atividade 9.\n"
             "10 - Atividade 10.\n"
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 10)
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}

//Procedimento responsável por atribuir o valor zero em todos os elementos da matriz. 
void inicializaTabuleiro(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
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

    if(Tabuleiro[Lista[turno].x][Lista[turno].y] == 0) //Testa se posição não está ocupada
        Tabuleiro[Lista[turno].x][Lista[turno].y] = 1; //ocupa posição
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
    while(i < N){
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
    while(j < N){
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
    while(i < N && j < N ){
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
    while(i < N && j >= 0 ){
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
    while(i >= 0 && j < N ){
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
    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            printf("|%d|", Tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Função para imprimir os valores de X e Y do vetor Lista
void imprimeLista(){
    printf("\n");
    printf("Lista de Jogadas");
    for(int i =0; i < N; i++){
        printf("\n x = %d, y = %d", Lista[i].x, Lista[i].y);
    }
    printf("\n");
}
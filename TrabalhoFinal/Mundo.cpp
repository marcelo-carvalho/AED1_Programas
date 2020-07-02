//Classe Mundo cria uma matriz de char onde serão inseridos os agentes. 
//Ao ser chamada a classe aloca dinamicamente as posições da matriz e as destroi quando encerra o programa. 
//A classe Mundo também é responsável por genrenciar os agentes no mundo. 

#include "Mundo.h"
#include "Agente.h"
#include "Walls.h"
#include "Presa.h"
#include "Predador.h"

//Inicializa a matriz de mundo atribuindo null para todas as posições. 
void Mundo::inicializa() {
    std::cout<<"inicializando mundo..."<< std::endl;

    for (int i=0;i<M;i++)
        for (int j=0;j<N;j++)
            matriz[i][j] = NULL;
}

//Função para imprimir conteúdo de mundo
void Mundo::imprimir() {
    for (int i = 0; i < M ; i++) {
        for (int j = 0 ; j < N; j++) {
            std::cout << tipoAgente(matriz[i][j]) << " | " ;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//Método para salvar o estado atual de mundo. 
void Mundo::salvar(std::string nome_arquivo) {
    nome_arquivo.append(".txt");
    
    //Abre o arquivo
    FILE * fp;
    fp = fopen(nome_arquivo.c_str(),"w");
    
    //Grava quantidade de linha
    int aux = M;
    fprintf(fp, "%d", aux);
    fputc(' ',fp);
    //Grava quantidade de colunas
    aux = N;
    fprintf(fp, "%d", aux);
    fputc('\n',fp);

    //Grava matriz
    for (int i = 0; i < M ; i++) {
        for (int j = 0 ; j < N; j++) {
            if(matriz[i][j] == NULL){
                fprintf(fp, "%d ", 0);
            }
            else if(matriz[i][j] != NULL){
                fprintf(fp, "%d ", matriz[i][j]->tipo);
            }
        }
        fputc('\n',fp);
    }
    fputc('\n',fp);
    fclose(fp);
}

//Método para carregar um estado salvo de mundo. 
void Mundo::carregar(std::string nome_arquivo) {
    int linha;
    int coluna;
    int temp;
    FILE * fp;
    
    nome_arquivo.append(".txt");
    fp = fopen(nome_arquivo.c_str(),"r");
    
    //Faz a leitura do tamanho da matriz
    fscanf(fp,"%d",&a);
    fscanf(fp,"%d",&b);

    //Percorre o arquivo buscando pelos objetos
    for (int i = 0; i < a ; i++) {
        for (int j = 0 ; j < b; j++) {
            fscanf(fp,"%d",&temp);
            if(temp == 0){ //Tipo NULL
                matriz[i][j] = NULL;
            }
            else if (temp == 1){ //Tipo walls
                Walls * wall;
                wall = new Walls;
                wall->inicializa(this,i,j);
                matriz[i][j] = wall; 
            }
            else if (temp == 2){ //Tipo presa
                Presa * presa;
                presa = new Presa;
                presa->inicializa(this,i,j); 
                matriz[i][j] = presa;
            }
            else if (temp == 3){ //Tipo predador
                Predador * predador;
                predador = new Predador;
                predador->inicializa(this,i,j); 
                matriz[i][j] = predador;
            }
        }
    }
    fclose(fp);
}

//Retorno o tipo de agente 
int Mundo::tipoAgente(Agente * a) {
    return a == NULL ? 0 : a->tipo;
}
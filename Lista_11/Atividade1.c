#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

typedef struct coordenada{
    int x;
    int y;
    int z;
} Coordenada;

int criaArquivo();
int criaArquivoManual();
int validaEscolha();
float leArquivo(int);
float calcDistancia(Coordenada, Coordenada);

int main(){
    Coordenada coord;
    int cont, escolha;
    float soma = 0;

    puts("Desaja criar o arquivo automaticamente?");
    escolha = validaEscolha();
    if(escolha == 0)
        cont = criaArquivo();
    else 
        cont = criaArquivoManual();

    if(cont == 0)
        return 0;
    else
        printf("\nForam inseridas %d coordenadas.", cont);

    soma = leArquivo(cont);
    if(soma == 0)
        return 0;
    else
        printf("\nA soma da distância entre a coordenadas é: %f", soma);
    
}


//Função para criar o arquivo .dat do tipo binário contendo as coordenadas de forma automática.
//Saídas:
//          0 -> caso algum problema tenha ocorrido durante a execução (arquivo não encontrado, falha de escrita etc.).
//          cont -> indicando a quantidade de entradas foram escritas no arquivo. 
int criaArquivo(){
    FILE *fp;
    int aux, cont = 0;
    Coordenada coord;
    srand(time(NULL));
    
    if((fp = fopen("coordenadas.dat", "wb")) == NULL){
        puts("Arquivo não criado");
        return 0;
    }

    do{
        coord.x = rand() % 100;
        coord.y = rand() % 100;
        coord.z = rand() % 100;
       
        if(fwrite(&coord,1,sizeof(Coordenada),fp) != sizeof(Coordenada)){
            puts("Um erro ocorreu durante a gravação.");
            puts("Programa será finalziado.");
            fclose(fp);
            return 0;
        }
        printf("\nCoordanada[%d] (x = %d, y = %d, z = %d) foi adicionada ao arquivo.\n", cont+1, coord.x, coord.y, coord.z);
        cont++;
        puts("Deseja adicionar outro coordenada ao arquivo? (S/N)");
        aux = validaEscolha();
        if(cont < 2 && aux == 1){//Condição para empedir usuário tentar entrar apenas com uma coordenada.
            puts("Pelo menos duas coordenadas são necessárias para o funcionamento do programa.");
            puts("Uma nova coordenada será inserida automaticamente.");
            aux = 0;
        }
    } while(aux == 0 && cont < N);

    fclose(fp);
    return cont;
}

//Função para criar o arquivo .dat do tipo binário contendo as coordenadas de forma manual.
//Saídas:
//          0 -> caso algum problema tenha ocorrido durante a execução (arquivo não encontrado, falha de escrita etc.).
//          cont -> indicando a quantidade de entradas foram escritas no arquivo. 
int criaArquivoManual(){
    FILE *fp;
    int aux, cont = 0;
    Coordenada coord;
    srand(time(NULL));
    
    if((fp = fopen("coordenadas.dat", "wb")) == NULL){ //Verifica se não houve falha ao tentar abrir o arquivo.
        puts("Arquivo não criado");
        return 0;
    }

    do{
        printf("Informe valor de x: ");
        scanf("%d%*c", &coord.x);
        printf("Informe valor de y: ");
        scanf("%d%*c", &coord.y);
        printf("Informe valor de z: ");
        scanf("%d%*c", &coord.z);
       
        if(fwrite(&coord,1,sizeof(Coordenada),fp) != sizeof(Coordenada)){ //Faz a leitura do bloco de bytes e executa condição em caso de falha. 
            puts("Um erro ocorreu durante a gravação.");
            puts("Programa será finalziado.");
            fclose(fp);
            return 0;
        }
        printf("\nCoordanada[%d] (x = %d, y = %d, z = %d) foi adicionada ao arquivo.\n", cont+1, coord.x, coord.y, coord.z);
        cont++;
        puts("Deseja adicionar outro coordenada ao arquivo? (S/N)");
        aux = validaEscolha();
        if(cont < 2 && aux == 1){ //Condição para empedir usuário tentar entrar apenas com uma coordenada. 
            puts("Pelo menos duas coordenadas são necessárias para o funcionamento do programa.");
            puts("Uma nova coordenada será inserida automaticamente.");
            aux = 0;
        }
    } while(aux == 0 && cont < N);

    fclose(fp);
    return cont;
}

//Função para validação de escolha do usuário. Textbox Sim ou Não.
//Saída:
//          0 -> Sim
//          1 -> Não
int validaEscolha(){
    char resp;
    scanf("%c%*c", &resp);
    if(resp == 110 || resp == 78)
        return 1;
    else if (resp == 115 || resp == 83)
        return 0;
    else{
        puts("Opção invalida... Informa uma opção valida.");
        validaEscolha();
    }
}

//Função para executar a leitura do arquivo.
//Entrada:
//          cont -> quantidade de elementos escritos no arquivo.
//Saída:
//          0 -> caso algum problema tenha ocorrido durante a execução (arquivo não encontrado, falha de escrita etc.).
//          soma -> resultado da soma das distâncias entre as coordenadas. 
float leArquivo(int cont){
    FILE *fp;
    Coordenada c1, c2;
    float soma = 0;

    if((fp = fopen("coordenadas.dat","rb")) == NULL){
        puts("Arquivo .dat não pode ser criado/encontrado.");
        puts("Programa será encerrado.");
        return 0;
    }

    if(fread(&c1,1,sizeof(Coordenada), fp) == sizeof(Coordenada)){
        cont--;
        while(cont > 0){
            if(fread(&c2,1,sizeof(Coordenada), fp) == sizeof(Coordenada)){
                cont--;
                soma += calcDistancia(c1,c2);
                printf("\nX1 = %d, \tY1 = %d, \tZ1 = %d", c1.x,c1.y,c1.z);
                printf("\nX2 = %d, \tY2 = %d, \tZ2 = %d", c2.x,c2.y,c2.z);
                printf("\nDistância %f\n",calcDistancia(c1,c2));
            }
            else{ //Em caso de falha de leitura. 
                puts("Problemas na leitura do arquivo.");
                puts("Programa será encerrado.");
                return 0;
            }
            c1 = c2;
        }
    }
    else{//Em caso de falha de leitura. 
        puts("Problemas na leitura do arquivo.");
        puts("Programa será encerrado.");
        return 0;
    }

    fclose(fp);
    return soma;
}

//Função para calcular a distância euclidiana entre as coordenadas informadas. 
//Entrada:
//          c1 -> struct de coordenadas.
//          c2 -> estruct de coornedasas.
//Saída:
//          resultado da distância euclidiana entre C1 e C2.
float calcDistancia(Coordenada c1, Coordenada c2){
    return sqrt(pow(c2.x - c1.x,2) + pow(c2.y - c1.y,2) + pow(c2.z - c1.z,2));
}
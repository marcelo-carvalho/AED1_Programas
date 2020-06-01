#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct aluno {
    int matricula;
    char nome[50];
    int idade;
    char telefone[30];
    float renda;
    int nota;
} Aluno;

Aluno List[N];
int Cont = 0; //Contador Global
int flagSalvar = 0;  //0 Salvo - 1 Não Salvo.

void addAluno();
void buscaAluno();
void listaAluno();
void maiorNota(); 
void rendaMedia(); 
void imprimeAluno(Aluno aluno); 
void salvaList(); 
void abreList();

int menu();
int validaEscolha();

int main(){
    int index;
    do{
        index = menu();
        switch(index){
            case 1:
                addAluno();
                break;
            case 2:
                listaAluno();
                break;
            case 3:
                rendaMedia();
                break;
            case 4:
                printf("\nA mairo nota é de: ");
                maiorNota();
                break;
            case 5:
                buscaAluno();
                break;
            case 6:
                salvaList();
                break;
            case 7:
                abreList();
                break;
            case 0:
                if(flagSalvar == 1){
                    puts("Modificações feitas serão perdidas");
                    puts("Deseja salvar? (S/N)");
                    if(validaEscolha() == 0)
                        salvaList();
                    else
                        puts("Obrigado por usar.");
                }
                break;
        }
    }while(index != 0);
    return 1;
}

//Procedimento para adicionar um novo aluno no vetor global List.
//Este procedimento é único que controla o incrimento de Cont uma váriavel global que determina a atual posição
//do vetor global List. 
void addAluno(){
    if(Cont < N){ //Garante que vetor não esteja cheio.
        printf("Número de matrícula: ");
        scanf("%d%*c", &List[Cont].matricula);
        printf("Nome do aluno: ");
        gets(List[Cont].nome);
        printf("Idade do aluno: ");
        scanf("%d%*c", &List[Cont].idade);
        printf("Telefone: ");
        gets(List[Cont].telefone);
        printf("Renda: ");
        scanf("%f%*c", &List[Cont].renda);
        printf("Nota: ");
        scanf("%d%*c", &List[Cont].nota);
    }
    else{ //Condição para quando vetor esteja cheio.
        puts("Operação falhou!");
        puts("Lista está cheia.");
    }
    Cont++;
    puts("Aluno Cadastrado.");
    flagSalvar = 1;
}

//Proceidmento para buscar um valor de matricula entre os alunos cadastrados no vetor List.
//No momento em que o valor de matrícula é encontrado procedimento é encerrado voltando ao vetor principal. 
//Caso valor não seja encontrado, uma mensagem informado o insucesso é mostrado ao usuário e então retorna o menu principal.
void buscaAluno(){
    int mat;
    int i;

    if(Cont == 0){ //Garante que a lista não esteja vazia. 
        puts("Operação falhou.");
        puts("Lista vázia.");
        return;
    } 
    
    printf("Número de Matrícula: "); //Pede valor de matrícula que se deseja buscar.
    scanf("%d", &mat);
    for(i = 0; i < Cont; i++){
        if(List[i].matricula == mat){
            imprimeAluno(List[i]);
            return;
        }
    } 
    
    puts("Aluno não encontrado.");
}

//Procedimento para listar os alunos que estão gravados no vetor global List.
//Procedimento imrpime mensagem de erro na tela caso o vetor global Lista esteja vázio.
//A variável global Cont garante que sejam impresssos apenas os campos ocupados do vetor. 
void listaAluno(){
    int i;
    if(Cont == 0){ //Garante que a lista não esteja vazia. 
        puts("Operação falhou.");
        puts("Lista vázia.");
        return;
    }

    for(i = 0; i < Cont; i++){
        imprimeAluno(List[i]);
    }
}

//Função para buscar entre os alunos cadastrados no vetor Global List qual possui a maior nota.
//Se função for chamada com vetor vazio a mesma reporta um erro e retorna ao menu principal.
void maiorNota(){
    Aluno maior;
    maior.nota = 0;
    int i;

    if(Cont == 0){ //Garante que a lista não esteja vazia. 
        puts("Operação falhou.");
        puts("Lista vázia.");
        return;
    }

    for(i = 0; i < Cont; i ++){
        if(List[i].nota > maior.nota){
            maior = List[i];
        }
    }
    imprimeAluno(maior);
}

//Procedimento para caluclar a renda media de todos os alunos presentes no vetor global List.
//Se função for chamada com vetor vazio a mesma reporta um erro e retorna ao menu principal.
void rendaMedia(){
    float renda = 0;
    int i;
    
    if(Cont == 0){ //Garante que a lista não esteja vazia. 
        puts("Operação falhou.");
        puts("Lista vázia.");
        return;
    }

    for(i = 0; i <Cont; i++){
        renda += List[i].renda;
    }
    renda /= Cont;
    printf("A renda média é: $ %.2f", renda);
}

//Procedimento para imprimer os dados do aluno na tela.
void imprimeAluno(Aluno aluno){  
    printf("\n\nMatrícula: %i \tNome: %s", aluno.matricula, aluno.nome);
    printf("\nIdade: %d \tTelefone: %s", aluno.idade, aluno.telefone);
    printf("\nRenda: $%.2f \tNota: %d", aluno.renda, aluno.nota);
}

//Procedimento para salvar os dados fornecedisos pelo usuário em um arquivo a escolha do mesmo.
//Qualquer falha de gravação ou para criação do arquivo retorna uma falha finalizando o programa.
void salvaList(){
    FILE *fp;
    int i;
    char arquivo[50];

    if(Cont == 0){ //Garante que a lista não esteja vazia. 
        puts("Operação falhou.");
        puts("Lista vázia.");
        return;
    } 

    setbuf(stdin, NULL);
    printf("Nome do arquivo: ");
    gets(arquivo);
    strcat(arquivo, ".dat");

    if((fp = fopen(arquivo, "wb+")) == NULL){ //Mesmo que o arquivo já existe, este será sobrescrito.
        puts("Arquivo não criado");
        return;
    }

    for(i = 0; i < Cont; i++){
        if(fwrite(&List[i],1,sizeof(Aluno),fp) != sizeof(Aluno)){
            puts("Um erro ocorreu durante a gravação.");
            puts("Programa será finalziado.");
            return;
        }
    }
    fclose(fp);

    puts("Arquivo salvo.");
    flagSalvar = 0;
}

//Procidmento para buscar um determinado arquivo escolhido pelo usuário.
//Em caso do arquivo não ser encontrado, uma mensagem de erro aparece e finalzia o programa. 
void abreList(){
    FILE *fp;
    char arquivo[50];

    setbuf(stdin,NULL);
    printf("Nome do arquivo: ");
    gets(arquivo);
    strcat(arquivo, ".dat");

    if((fp = fopen(arquivo, "rb")) == NULL){
        puts("Falha ao abrir o arquivo.");
        return;
    }

    while(fread(&List[Cont],1,sizeof(Aluno), fp) == sizeof(Aluno) ){
        Cont++;
    }
    puts("Arquivo carregado.");
}

//Função gera um menu, com opções de escolha para o usuário.
//Saída:
//          index -> contém a opção escolhida pelo usuário.
int menu(){
    int index = 0;
    puts("\n=====================Cadastro de Alunos=====================\n"
             "\nEscolha uma das opcoes abaixo: \n");
    do{
        puts("1 - Cadastrar.\n"
             "2 - Listar.\n"
             "3 - Renda Média.\n"
             "4 - Maior Nota.\n"
             "5 - Pesquisar Matrícula.\n"
             "6 - Salvar.\n"
             "7 - Abrir.\n"
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 7) //Garante a faixa de escolhas possíveis. 
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}

//Função para validação de escolha do usuário. Textbox Sim ou Não.
//Saída:
//          0 -> Sim
//          1 -> Não
int validaEscolha(){
    char resp;
    setbuf(stdin,NULL);
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
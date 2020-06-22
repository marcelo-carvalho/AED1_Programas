#include <iostream>
#include "Disciplina.h"
#include "Aluno.h"

#define N 10

int menu();
void cadastrarAluno();
void cadastrarDisciplina();
void listarAluno();
void cadastrarNotas();
void exibirNota();
void maiorNota();
int buscarAluno();

Aluno alunos[N];
int aluno_counter = -1;

int main(){
    int index = 0;

    do{ 
        index = menu();
        switch(index){
            case 1:
                cadastrarAluno();
                break;
            case 2:
                cadastrarDisciplina();
                break;
            case 3:
                cadastrarNotas();
                break;
            case 4:
                listarAluno();
                break;
            case 5:
                exibirNota();
                break;
            case 6:
                maiorNota();
                break;
            case 0: 
                break;
        }


    }while(index != 0);

}

//Cadastra aluno
void cadastrarAluno(){
    std::string nome;
    std::string email;
    int matricula; 
    
    aluno_counter++; //Contador de alunos. 
    
    //Garante que o número maximo de alunos não seja ultrapassado. 
    if(aluno_counter == N ){
        std::cout << "Numero de alunos excedido." << std::endl;
        return;
    }
    
    std::getline(std::cin, nome);
    std::cout << "Nome do Aluno: ";
    std::getline(std::cin, nome);
    alunos[aluno_counter].setNome(nome);

    std::cout << "Numero de Matrícula: ";
    std::cin >> matricula;
    alunos[aluno_counter].setMatricula(matricula);
    std::fflush(stdin);

    std::getline(std::cin, nome);
    std::cout << "Email do Aluno: ";
    std::getline(std::cin, email);
    alunos[aluno_counter].setEmail(email);
}

//Função para cadastro de disciplina de um aluno com uma matrícula informada. 
void cadastrarDisciplina(){
    Disciplina disciplina;

    //Encerra função caso vetor de alunos esteja vazio. 
    if(aluno_counter == -1){
        std::cout << "Não existem alunos." << std::endl;
        return; 
    }

    //Encerra função caso aluno buscado não exista. 
    int index = buscarAluno();
    if(index == -1 ){
        std::cout << "Aluno não encontrado." << std::endl;
        return; 
    }

    std::string nome;
    std::cout << "Nome da Disciplina: ";
    std::cin >> nome;
    disciplina.setNome(nome);

    int codigo;
    std::cout << "Código da Disciplina: ";
    std::cin >> codigo;
    disciplina.setCodigo(codigo);

    alunos[aluno_counter].addDisciplina(disciplina);
}

//Adiciona notas para um aluno com número de matrícula informado. 
//Função é encerrada caso não seja encontrado o aluno. 
void cadastrarNotas(){
    
    if(aluno_counter == -1){
        std::cout << "Não existem alunos." << std::endl;
        return; 
    }
    
    int index = buscarAluno();

    if(index == -1 ){
        std::cout << "Aluno não encontrado." << std::endl;
        return; 
    }

    alunos[index].addNota();
}

//Lista os alunos cadastrados no vetor alunos. 
void listarAluno(){
    if(aluno_counter == -1){
        std::cout << "Não existem alunos." << std::endl;
        return; 
    }

    for(int i =0; i <= aluno_counter; i++){
        alunos[i].exibir();
    }
}

//Exibe as notas de um aluno com número de matrícula informado. 
void exibirNota(){
    
    //Caso vetor de alunos esteja vazio função é encerrada. 
    if(aluno_counter == -1){
        std::cout << "Não existem alunos." << std::endl;
        return; 
    }

    //Garante que o aluno buscado exista. 
    int index = buscarAluno();
    if(index != -1){
        alunos[index].listar();
    }
    else{
        std::cout << "Aluno informado não existe." <<std::endl;
    }
}

//Busca pela maior nota de uma disciplina de um determinado código informado. 
void maiorNota(){
    int codigo;
    int maior = 0;
    int index = -1;

    if(aluno_counter == -1){
        std::cout << "Não existem alunos." << std::endl;
        return; 
    }

    std::cout << "Informe o código da disciplina: ";
    std::cin >> codigo;

    for(int i =0; i <= aluno_counter; i++){
        if(alunos[i].getNota(codigo) > maior){
            index = i;
            maior = alunos[i].getNota(codigo);
        }
    }
    if(index != -1 ){
        std::cout << "O Aluno com a maior nota na disciplina " << codigo << std::endl;
        std::cout << "\tNome:" << alunos[index].getNome() << "\tMatrícula: " << alunos[index].getMatricula();
    }
    else{
        std::cout << "Não foram encontrdos alunos cadastrados na disciplina informada." << std::endl;
    }
}

//Gera um menu. 
int menu(){
    int index = 0;
    puts("\nEscolha uma das opcoes abaixo: \n");
    do{
        puts("1 - Cadastrar Aluno.\n"
             "2 - Cadastrar Disciplinas.\n"
             "3 - Cadastrar Notas.\n"
             "4 - Listar Alunos.\n"
             "5 - Exibir Notas.\n"
             "6 - Maior Nota.\n"
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 6) //Garante a faixa de escolhas possíveis. 
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}

//Função para buscar um aluno pelo número de matrícula. 
//Caso não seja encontrado retorna -1.
int buscarAluno(){
    int matricula;
    std::cout << "Informe o número de matricula: ";
    std::cin >> matricula;

    for(int i = 0; i <= aluno_counter; i++){
        if(alunos[i].getMatricula() == matricula)
            return i;
    }

    return -1;
}
#include "Aluno.h"

//Construtor padrão
Aluno::Aluno(){
     nome = "\0";
     email = "\0";
     disciplinas = new Disciplina[10];
     matricula = 0;
     disciplinaCounter = -1;
}

//Construtor sobrecarregado
Aluno::Aluno(int new_matricula,  std::string new_nome, std::string new_email, Disciplina new_disciplina){
     matricula = new_matricula;
     nome = new_nome;
     email = new_email;
     disciplinas = new Disciplina[10];
     Aluno::setDisciplina(new_disciplina);
}

//Destrutor
Aluno::~Aluno(){
    nome = "\0";
    email = "\0";
    delete disciplinas;
    matricula = 0;
    disciplinaCounter = 0;
}

void Aluno::setMatricula(int new_matricula){
    matricula = new_matricula;
}

int Aluno::getMatricula(){
    return matricula;
}

void Aluno::setNome(std::string new_Nome){
    nome = new_Nome;
}

std::string Aluno::getNome(){
    return nome;
}

void Aluno::setEmail(std::string new_email){
    email = new_email;
}

std::string Aluno::getEmail(){
    return email;
}

//Função para adicionar uma nova disciplina para um aluno. 
void Aluno::setDisciplina(Disciplina new_disciplina){
    disciplinaCounter++;

    if(disciplinaCounter == 10){
        std::cout << "Número máximo de Disciplinas atingido." << std::endl;
        return;
    }

    disciplinas[disciplinaCounter].setNome(new_disciplina.getNome());
    disciplinas[disciplinaCounter].setCodigo(new_disciplina.getCodigo());
    disciplinas[disciplinaCounter].setNota(new_disciplina.getNota());
    
}

//Exibe as informações de um aluno. 
void Aluno::exibir(){
    std::cout << "Nome: " << getNome();
    std::cout << "\tMatrícula: " << getMatricula();
    std::cout << "\tE-mail: " << getEmail() << std::endl;
    std::cout << "\tDisciplinas: " << std::endl;
    if(disciplinaCounter == -1){
        std::cout << "\tNenhuma Disciplina Cadastrada." << std::endl;    
        return;
    }
    listar();
}

//Lista as disciplinas cadastradas para um aluno. 
void Aluno::listar(){
    int i = 0;
    for(i = 0; i <= disciplinaCounter; i++){
        std::cout << "\t" << disciplinas[i].exibir();
    }
}

void Aluno::addDisciplina(Disciplina new_disciplina){
    setDisciplina(new_disciplina);
}

//Função para adicionar notas para as disciplinas cadastradas para um aluno. 
void Aluno::addNota(){
    if(disciplinaCounter == -1){
        std::cout << "Nenhuma disciplina cadastrada." << std::endl;
        return;
    }

    int nota;

    for(int i=0; i <= disciplinaCounter; i++){
        //Somente as disciplinas com nota -1 poderão receber valor. 
        if(disciplinas[i].getNota() == -1){
            std::cout << disciplinas[i].getNome() << std::endl;
            std::cout << "Nota: ";
            std::cin >> nota;
            disciplinas[i].setNota(nota);
        }
    }
}

//Função para retornar as notas do aluno cadastrados em uma disciplina de código "cod".
int Aluno::getNota(int cod){    
    if(disciplinaCounter == -1){
        return -1;
    }

    for(int i=0; i <= disciplinaCounter; i++){
        if(disciplinas[i].getCodigo() == cod)
            return disciplinas[i].getNota();
    }

    return -1;
}
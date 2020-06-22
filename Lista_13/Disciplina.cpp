#include "Disciplina.h"

Disciplina::Disciplina(){
    nome = "\0";
    codigo = 0;
    nota = -1;
}

Disciplina::Disciplina(std::string new_nome, int new_codigo, int new_nota){
    nome = new_nome;
    codigo = new_codigo;
    nota = new_nota;
}

Disciplina::~Disciplina(){
    nome = "\0";
    codigo = 0;
    nota = 0;
}

void Disciplina::setNome(std::string new_nome){
    nome = new_nome;
}

std::string Disciplina::getNome(){
    return nome;
}

void Disciplina::setCodigo(int new_codigo){
    codigo = new_codigo;
}

int Disciplina::getCodigo(){
    return codigo;
}

void Disciplina::setNota(int new_nota){
    nota = new_nota;
}

int Disciplina::getNota(){
    return nota;
}

//Retorna uma string com as informações cadastradas para a disciplina. 
std::string Disciplina::exibir(){
    return  "\tNome: " + getNome() + "\tCódigo: " + std::to_string(getCodigo()) + "\tNota: " + std::to_string(getNota()) + "\n";
}
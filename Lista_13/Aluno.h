#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include "Disciplina.h"
#include <string.h>

class Aluno{

    private:
    
        int matricula;
        std::string nome;
        std::string email;
        Disciplina *disciplinas;
        int disciplinaCounter;

    public:
        Aluno();
        Aluno(int, std::string, std::string, Disciplina);
        ~Aluno();
        void listar();
        void exibir();
        void addDisciplina(Disciplina);

        void setMatricula(int);
        void setNome(std::string);
        void setEmail(std::string);
        void setDisciplina(Disciplina);
        int getMatricula();
        std::string getNome();
        std::string getEmail();
        void addNota();
        int getNota(int);
};

#endif
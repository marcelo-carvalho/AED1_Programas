#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>

class Disciplina{
    private:
        std::string nome;
        int codigo;
        int nota;

    public:
        Disciplina();
        Disciplina(std::string, int, int);
        ~Disciplina();
        void listar();
        std::string exibir();

        void setNome(std::string);
        void setCodigo(int);
        void setNota(int);
        std::string getNome();
        int getCodigo();
        int getNota();
};

#endif
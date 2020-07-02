#ifndef MUNDO_H
#define MUNDO_H

#include <iostream>
#include "Agente.h"

#define M 10
#define N 10

class Agente;

class Mundo{
	public: 

		Agente * matriz[M][N];
		int a; int b; //Tamanho alternativo para a matriz 
		
		void inicializa();
		void imprimir();
		void carregar(std::string nome_arquivo);
		void salvar (std::string nome_arquivo);
		int tipoAgente(Agente *a);

};

#endif
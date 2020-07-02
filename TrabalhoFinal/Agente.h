#ifndef AGENTE_H
#define AGENTE_H

#include <iostream>
#include "Mundo.h"

#define ANDAR_ALEATORIO 0
#define FUGIR 1
#define PERSEGUIR 2
#define SUBINDO 3
#define DESCENDO 4
#define INDO 5
#define VOLTANDO 6

class Mundo;

class Agente{

	public:
		int x;
		int y;
		int estado = 0; //Os agentes podem assumir diferentes estados. (ex. estado 1 = andar aleatoriamente)
		int tipo = 0; //Define o tipo de agente
		Mundo * mundo; 
		
		int getTipo();
		void inicializa(Mundo * m, int x_inicial, int y_inicial);
		bool podeMover(int novo_x, int novo_y);
		void mover(int novo_x, int novo_y);
		int tipoAgente(Agente *a);

		virtual void decidir() = 0;
    	virtual void executar() = 0;
		void deslocarAleatorio();
};

#endif 
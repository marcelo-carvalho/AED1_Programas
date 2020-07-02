#ifndef PRESA_H
#define PRESA_H

#include <iostream>
#include "Mundo.h"
#include "Agente.h"

class Mundo;

class Presa : public Agente{
			
	public:
        int x_predador;
        int y_predador;
		Presa();
		void decidir();
		void executar();

};

#endif
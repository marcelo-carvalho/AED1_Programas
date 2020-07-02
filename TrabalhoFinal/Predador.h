#ifndef PREDADOR_H
#define PREDADOR_H

#include <iostream>
#include "Mundo.h"
#include "Agente.h"

class Mundo;

class Predador : public Agente{
			
	public:
        int x_presa;
        int y_presa;
		Predador();
		void decidir();
		void executar();
};

#endif
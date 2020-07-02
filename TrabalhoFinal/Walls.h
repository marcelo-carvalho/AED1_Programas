#ifndef WALLS_H
#define WALLS_H

#include <iostream>
#include "Mundo.h"
#include "Agente.h"

class Mundo;

class Walls : public Agente{
			
	public:
		Walls();
		void decidir();
		void executar();

};

#endif
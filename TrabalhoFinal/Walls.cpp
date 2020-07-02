#include "Walls.h"

//Inicializa o objeto do tipo walls 
Walls::Walls(){
	estado = ANDAR_ALEATORIO;
	tipo = 1;
}

void Walls::decidir() {

	switch(estado){
		case ANDAR_ALEATORIO:
			if(x > 0 && y > 0)
				estado = SUBINDO;
			else if(x > 0 && x < M && y == 0 )
				estado = INDO;
			else if(x == M - 1 && y > 0 && y < N)
				estado = DESCENDO;
			else if(x > 0 && x < M && y == N -1)
				estado = VOLTANDO;
			break;
		case SUBINDO:
			if(x >= 0 && y == 0)
				estado = INDO;
				break;
		case INDO:
			if(x == M - 1 && y == 0)
				estado = DESCENDO;
				break;
		case DESCENDO:
			if(x == M - 1 && y == N - 1)
				estado = VOLTANDO;
				break;
		case VOLTANDO:
			if(x == 0 && y == N - 1)
				estado = SUBINDO;
				break;
	}
}

void Walls::executar() {
	switch(estado){
		case ANDAR_ALEATORIO:
			deslocarAleatorio();
			break;
		case SUBINDO:
			mover(x,y-1);
			break;
		case INDO:
			mover(x+1,y);
			break;
		case DESCENDO:
			mover(x,y+1);
			break;
		case VOLTANDO:
			mover(x-1,y);
			break;
	}
}
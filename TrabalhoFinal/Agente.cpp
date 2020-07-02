//Implementação de uma classe pai contendo elementos básicas para existÊncia de um agente no mundo. 
//AS classes filhas poderão incluir metódos construtores para definir tipos e posisções diferentes.

#include "Agente.h"

int Agente::getTipo() {
	return tipo;
}

//Inicializa o agente no mundo com uma posição inicial
void Agente::inicializa(Mundo * m, int x_inicial, int y_inicial) {
	x = x_inicial;
	y = y_inicial;
	mundo = m;
	mundo->matriz[y][x] = this;
}

bool Agente::podeMover(int novo_x, int novo_y) {
	return novo_x < M && novo_y < N  && novo_x >= 0 && novo_y >= 0 && mundo->matriz[novo_y][novo_x] == NULL ;
}

void Agente::mover(int novo_x, int novo_y) {

	if (podeMover(novo_x, novo_y)) {
		mundo->matriz[y][x] = NULL;
		x = novo_x;
		y = novo_y;
		mundo->matriz[y][x] = this;
	}
}

void Agente::deslocarAleatorio() {
	
	int novo_x = (x + rand() % 3 - 1) % M; //Soma um número aleatório entre -1 e 1 e garante que resultado nunca sera > M.
	int novo_y = (y + rand() % 3 - 1) % N; //Soma um número aleatório entre -1 e 1 e garante que resultado nunca sera > N.
	mover(novo_x,novo_y);
	 
}

int Agente::tipoAgente(Agente * a) {
    return a == NULL ? 0 : a->tipo;
}
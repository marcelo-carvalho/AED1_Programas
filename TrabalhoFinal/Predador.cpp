#include "Predador.h"


//Inicializa o objeto do tipo walls 
Predador::Predador(){
    estado = ANDAR_ALEATORIO;
	tipo = 3; //Predador
}

void Predador::decidir(){
    switch(estado){
        case ANDAR_ALEATORIO:
            for(int i = x - 3; i <= x + 3; i++){
                for(int j = y - 3; j <= y + 3; j++){
                    if(Agente::podeMover(i,j) == true){
                        if(mundo->matriz[i][j] != NULL && mundo->matriz[i][j]->tipo == 2){
                            estado = PERSEGUIR;
                            x_presa = i;
                            y_presa = j;
                            break;
                        }
                    }
                }
            }
            break;
        case PERSEGUIR:
            for(int i = x - 3; i <= x + 3; i++){
                for(int j = y - 3; j <= y + 3; j++){
                    if(Agente::podeMover(i,j) == true){
                        if(mundo->matriz[i][j] != NULL && mundo->matriz[i][j]->tipo == 2){
                            estado = FUGIR;
                            x_presa = i;
                            y_presa = j;
                            break;
                        }
                        else{
                            estado = ANDAR_ALEATORIO;
                        }
                    }
                }
            }
            break;
    }
}

void Predador::executar(){
    int novo_x;
    int novo_y;


    switch(estado){
        case ANDAR_ALEATORIO:
            Agente::deslocarAleatorio();
            break;
        case PERSEGUIR:
            if(x > x_presa) novo_x = x - 1;
            else novo_x = x-1;
            if(y > y_presa) novo_y = y + 1;
            else novo_y = y-1;
            Agente::mover(novo_x,novo_y);
            break;
    }
}

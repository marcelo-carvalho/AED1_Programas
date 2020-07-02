#include "Presa.h"


//Inicializa o objeto do tipo walls 
Presa::Presa(){
	estado = ANDAR_ALEATORIO;
	tipo = 2; //Presa
}

void Presa::decidir(){
    switch(estado){
        case ANDAR_ALEATORIO:
            for(int i = x - 2; i <= x + 2; i++){
                for(int j = y - 2; j <= y + 2; j++){
                    if(Agente::podeMover(i,j) == true){
                        if(mundo->matriz[i][j] != NULL && mundo->matriz[i][j]->tipo == 3){
                            estado = FUGIR;
                            x_predador = i;
                            y_predador = j;
                            break;
                        }
                    }
                }
            }
            break;
        case FUGIR:
            for(int i = x - 2; i <= x + 2; i++){
                for(int j = y - 2; j <= y + 2; j++){
                    if(Agente::podeMover(i,j) == true){
                        if(mundo->matriz[i][j] != NULL && mundo->matriz[i][j]->tipo == 3){
                            estado = FUGIR;
                            x_predador = i;
                            y_predador = j;
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

void Presa::executar(){
    int novo_x;
    int novo_y;

    switch(estado){
        case ANDAR_ALEATORIO:
            Agente::deslocarAleatorio();
            break;
        case FUGIR:
            if(x > x_predador) novo_x = x + 1;
            else novo_x = x-1;
            if(y > y_predador) novo_y = y + 1;
            else novo_y = y-1;
            Agente::mover(novo_x,novo_y);
            break;
    }
}

#include <iostream>
#include <string>
#include "Agente.h"
#include "Mundo.h"
#include "Walls.h"
#include "Presa.h"
#include "Predador.h"

int menu();
void atualizaMundo();

Walls wall[5];
Predador predador[5];
Presa presa[5];
Mundo mundo;
int conta_presa =0; 
int conta_predador = 0; 
int conta_walls = 0;

int main(){

	bool salvar = false;
	std::string nomeArquivo;
	int index;
	int aux = 0;
	
	mundo.inicializa();
		
		do{
			index = menu();
			switch(index){
				case 1:
					if(conta_walls < 5){
						wall[conta_walls].inicializa(&mundo, 1,1);
						conta_walls++;
						mundo.imprimir();
						salvar = true;
					}
					else{
						std::cout << "Máximo de walls atingido" << std::endl;
					}
					atualizaMundo();
					break;
				case 2:
					if(conta_presa < 5){
						presa[conta_presa].inicializa(&mundo, rand()%M, rand() %N);
						conta_presa++;
						mundo.imprimir();
						salvar = true;
					}
					else{
						std::cout << "Máximo de presas atingido" << std::endl;
					}
					atualizaMundo();
					break;
				case 3:
					if(conta_predador < 5){
						predador[conta_predador].inicializa(&mundo, rand()%M, rand() %N);
						conta_predador++;
						mundo.imprimir();
						salvar = true;
					}
					else{
						std::cout << "Máximo de predadores atingido" << std::endl;
					}
					atualizaMundo();
					break;
				case 4:
					std::fflush(stdin);
					std::cout << "Nome do arquivo: ";
					std::cin >> nomeArquivo;
					mundo.salvar(nomeArquivo);
					salvar = false;
					break;
				case 5:
					std::fflush(stdin);
					std::cout << "Nome do arquivo: ";
					std::cin >> nomeArquivo;
					mundo.carregar(nomeArquivo);
					conta_presa =0; 
					conta_predador = 0; 
					conta_walls = 0;
					break;
				case 6:
					atualizaMundo();
					mundo.imprimir();
					break;
				case 0:
					if(salvar == true){
						std::cout << "Arquivo não salvo." << std::endl << "Salve antes de fechar o programa." << std::endl;
						index = 7;
					}
					else{
						std::cout << "FIM." << std::endl;
					}
					break;
			}
		}while(index != 0);
	return 0;
}

//Gera um menu. 
int menu(){
    int index = 0;
    puts("\nEscolha uma das opcoes abaixo: \n");
    do{
        puts("1 - Criar um walls.\n"
             "2 - Criar uma presa.\n"
             "3 - Criar um predador.\n"
             "4 - Salvar mundo.\n"
             "5 - Carregar mundo.\n"
			 "6 - Atualiza mundo.\n"
             "0 - Sair.");

            std::cin >> index;
             if(index >= 0 && index <= 6) //Garante a faixa de escolhas possíveis. 
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}

void atualizaMundo(){
    int aux = 0;
    if(conta_walls > 0){
        while(aux < conta_walls){
            wall[aux].decidir();
            wall[aux].executar();
            aux++;
        }
    }
    aux = 0;
    if(conta_predador > 0){
        while(aux < conta_predador){
            predador[aux].decidir();
            predador[aux].executar();
            aux++;
        }
    }
    aux = 0;
    if(conta_presa > 0){
        while(aux < conta_presa){
            presa[aux].decidir();
            presa[aux].executar();
            aux++;
        }
    }
}
#include "pilha.h"

struct calc{
    char f[21]; //formato para impressão
    Pilha*p;
};
typedef struct calc Calc;

Calc* calc_cria (char* f);
void calc_operando(Calc *c, float v);
void calc_operador(Calc *c, char op);
void calc_libera(Calc *c);
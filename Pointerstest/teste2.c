#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned int x = 5, y = 6;
    unsigned int *px, *py;

    px = &x; //Atribuições
    py = &y;

    if(px < py) //Comparações
        printf("py - px = %u\n", (py - px));
    else
        printf("px - py = %u\n", (px - py));

    printf("px = %p", px);
    printf(", *px = %u", *px); //Op. Indireto
    printf(", &px = %p\n", &px); //Op. Endereços

    printf("py = %p", py);
    printf(", *py = %u", *py);
    printf(", &py = %p\n", &py);

    py++; //Incremento

    printf("py = %p", py);
    printf(", *py = %u", *py);
    printf(", &py = %p\n", &py);

    px = py + 5; //Somar inteiros

    printf("px = %p", px);
    printf(", *px = %u", *px); //Op. Indireto
    printf(", &px = %p\n", &px); //Op. Endereços

    printf("px - py = %u\n", (px - py));

    return 0;
}
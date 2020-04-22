#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//Primiera Questão
//Procedimento recebe como argumento 5 variáveis, num1 - num3 sao analiados de forma a se determinar
//qual é o maior e qual é o menor que são atribuidos por referência as as variáveis maior e menor
//respectivamente.
void primeiraAtividade(float num1, float num2, float num3, float *maior, float *menor){
    //Testa o maior número
    if(num1 > num2 && num1 > num3){
        *maior = num1;
    }
    else if(num2 > num1 && num2 > num3){
        *maior = num2;
    }
    else if(num3 > num1 && num3 > num2){
        *maior = num3;
    }

    //Testa o menor número
    if(num1 < num2 && num1 < num3){
        *menor = num1;
    }
    else if(num2 < num1 && num2 < num3){
        *menor =  num2;
    }
    else if(num3 < num1 && num3 < num2){
        *menor = num3;
    }
}

//Segunda Questão
//Procedimento recebe 4 variáveis como argumento sendo num1 - num2 valores que serão processados
//para que o ponteiro *avg receba por referÊncia a media dos três numeros inciais. 
void segundaAtividade(float num1, float num2, float num3, float *avg){
    *avg = (num1 + num2 + num3) / 3;
}

//Terceira Questão
//Função recebe como argumento três variáveis sendo A e B valores inteiros 0 ou 1. 
//Os valores são processados de forma que aoperação lógica ¬ (A ^ B) seja calculada e
//atribuida a *Res.
void terceiraAtviidade(int A, int B, int *Res){
    if(A == 1){
        if(B == 1){
            *Res = 0; // not (1 and 1)
        }
        else{
            *Res = 1; // not (1 and 0)
        }
    }
    else{
        *Res = 1; // not (0 and X)
    }
}

//Quarta Questão
//Procedimento recebe por referêcia 5 numeros inteiros quaisquer, entre eles faz o deslocaento 
//dos valores entre eles e os imprime na tela para o usuário ver seu endereço na memória o valor
//que possui antes e o valor atual. 
void quartaAtividade(int *num1, int *num2, int *num3, int *num4, int *num5){
    int aux1 = *num1, aux2 = *num2, aux3 = *num3, aux4 = *num4, aux5 = *num5;

    //Deslocamento dos valores
    *num1 = aux5;
    *num2 = aux1;
    *num3 = aux2;
    *num4 = aux3;
    *num5 = aux4;
    
    //Apresentação dos resultados
    puts("\tNOME_VARIAVEL \tENDERECO \tVALOR ANTIGO \tVALOR NOVO");
    printf("\n\t\ta \t%p \t\t%d \t\t%d", &num1, aux1, *num1);
    printf("\n\t\tb \t%p \t\t%d \t\t%d", &num2, aux2, *num2);
    printf("\n\t\tc \t%p \t\t%d \t\t%d", &num3, aux3, *num3);
    printf("\n\t\td \t%p \t\t%d \t\t%d", &num4, aux4, *num4);
    printf("\n\t\te \t%p \t\t%d \t\t%d", &num5, aux5, *num5);
}

//Quinta Questão
//Este procedimento declara uma variável de cada tipo char, int, float e double e seus respectivos ponteiros.
//É apresentado para o usuário como saída o endereço que cada variável ocupa e qual é o tamnho desta em bytes. 
void quintaAtividade(){
    char c, *pc = &c;
    int i, *pi = &i;
    float f, *pf = &f;
    double d, *pd = &d;

    printf("\t\nO endereco do char 'c' eh 0x%p . Essa variavel ocupa %d bytes", pc, sizeof(char));
    printf("\t\nO endereco do char 'i' eh 0x%p . Essa variavel ocupa %d bytes", pi, sizeof(int));
    printf("\t\nO endereco do char 'f' eh 0x%p . Essa variavel ocupa %d bytes", pf, sizeof(float));
    printf("\t\nO endereco do char 'd' eh 0x%p . Essa variavel ocupa %d bytes", pd, sizeof(double));
}

//Funções da Sexta Questão
//Procedimento recebe um váriavel inteira como argumento e atribui este valor a uma váriavel local x.
//Esta variável local é impressa na tela mostrando seu indereço e seu conteúdo para o usuário final. 
void misterio1(int xval){
    int x;
    x = xval;
    printf("\n\tmisterio1 -> \tEndereco: %p \tValor: %d", &x, x);
}

//Procedimento recebe um variável inteira como argumento e nada faz com ela. 
//Uma váriavel local é criada y, que por sua vez é impressa ao usário mostrando seu conteúdo e endereço.    
void misterio2(int nada){
    int  y;
    printf("\n\tmisterio2 -> \tEndereco: %p \tValor: %d", &y, y);
    
}

//Procedimento criado para testar os procedimentos misterio1 e misterio2, em si este procedimento não possui
//saídas, estas ficam a cargo dos procedimentos testados. 
void sextaAtividade(){
    misterio1(7);
    misterio2(11);
}

//Funções extras
//Função produz um menu que é apresentado para o usuário e um valor é aguardado. 
//Este valor é verificado pela função para que esteja dentro do limite permitido e
//casso verdadeiro retorna-se o valor da opção desejada 0 para finalizar o programa. 
int menu(){
    int index = 0;
    puts("\n=====================LISTA DE EXERCICIOS 6=====================\n"
             "\nEscolha uma das opcoes abaixo: \n");
    do{
        puts("1 - Primeira Atividade.\n"
             "2 - Secunda Atividade.\n"
             "3 - Terceira Atividade.\n"
             "4 - Quarta Atividade.\n"
             "5 - Quinta Atividade.\n"
             "6 - Sexta Atividade\n"
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 6)
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}

//Função para validar se os valores de entrada A e B são 0 ou 1. As entradas são feitas 
//por referência para que seja corrigido uma vez que é identificado o valor fora do padrão esperado. 
//Caso seja identificado algum valor fora do padrão a função pede um novo valor atribui à váriavel e 
//chama a si mesma para uma nova checagem. Processo continua até que o usuário escolha o valor correto
//Caso os valores estejam corretos a função retorna 1.
int validaBoolean(int *A, int *B){
    if(*A == 0 || *A == 1){
        if(*B == 0 || *B == 1){
            return 1;
        }
        else{
            puts("\tA variavel so pode ser 1 ou 0...");
            puts("\tInforme um novo valor de B.");
            scanf("%d",B);
            validaBoolean(A,B); //Uso da recursividade.
        }
    }
    else{
            puts("\tA variavel so pode ser 1 ou 0...");
            puts("\tInforme um novo valor de A.");
            scanf("%d",A);
            validaBoolean(A,B); //Uso da recursividade.
    }
}
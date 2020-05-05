#include <stdio.h>
#include <stdlib.h>

//Funções das questões
//Recursão
int divide(int, int);
int quantosDigitos(int);
int somaDigitos(int);
int multiplica(int, int);
int progressao(int, int, int);

//Vetores
void atividade6();
void atividade7();
void atividade8();
void atividade9();
void atividade10();
void atividade11();
void atividade12();
void atividade13();
void atividade14();

//Funções auxiliares
int menu();
int testaNumero(int *);
int testaNumero2(int *);
int fibonacci(int);
int func(int);
void ordena(int, int *);


int main(){
    int index;
    int A, B;
    int first, r, n;

    
    do{ 
        index = menu();
        switch(index){
            case 1:
                printf("Informe um dividendo: ");
                scanf("%d", &A);
                printf("Informe um divisior: ");
                scanf("%d", &B);
                printf("A / B = %d", divide(A,B));
                break;
            case 2:
                printf("Informe um numero: ");
                scanf("%d", &A);
                printf("O numero informado possui %d digitos.", quantosDigitos(A));
                break;
            case 3:
                printf("Informe um numero: ");
                scanf("%d", &A);
                printf("A soma dos digitos do numero eh %d.", somaDigitos(A));
                break;
            case 4:
                printf("Informe um multiplicando: ");
                scanf("%d", &A);
                printf("Informe um multiplicador: ");
                scanf("%d", &B);
                printf("A * B = %d", multiplica(A,B));
                break;
            case 5:
                printf("Informe o primeiro termo da progressao: ");
                scanf("%d", &first);
                printf("Informe a razao: ");
                scanf("%d", &r);
                printf("Informe o n-esimo termo desejado: ");
                scanf("%d", &n);
                progressao(first,r,n);
                break;
            case 6:
                atividade6();
                break;
            case 7:
                atividade7();
                break;
            case 8:
                atividade8();
                break;
            case 9:
                atividade9();
                break;
            case 10:
                atividade10();
                break;
            case 11:
                atividade11();
                break;
            case 12:
                atividade12();
                break;
            case 13:
                atividade13();
                break;
            case 14:
                atividade14();
                break;
            case 0:
                break;
        }
    }while(index != 0);

    return 0;
}

//Funções das questões

//Questões de Recursividade

//Função recursiva que realiza a divisão de dois numeros utilizando 
//da subtração do dividendo pelo divisor. 
int divide(int x, int y){
    int z = 1; 

    if(x < 0)
        x = -x;
    if(y < 0)
        y = -y;

    if(y == 0 || x < y)
        return 0;
    else if(x - y > 0)
        z += divide(x-y, y);
   
    return z;
}

//Função determina quantos digitos compõe um número informado.
int quantosDigitos(int A){
    int z = 1;

    if(A == 0)
        return 0;
    else if(A < 10)
        return 1;
    else 
        z += quantosDigitos(A / 10);

    return z;
}

//Função soma os digitos que compçoe um dado numero. 
int somaDigitos(int A){
    int z = 0;

    if(A < 10)
        return A;
    else{
        z = A % 10;
        z += somaDigitos(A / 10);
    }
    return z;
}

//Função multiplica um número utilizando da soma 
int multiplica(A,B){
    int z = A;

    if(B == 0 || A == 0)
        return 0;
    else if (B == 1)
        return A;
    else
        z += multiplica(A, B - 1);
    
    return z;
}

//Calcula e exibe n-enesimo valor de uma progressçao geometrica
int progressao(int a, int r, int n){
    
    int z = a * pow(r,n-1);
    printf("\nN = %d Z = %d", n, z);

    if(n == 1)
        return z;
    else
        z *= progressao(a, r, n-1);
}


//Questões de vetores

void atividade6(){
    int vet[10];

    //Le um veto de 10 posições.
    puts("Informe 10 numeros inteiros:");
    for(int i = 0; i < 10; i++){
        printf("#[%d]: ", i+1);
        scanf("%d", &vet[i]);
    }

    //Imprime o vetor em ordem reversa ao informada pelo usuário. 
    puts("\nValores informados em ordem reversa");
    for(int i = 9; i >= 0; i--){
        printf("\nVet[%d] = %d", i+1, vet[i]);
    }
}

void atividade7(){
    int vet[10];

    //Lê dez valores informados pelo usuario. 
    puts("Informe 10 numeros inteiros:");
    for(int i = 0; i < 10; i++){
        printf("#[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    //Só serão impressos os valores que são equivaletes ao indice do vetor. 
    puts("\nValores compatíveis com o indice do vetor:");
    for(int i = 0; i < 10; i++){
        if(vet[i] == i)
            printf("\nvet[%d] = %d", i, vet[i]);
    }
}

void atividade8(){
    int vet[15];

    for(int i = 0; i < 15; i++){
        vet[i] = rand() % 10;
    }

    puts("Vetor de 15 elementos gerados aleatoreamente:");
     for(int i = 0; i < 15; i++){
        printf("\nVet[%d] = %d", i+1, vet[i]);
    }
}

void atividade9(){
    int vet[15];
    int aux = 0;
    int maior, menor, media = 0;
    int abaixoMedia = 0; 
    int i = 0;

    //Alimenta o vetor com números aleatorios
    while(i < 15){
        aux = rand() % 100;
        if(aux >= 15 && aux <= 40){ //Condição garante que os números estejam dentro do intervalo
            vet[i] = aux;
            i++;
        }
    }

    maior = vet[0]; //Inicializa a váriavel para comparação. 
    menor = vet[i]; //Inicializa a váriavel para comparação. 
    for(i = 0; i < 15; i++){
        media += vet[i]; //Acumulador para calculo da média. 
        
        if(vet[i] < menor) //Condição para menor temperatura.
            menor = vet[i];

        if(vet[i] > maior) //Condição para maior temperatura. 
            maior = vet[i];    
    }

    media = media / 15; //Cálculo da média. 

    //Loop para identificar valores abaixo da média.
    for(i = 0; i < 15; i++){ 
        if(vet[i] < media)
            abaixoMedia++;
    }

    printf("Menor temperatura = %d", menor);
    printf("\nMaior temperatura = %d", maior);
    printf("\nTemperatura media = %d", media);
    printf("\nMedidas abaixo da media = %d", abaixoMedia);
}

void atividade10(){
    int vet[10];
    int aux; 

    //Loop para alimentar o vetor
    for(int i = 0; i < 10; i++){
        if (i % 2 == 0) //Condição para posição multipla de 2
            vet[i] = 1;
        else
            vet[i] = 0;
    }

    //Imprime o vetor. 
    for(int i = 0; i < 10; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
}

void atividade11(){
    int freq[10] = {0,0,0,0,0,0,0,0,0,0};
    int i, index;

    for (i = 0; i < 10; i++){
        printf("#%d: Digite um numero entre 0 e 9: ", i);
        scanf("%d", &index);
        if(testaNumero(&index))
            freq[index]++;
    }

    for(i = 0; i < 10; i++){
        printf("\n%d apareceu %d vezes", i, freq[i]);
    }
    return 0;
}

//A capacidade do vetor foi alterado da original proposta de 100 pois esta acarretando sobrecarga de memória. 
//A capacidade do tipo int também não comporta os valores acima da posição 30 da sequência. 
void atividade12(){
    int vet[30];
    int i;
    
    puts("Vetor foi reduzido pra 30 posicoes para nao ocorrer overload de memoria...");
    //Alimenta o vetor com os valores da sequencia de Fibonacci, de acordo com a posição do vetor. 
    for(i=0; i < 30; i++)
        vet[i] = fibonacci(i);

    //Imprime os valores armazenados no vetor. 
    for(i = 0; i < 30; i++)
        printf("\nvet[%d] = %d", i, vet[i]);
}

void atividade13(){
    int vet[10];

    for(int i =0; i < 10; i ++)
        vet[i] = func(i);

    for(int i=0; i < 10; i ++)
        printf("\nvet[%d] = %d", i, vet[i]);
}

void atividade14(){
    int vet[100];
    int n = 0;
    int i; 

    //n garante uma quantidade máxima de valores desejada pelo usuário 
    //desde que seja menor que 100 e maior que 1.
    puts("Informe a quantidade de valores desejado: ");
    scanf("%d", &n);
    
    int testaNumero2(int *n); //Garante que n esteja entre 1 e 100

    //Loop para alimentar o vetor.
    for(i = 0; i < n; i ++){
        printf("#%d Informe um valor: ", i);
        scanf("%d", &vet[i]);
    }

    //Ordena o vetor
    ordena(n,vet); 
    printf("Segundo menor valor digitado = %d", vet[1]);
}

//Função auxiliares
int menu(){
    int index = 0;
    puts("\n=====================LISTA DE EXERCICIOS 6=====================\n"
             "\nEscolha uma das opcoes abaixo: \n");
    do{
        puts("1 - Atividade 1.\n"
             "2 - Atividade 2.\n"
             "3 - Atividade 3.\n"
             "4 - Atividade 4.\n"
             "5 - Atividade 5.\n"
             "6 - Atividade 6.\n"
             "7 - Atividade 7.\n"
             "8 - Atividade 8.\n"
             "9 - Atividade 9.\n"
             "10 - Atividade 10.\n"
             "11 - Atividade 11.\n"
             "12 - Atividade 12.\n"
             "13 - Atividade 13.\n"
             "14 - Atividade 14.\n"
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 14)
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}

//Função utilizada para garantir que numero testado esteja sempre entre 0 e 9.
int testaNumero(int *n){
    if(*n > 9){
        puts("Valor deve ser menor que 9...");
        printf("Informe novo valor: ");
        scanf("%d", n);
        testaNumero(n);
    }
    else if (*n < 0){
        puts("Valor deve ser maior que 0...");
        printf("Informe novo valor: ");
        scanf("%d", n);
        testaNumero(n);
    }
    else 
        return 1;
}

//Função recursiva que retorna um valor da sequencia de fibonacci
//da posição requirida pelo usuario. 
int fibonacci(int n){
    if(n == 0 )
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

//Função para calcular valor de uma função matemática, dado um certo x. 
int func(int x){
    return (3 * pow(x,3) + 2 * pow(x,2) + (x - 5));
}

///Função utilizada para fazer ordenação do vetor do menor para o maior
// n se refere ao tamanho do vetor a ser ordenado. 
void ordena(int n, int *v){
    int j,i;

    for(i=n-1; i>-1; i--){
        int troca = 0;
        for(j=0;j<i; j++){
            if(v[j]>v[j+1]){
                int temp = v[j]; // realiza a troca caso o valor a frente é menor que anterior.
                v[j] = v[j+1];
                v[j+1] = temp;
                troca = 1; //Garante que loop continue rodando enquanto trocas estão sendo realizadas. 
            }
        }
        if(troca == 0) //Interrompe o loop caso novas trocas não estejam ocorrendo. 
            return;
    }
}

//Função utilizada para garantir que numero testado esteja sempre entre 1 e 100.
int testaNumero2(int *n){
    if(*n > 100){
        puts("Valor deve ser menor que 100...");
        printf("Informe novo valor: ");
        scanf("%d", n);
        testaNumero(n);
    }
    else if (*n < 1){
        puts("Valor deve ser maior que 1...");
        printf("Informe novo valor: ");
        scanf("%d", n);
        testaNumero(n);
    }
    else 
        return 1;
}
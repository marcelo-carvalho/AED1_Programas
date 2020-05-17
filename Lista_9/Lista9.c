#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes 
#define N 10

//Funções das questões
int busca(int, int *, int);
void maximo(int *, int *, int);
void minimo(int *, int *, int);
void soma(int *, int *, int);
void produto(int *, int *, int);
void media(float *, int *, int);
void questao7();
void questao8();
void questao9();
void questao10();
int comparaStr(char *, char *, int );
void inverteStr(char *str1, char *str2, int ini, int fim);

//Funções auxiliares
int menu();
void setVetorManual(int*);

int main(){
    
    int index, k, b;
    int vet[N];
    int max = 0;
    int min = 999;
    int sum = 0;
    int prod = 1;
    int opcaoVetor = 0;
    float med = 0;
    

        do{ 
            index = menu();
            switch(index){
                case 1:
                    puts("Opcao 1: Um vetor de 10 posicoes sera preenchido com valores entre 0 - 100.");
                    setVetorManual(&vet);
                    printf("\nInforme um valor k a ser buscado: ");
                    scanf("%d", &k);
                    b = busca(k,vet,0);
                    if(b != -1)
                        printf("\n\t***Valor na posicao %d\n", b);
                    else
                        printf("\n\t***Valor nao encontrando.\n");
                    //Imprime o vetor para conferência.     
                    for(int i =0; i < N; i++)
                        printf("\nvet[%d] = %d", i, vet[i]);
                    break;
                case 2:
                    puts("Opcao 2: Um vetor de 10 posicoes sera preenchido automaticamente com valores entre.");
                    puts("O maior valor desde vetor sera retornado.");
                    setVetorManual(&vet);(vet);
                    maximo(&max,vet,0);
                    printf("\n\t***Maximo = %d\n", max);
                    //Imprime o vetor para conferência.
                    for(int i =0; i < N; i++)
                        printf("\nvet[%d] = %d", i, vet[i]);
                    break;
                case 3:
                    puts("Opcao 3: Um vetor de 10 posicoes sera preenchido automaticamente com valores entre.");
                    puts("O menor valor desde vetor sera retornado.");
                    setVetorManual(&vet);(vet);
                    minimo(&min,vet,0);
                    printf("\n\t***Minimo = %d\n", min);
                    //Imprime o vetor para conferência.
                    for(int i =0; i < N; i++)
                        printf("\nvet[%d] = %d", i, vet[i]);
                    break;
                case 4:
                    puts("Opcao 4: Um vetor de 10 posicoes sera preenchido automaticamente com valores entre.");
                    puts("A soma dos valores desde vetor sera retornada.");
                    setVetorManual(&vet);(vet);
                    soma(&sum,vet,0);
                    printf("\n\t***Soma = %d\n", sum);
                    //Imprime o vetor para conferência.
                    for(int i =0; i < N; i++)
                        printf("\nvet[%d] = %d", i, vet[i]);
                    break;
                case 5:
                    puts("Opcao 5: Um vetor de 10 posicoes sera preenchido automaticamente com valores entre.");
                    puts("O produto dos valores desde vetor sera retornado.");
                    setVetorManual(&vet);(vet);
                    produto(&prod,vet,0);
                    printf("\n\t***Produto = %d\n", prod);
                    //Imprime o vetor para conferência.
                    for(int i =0; i < N; i++)
                        printf("\nvet[%d] = %d", i, vet[i]);
                    break;
                case 6:
                    puts("Opcao 6: Um vetor de 10 posicoes sera preenchido automaticamente com valores entre.");
                    puts("A media dos valores desde vetor sera retornada.");
                    setVetorManual(&vet);(vet);
                    media(&med,vet,0);
                    printf("\n\t***Media = %f\n", med);
                    //Imprime o vetor para conferência.
                    for(int i =0; i < N; i++)
                        printf("\nvet[%d] = %d", i, vet[i]);
                    break;
                case 7:
                    puts("Opcao 7: Testa se duas strings sao semelhantes ou não.");
                    questao7();
                    break;
                case 8:
                    puts("Opcao 8: Imprime três strings em ordem alfabetica.");
                    questao8();
                    break;
                case 9:
                    puts("Opcao 9: Testa se uma palavra e palindromo.");
                    questao9();
                    break;
                case 10:
                    puts("Opcao 10: Testa se uma palavra e palindromo, usando recursao.");
                    questao10();
                    break;
                default:
                    index = 0;
                    puts("PROGRAMA FINALIZADO");
                    puts("OBRIAGADO POR USAR!");
                    break;
            }
    }while(index != 0);

    return 0;
}

//Funções das questões

//Função recursiva para localizar valor k em um vetor.
//Entradas:
//          k -> valor buscado.
//          vet -> ponteiro do vetor onde se deseja buscar o elemento.
//          elem -> posição inicial do vetor (recomenda-se 0).
//Saidas:
//          elem -> caso valor buscado seja econtrado a posição deste no vetor é retornada.
//          -1 -> caso valor buscado não seja encontrado. 
int busca(int k, int *vet, int elem){
    if(elem >= N)           //Primeira prosição sempre sera a condição de parada da recursão.  
        return -1;
    else if(k == vet[elem]) //Condição para valor encontrado.
        return elem;        
    else                    //Entrada da recursão sempre na ultima condição.
        return busca(k,vet,++elem);    
}

//Função apra encontrar o maior valor de um vetor
//Entrada:
//          *max -> ponteiro onde sera armazenado o maior valor (recomenda-se inicializalo em 0).
//          *vet -> vetor o qual se deseja encontrar o maior valor
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void maximo(int *max, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        return;
    
    if(*max < vet[elem])
        *max = vet[elem];
    maximo(max, vet, ++elem);
}

//Função apra encontrar o menor valor de um vetor
//Entrada:
//          *min -> ponteiro onde sera armazenado o menor valor (recomenda-se inicializalo em 999).
//          *vet -> vetor o qual se deseja encontrar o menor valor
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void minimo(int *min, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        return;
    
    if(*min > vet[elem])
        *min = vet[elem];
    minimo(min, vet, ++elem);
}

//Função para fazer a soma dos valores de um vetor
//Entrada:
//          *sum -> ponteiro onde sera armazenado o valor da soma (recomenda-se inicializalo em 0).
//          *vet -> vetor o qual se deseja encontrar o menor valor
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void soma(int *sum, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        return;
    
    *sum += vet[elem];
    soma(sum, vet, ++elem);
}

//Função para fazer a soma dos valores de um vetor
//Entrada:
//          *prod -> ponteiro onde sera armazenado o valor do produto (recomenda-se inicializalo em 1).
//          *vet -> vetor o qual se deseja encontrar o produto
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void produto(int *prod, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        return;
    
    *prod *= vet[elem];
    produto(prod, vet, ++elem);
}

//Função para encontrar a media dos valores de um vetor
//Entrada:
//          *med -> ponteiro onde sera armazenado o valor da media (recomenda-se inicializalo em 0).
//          *vet -> vetor o qual se deseja encontrar o menor valor
//          elem -> posição do vetor (recomenda-se iniciar no 0).
void media(float *med, int *vet, int elem){
    if(elem >= N)       //Primeira prosição sempre sera a condição de parada da recursão. 
        *med = *med/N;
    else{
        *med += vet[elem];
        media(med, vet, ++elem);
    }
}

//Procedimento pergunta por duas strings são identicas.
//Procedimento não possui entradas. 
void questao7(){
    char string1[N];
    char string2[N];
    int strIguais = 1;

    setbuf(stdin,NULL);
    printf("Informe a primeira string: ");
    scanf("%[^\n]s", &string1);
    setbuf(stdin, NULL);
    printf("Informe a segunda string: ");
    scanf("%[^\n]s", &string2);

    //Testa cada um dos caracters, caso haja diferenças seta a variável 
    //strIguais para zero, caso todos sejam identicos matém variável em 1.
    for(int i = 0; string1[i] != '\0' || string2[i] != '\0' ; i++){
        if(string1[i] != string2[i]){
            strIguais = 0;
            break;
        }
    }
    
    //Imprime os resutlados de acordo com a saida do loop anterior. 
    if(strIguais == 0){
        puts("As strings sao diferentes.");
        printf("str1 = %s", string1);
        printf("\nstr2 = %s", string2);
    }
    else {
        puts("As strings sao iguais");
        printf("str1 = %s", string1);
        printf("\nstr2 = %s", string2);
    }
}

//Procedimento perguta por três strings, em seguida gera um código hash baseado 
//no primiero caracter de cada string, compara esses códigos e os exibe em ordem.
void questao8(){
    char nome1[N];
    char nome2[N];
    char nome3[N];
    int hashNome1, hashNome2, hashNome3;

    setbuf(stdin,NULL);
    printf("Informe o primeira nome: ");
    scanf("%[^\n]", &nome1);
    setbuf(stdin, NULL);
    hashNome1 = hashNome(nome1);
    printf("Informe o segundo nome: ");
    scanf("%[^\n]", &nome2);
    setbuf(stdin, NULL);
    hashNome2 = hashNome(nome2);
    printf("Informe o terceiro nome: ");
    scanf("%[^\n]", &nome3);
    hashNome3 = hashNome(nome3);

    //Condições para exibição das strings ordenadas. 
    if(hashNome1 < hashNome2 && hashNome1 < hashNome3){
        if(hashNome2 < hashNome3){
            printf("%s", nome1);
            printf("\n%s", nome2);
            printf("\n%s", nome3);
        }
        else{
            printf("%s", nome1);
            printf("\n%s", nome3);
            printf("\n%s", nome2);
        }
    }
    else if (hashNome2 < hashNome1 && hashNome2 < hashNome3){
        if(hashNome1 < hashNome3){
            printf("%s", nome2);
            printf("\n%s", nome1);
            printf("\n%s", nome3);
        }
        else{
            printf("%s", nome2);
            printf("\n%s", nome3);
            printf("\n%s", nome1);
        }
    }
    else{
        if(hashNome1 > hashNome2){
            printf("%s", nome3);
            printf("\n%s", nome1);
            printf("\n%s", nome2);
        }
        else{
            printf("%s", nome3);
            printf("\n%s", nome2);
            printf("\n%s", nome1);
        }
    }
}

//Procedimento pede por uma string e iria checar se essa string é um palíndromo.
void questao9(){
    char str[N];
    char invStr[N];
    int i, j, letraDiferente = 1, size;

    setbuf(stdin,NULL);
    printf("Informe uma string: ");
    scanf("%[^\n]", &str);

    size = strlen(str);
    //transforma todas as letras em minúsculas.
    for(i = 0; i < size; i++)
        str[i] = tolower(str[i]);
    
    //cria uma string invertida. 
    j = strlen(str) - 1;
    for(i = 0; i < size; i++){
        invStr[i] = str[j];
        j--;
    }
    invStr[i] = '\0';

    //compara todas as letras das duas strings. 
    for(i = 0; i < size; i ++){
        if(str[i] != invStr[i]){
            letraDiferente = 0;
            break;
        }
    }

    printf("\nPalavra = %s \tPalavra invertida = %s\n", str, invStr);
    
    //teste se existe alguma letra diferente. 
    if(letraDiferente == 1)
        printf("\nA palavra e palindroma.");
    else 
        printf("\nA palavra nao e palindroma.");
}

void questao10(){
    char str[N];
    char invStr[N];
    int i, j, size;

    setbuf(stdin,NULL);
    printf("Informe uma string: ");
    scanf("%[^\n]s", &str);

    size = strlen(str);
    //transforma todas as letras em minúsculas.
    for(i = 0; i < size; i++)
        str[i] = tolower(str[i]);
    
    //cria uma string invertida. 
    inverteStr(str,invStr,0,strlen(str)-1);

    printf("\nPalavra = %s \tPalavra invertida = %s\n", str, invStr);
    
    //teste se existe alguma letra diferente. 
    if(comparaStr(str,invStr,0) == 1)
        printf("\nA palavra e palindroma.");
    else 
        printf("\nA palavra nao e palindroma.");
}


//Função para determinar se a palavra é palindroma.
//Entrada:
//          str1 -> primeira string.
//          str2 -> segunda string invertida.
//          elem -> indice do elemento do vetor.
//Saída:
//          0 -> caso algum caracter apresente diferença. 
//          1 -> caso os caracters sejam iguais. 
int comparaStr(char *str1, char *str2, int elem){
    if(elem > N) //Primeira condição de parada.
        return 0;
    else if(str1[elem] != str2[elem]) //Segunda condição de parada. 
        return 0;
    else if (str1[elem] == str2[elem])
        comparaStr(str1,str2,++elem);

    return 1;
}

//Procedimento para inverter strings
//Entrada:
//          str1 -> string a ser invertida;
//          str2 -> string invertida.
//          ini -> valor da posição inicial da str1 recomenda-se começar em 0.
//          fim -> valor final da posição str1 recomenda-se usar strlen().
void inverteStr(char *str1, char *str2, int ini, int fim){
    if(ini > strlen(str1)){
        return;
    }
    else{
        str2[ini] = str1[fim];
        inverteStr(str1,str2,++ini,--fim);
    }
}

//Funções auxiliares

//Função cria um menu com as opções possíveis. 
int menu(){
    int index = 0;
    puts("\n=====================LISTA DE EXERCICIOS 9=====================\n"
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
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 10)
                return index;
            else
                puts("\nValor invalido. Escolha uma das opcoes abaixo:\n");
    }while(index != 0);

    return index;
}


//Gera um número hash para comparação de strings. 
//Entrada:
//          nome -> vetor contendo a string. 
//Saida:
//          valor inteiro correspondente ao primeiro caracter da string.  
int hashNome(char *nome){
        return (int) (nome[0]);
}


//Procedimento para preenchimento manual do vetor
//Entrada:
//          vet -> ponteiro do vetor a ser preenchido pelo usuário.
void setVetorManual(int *vet){
    for(int i =0; i < N; i++){
        printf("vet[%d] = ", i);
        scanf("%d", &vet[i]);
    }
}
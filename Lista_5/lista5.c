#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Protótipos das funções das atividades 1 - 7.
float retornMiddle(float, float, float);
float calcAvg();
int funcXor(int, int);
void calcSeries();
float calcSeries2();
float calcSin(float x);
int randNumber(int min, int max);

//Protótipos das funções da atividade 8
bool validateNumber(long long int, int);
void nameHundreads(int);
void nameDozens(int);
void nameUnits(int);
void splitNumber(long long int, int);

//Protótipos de funções extras
int menu();
float calcFact(int a);
int testaBooleans(int);


//********************************************************************************************//
//*                                        Função main                                       *//
//********************************************************************************************//

int main(){
    int index = 0;
    float num1 = 0, num2 = 0, num3 = 0; 
    int min, max;
    float avg = 0, x = 0;
    int a = 0, b = 0;
    long long int parteIneira = 0;
    int parteDecimal = 0;  

    do{
        index = menu();

        switch(index){
            case 1: 
                puts("Informe tres numeros: ");
                puts("Numero 1: ");
                scanf("%f", &num1);
                puts("Numero 2: ");
                scanf("%f", &num2);
                puts("Numero 3: ");
                scanf("%f", &num3);
                float resp = retornMiddle(num1, num2, num3);
                printf("O valor do meio e: %0.4f\n", resp);
                break;
            case 2:
                avg = calcAvg();
                printf("A media dos numeros e: %0.4f\n", avg);
                break;
            case 3: 
                puts("Informe dois valoers booleans (1 ou 0)\n");

                do{
                    puts("Valor de A: ");
                    scanf("%d", &a);
                    puts("Valor de B: ");
                    scanf("%d", &b);
                }while(testaBooleans(a) != 1 || testaBooleans(b) != 1);
                               
                if(funcXor(a, b)==1) 
                    puts("A XOR B = Verdadeiro");
                else 
                    puts("A XOR B = Falso");
                break;
            case 4: 
                calcSeries();
                break;
            case 5:
                avg = calcSeries2();
                printf("\nO resultado do somatorio e: %f\n", avg);
                break;
            case 6:
                puts("Informe um numero real x: ");
                scanf("%f", &x);
                printf("\nO valor do sen(x) = %f", calcSin(x));
                printf("\nO valor de sen(x) pela funcao e MATH.H = %f\n", sin(x));
                break;
            case 7:
                do{
                    puts("Informe um valor inteiro min e um valor inteiro max, onde min < max.\n"
                        "Um numero aleatorio entre eles sera exibido em seguida.");
                    printf("\nValor de min:");
                    scanf("%d", &min);
                    printf("\nValor de max:");
                    scanf("%d", &max);
                }while(min > max);
                printf("O valor aleatorio eh: %i\n", randNumber(min, max));
                break;
            case 8: 
                do{
                    puts("Informe um numero entre 0 e 999.999.999.99,99: ");
                    scanf("%lld,%d", &parteIneira, &parteDecimal);
                }while(validateNumber(parteIneira,parteDecimal)!=true);
                splitNumber(parteIneira,parteDecimal);
                break;

        }
    }while(index != 0);

}

//********************************************************************************************//
//*                            Funções das atividades 1 - 7                                  *//
//********************************************************************************************//

//retornMeddle: função recebe três valores reais quaisquer e em seguida compara os valores e
//retorna o que estiver na posição do meio para a função requerinte.
float retornMiddle(float num1, float num2, float num3){
    if(num1 >= num2 && num1 <= num3)
        return num1;
    else if(num2 >= num1 && num2 <= num3)
        return num2;
    else if(num3 >= num1 && num3 <= num2)
        return num3;
}

//calcAvg: Função solicita dez valores para o usuário e aguarda que ele informe dez valores,
//em seguida calcula a media dos valores informados e retorna este valor para a função requerinte.
float calcAvg(){
    float avg = 0;
    float aux = 0;
    puts("Informe 1- numeros: ");
    for(int i=0; i< 10; i++){
        printf("#%d: ", i + 1);
        scanf("%f", &aux);
        avg += aux;
    }
    return avg /10;
}

//funcXor: Função pede dois valores inteiros A e B, e retorna para oa função requerinte as saídas de 
//acordo com a tabela verdade da operação XOR: 
//1 -> A = 1 B = 0 
//1 -> A = 0 B = 1
//0 -> A = 1 B = 1
//1 -> A = 0 B = 0 
int funcXor(int a, int b){
    if (a == 1 && b == 0)
        return 1;
    else if (a == 0 && b == 1) 
        return 1;
    else 
        return 0;
}

//calcSeries: procedimento criado para calcular os vintes primeiros elementos de uma serie infinita. 
//Procedimento irá retornar o resultado da soma dos 20 primieros elementos dessa serie. 
void calcSeries(){
    int count = 0;
    int num = 100;
    float series = 0;
    while (count < 20){
        series += num / calcFact(count);
        num--;
        count++;
    }
    printf("O resultado da serie eh: %f\n", series);
}

//calcSeries2: Função para calcular um serie de 15 elementos. A função não recebe argumentos e retorna o 
//o resultado do somatorio. 
float calcSeries2(){
    int num = 1; 
    int den = 15;
    float sum = 0;

    for(int i = 0; i < 15; i++){
        sum += (float) num/(den*den);
        num *= 2;
        den -= 1;
    }
    return sum;
}

//calcSin: Função recebe um valor de entrada e partir deste utiliza um metódo númerico para calcular o seno do 
//valor de entrada. A função foi dimensionada de forma que o valor de saída seja 4 casas decimais preciso em
//relação a função sin(x) de math.h.
float calcSin(float x){
    float comp = sin(x);
    float sinX = x; 
    int operator = 3;
    int i = 1;
    while(i < 20){
        sinX += (float) (pow(x,operator) / calcFact(operator)) * pow(-1,i);
        operator += 2;
        i++;
    }
    return sinX;
}

//ranNumber: Função recebe dois valores de entrado um max e min onde um processo para gerar números aleatórios
//utiliza os valores de entrada como intervalos para os números aleatorios gerados. 
int randNumber(int min, int max){
    int ran = 0;
    do{
        ran = rand() % max;
    } while(ran <= min && ran >= max);

    return ran;
}

//********************************************************************************************//
//*                                Funções das atividades 8                                  *//
//********************************************************************************************//

//validateNumber: Rrecebe dois numeros inteiros que compõe o numero a ser analisado. Em seguida 
//Verifica se o numero esta dentro do limite permitido pelo programa. Retorna um booleano onde:
// 1 o numero é valido, 0 o número não é valido. 
bool validateNumber(long long int inteiro, int decimal){
    if(decimal > 99 && decimal <0 ){
        printf("A parte decimal não pode ser maior que 0.99");
        return false;
    }
    else if(inteiro > 99999999999){
        printf("O numero nao pode ser maior que 99999999999.");
        return false;
    }
    else if(inteiro < 0){
        puts("O numero deve ser positvo");
        return false;
    }
    else{
        return true;
    }
}

//nameHundreads: Recebe um numero inteiro calculado onde intenta-se nomear as centenas.
//O procedimento printa na tela o nome equivalente ao valor. 
void nameHundreads(int inteiro){
    int centenas = inteiro % 1000;
    int centena = centenas / 100;
    int dezenas = centenas % 100;

    switch(centena){
        case 1: 
            if(dezenas != 0)
                printf("Cento e");
            else
                printf("Cem");
            break;    
        case 2: 
            if(dezenas != 0)
                printf("Duzentos e");
            else
                printf("Duzentos");
            break;
        case 3: 
            if(dezenas != 0)
                printf("Trezentos e");
            else
                printf("Trezentos");
            break;
        case 4: 
            if(dezenas != 0)
                printf("Quatrocentos e");
            else
                printf("Quatrocentos");
            break;
        case 5: 
            if(dezenas != 0)
                printf("Quinhentos e");
            else
                printf("Quinhentos");
            break;
        case 6: 
            if(dezenas != 0)
                printf("Seiscentos e");
            else
                printf("Seiscentos");
            break;
        case 7: 
            if(dezenas != 0)
                printf("Setecentos e");
            else
                printf("Setecentos");
            break;
        case 8: 
            if(dezenas != 0)
                printf("Oitocentos e");
            else
                printf("Oitocentos");
            break;
        case 9: 
            if(dezenas != 0)
                printf("Novecentos e");
            else
                printf("Novecentos");
            break;
        default:
            break;  
    }
}

//nameDozens: Recebe um numero inteiro calculado onde intenta-se nomear as dezenas.
//O procedimento printa na tela o nome equivalente ao valor, caso a dezena contenha 
//unidades, o proprio procedimento encaminha para o procedimento que produz o nome 
//da unidade.
void nameDozens(int inteiro){
    int dezenas = inteiro % 100;
    /*if(dezenas > 19)
        dezenas = (dezenas / 10) * 10;*/

    if(dezenas == 10){
        printf(" Dez ");
    }
    else if(dezenas == 11){
        printf(" onze ");
    }
    else if(dezenas == 12){
        printf(" Doze ");
    }
    else if(dezenas == 13){
        printf(" Treze ");
    }
    else if(dezenas == 14){
        printf(" Quatorze ");
    }
    else if(dezenas == 15){
        printf(" Quinze ");
    }    
    else if(dezenas == 16){
        printf(" Dezesseis ");
    }
    else if(dezenas == 17){
        printf(" Dezessete ");
    }
    else if(dezenas == 18){
        printf(" Dezoito e ");
    }
    else if(dezenas == 19){
        printf(" Dezenove ");
    }
    else if(dezenas > 20 && dezenas < 30){
        printf(" Vinte e ");
        nameUnits(inteiro);
    }
    else if (dezenas == 20){
        printf(" Vinte ");
    }
    else if(dezenas > 30 && dezenas < 40){
        printf(" Trinta e ");
        nameUnits(inteiro);
    }
    else if (dezenas == 30){
        printf(" Trinta ");
    }
    else if(dezenas > 40 && dezenas < 50){
        printf(" Quarenta e ");
        nameUnits(inteiro);
    }
    else if (dezenas == 40){
        printf(" Quarenta ");
    }
    else if(dezenas > 50 && dezenas < 60){
        printf(" Cinquenta e ");
        nameUnits(inteiro);
    }
    else if (dezenas == 50){
        printf(" Cinquenta ");
    }
    else if(dezenas > 60 && dezenas < 70){
        printf(" Sessenta e ");
        nameUnits(inteiro);
    }
    else if (dezenas == 60){
        printf(" Sessenta ");
    }
    else if(dezenas > 70 && dezenas < 80){
        printf(" Setenta e ");
        nameUnits(inteiro);
    }
    else if (dezenas == 70){
        printf(" Setenta ");
    }
    else if(dezenas > 80 && dezenas < 90){
        printf(" Oitenta e ");
        nameUnits(inteiro);
    }
    else if (dezenas == 70){
        printf(" Oitenta ");
    }
    else if(dezenas > 90 && dezenas < 100){
        printf(" Noventa e ");
        nameUnits(inteiro);
    }
    else if (dezenas == 90){
        printf(" Noventa ");
    }
}

//nameUnits: Procedimento responsável por nomear as unidades dos trios de valores.
//O procedimento recebe um valor inteiro e printa na tela o nome correspondente.
void nameUnits(int inteiro){
    int unidades = inteiro % 10;

     switch(unidades){
        case 1:
            printf(" Um");
            break;
        case 2:
            printf(" Dois");
            break;
        case 3:
            printf(" Tres");
            break;
        case 4:
            printf(" Quatro");
            break;
        case 5:
            printf(" Cinco");
            break; 
        case 6:
            printf(" Seis");
            break;
        case 7:
            printf(" Sete");
            break;
        case 8: 
            printf(" Oito");
            break;
        case 9:
            printf(" Nove");
            break;
        default:
            break;
    }
}

//splitNumber: procedimento inicial no processo, recebe dois numeros inteiros.
//Uma parte equivale a parte inteira do numero e o outro a parte fracionaria. 
//O procedimento quebra o numero de acardo com a posição de valor de cada algarismo.
//Redireciona cada trinca de valores para que seja devidamente nomeada. 
void splitNumber(long long int parteIneira, int parteDecimal){
    int billions = (((parteIneira / 1000) / 1000) / 1000) % 1000;
    int millions = ((parteIneira / 1000) / 1000) % 1000;
    int thousands = (parteIneira / 1000) % 1000;
    int hundreds = parteIneira % 1000;
    int dozens = parteIneira % 100;
    int units = parteIneira % 10;

    if(billions != 0){
        nameHundreads(billions); 
        if(billions > 1){
            nameDozens(billions);
            if(billions < 10) nameUnits(billions);
            printf(" Bilhoes ");
        }
        else{
            nameUnits(billions);
            printf(" Bilhao ");
        }
    }

    if(millions != 0){
        nameHundreads(millions); 
            if(millions > 1){
                nameDozens(millions);
                if(thousands < 10) nameUnits(millions);
                printf(" Milhoes ");
            }
            else{
                nameUnits(millions);
                printf(" Milhao ");
            }
    }

        if(thousands != 0){
            nameHundreads(thousands); 
            nameDozens(thousands);
            if(thousands < 10) nameUnits(thousands);
            printf(" Mil e");
        }

        if(hundreds != 0){
            nameHundreads(hundreds); 
            nameDozens(hundreds);
            if(hundreds > 10) nameUnits(hundreds);
        }
        
        printf(" Reais ");

       if(parteDecimal != 0){
           printf("e ");
           nameDozens(parteDecimal);
           nameUnits(parteDecimal);
           printf(" centavos");
        }    
}

//********************************************************************************************//
//*                                Funções extras                                            *//
//********************************************************************************************//


//Menu: Função para gerar o menu. Retorna um valor do indicie apresentado para futuro 
//uso no programa principal. 
int menu(){
    int index = 0;
    puts("=====================LISTA DE EXERCICIOS 5=====================\n"
             "Escolha uma das opcoes abaixo: \n"
             "\n");
    do{
        puts(
             "1 - Funcao que recebe tres elementos e retorna o do meio.\n"
             "2 - Funcao que recebe 10 numeros e retorna a media destes.\n"
             "3 - Funcao que recebe dois booleanos e retorna a operacao XOR destes.\n"
             "4 - Procedimento para calcular os 20 primeiros termos de uma serie.\n"
             "5 - Funcao que retorna o valor de um somatorio.\n"
             "6 - Funcao que recebe um valor x e calcula o sen deste e compara com a funcao sen de Math.h\n"
             "7 - Funcao que recebe um valor min e max e retorna um numero aleatorio entre eles.\n"
             "8 - Funcao para escrever um valor por extenso.\n"
             "0 - Sair.");

             scanf("%d", &index);

             if(index >= 0 && index <= 8)
                return index;
            else
                puts("Valor invalido. Escolha uma das opcoes abaixo:");
    }while(index != 0);
}

//calcFact: Enters a number and the function returns its factorial
float calcFact(int a){
    float fact = 1;
    if(a < 0){
        puts("To calculate factorial the number must be > 0.");
        return 1;
    }
    else if(a == 0){
        return 1;
    }
    else{
        for(int i = 1; i <= a; i++){
            fact *= i;
        }
        return fact;
    }
}
//testaBooleans: a função testa se os valores atribuidos a A e B estão dentro da regra de 
//0 ou 1. caso tudo esteja correto a função retorna 1, caso contrário reetorna 0.
int testaBooleans(int a){
    if(a == 1 || a == 0){
        return 1;
    }
    else{
        puts("\nO valor da variavel so pode ser 0 ou 1.\n");
        return 0;
    }
}
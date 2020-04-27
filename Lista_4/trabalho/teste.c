#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validateNumber(long long int, int);
void nameHundreads(int);
void nameDozens(int);
void nameUnits(int);

int main(){
    
    long long int parteIneira = 0;
    int parteDecimal = 0;    

    puts("Informe um numero entre 0 e 999.999.999.99,99: ");
    scanf("%lld,%d", &parteIneira, &parteDecimal);

    if(validateNumber(parteIneira,parteDecimal)==true){
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
                if(billions < 10)
                    nameUnits(billions);
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
                if(thousands < 10)
                    nameUnits(millions);
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
            if(thousands < 10)
                nameUnits(thousands);
            printf(" Mil e");
        }

        if(hundreds != 0){
            nameHundreads(hundreds); 
            nameDozens(hundreds);
            if(hundreds > 10)
                nameUnits(hundreds);
        }

        printf(" Reais ");

       if(parteDecimal != 0){
           printf("e ");
           nameDozens(parteDecimal);
           nameUnits(parteDecimal);
           printf(" centavos");
        }

        /*printf("\n\tBilhao: %d", billions);
        printf("\n\tMilhao: %d", millions);
        printf("\n\tMilhar: %d", thousands);
        printf("\n\tCentena: %d", hundreds);
        printf("\n\tDecimal: %d", parteDecimal);*/
    }

    return 0;
}


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
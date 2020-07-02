#include <iostream>

class Fracao{
    public:
        int numerador;
        int denominador;
    
    //Construtor padrão, inicia a fração como 0/1;
    Fracao(){
        numerador = 0;
        denominador = 1;
    }

    //Construtor sobrecarregado inicia a fração com os valores passados pelos usuário. 
    Fracao(int num, int den){
        numerador = num;
        
        //Testa se denominar é diferente de zero, caso contrário atribui 1 ao denominador.
        if(den != 0) {
            denominador = den;
        }
        else {
            denominador = 1;
            std::cout << "Denominador 0, será atribuido o valor 1 no lugar" << std::endl;
        }
    }

    //Função set para atribuição de valor ao numerador. 
    void setNumerador(int num){
        numerador = num;
    }

    //Função set para atribuição de valor ao denominador. 
    //Realiza a verificação pra que o valor zero não seja adicionado ao denominador. 
    void setDenominador(int den){
        
        if(den != 0){
            denominador = den;
        }
        else {
            std::cout << "Denominador 0, será atribuido o valor 1 no lugar" << std::endl;
            denominador = 1;
        }
    }

    //Função apra imprimier a fração.
    void imprimir(){
        //Quando denominador é igual a 1 este não é impresso na tela. 
        if(denominador != 1)
            std::cout << numerador << "/" << denominador << std::endl;
        else 
            std::cout << numerador << std::endl;
    }

    //Função para realizar a simplificação da fração. 
    void simplifica(){
        int mdc = 0;

        //Cálcula o MDC entre númerador e denominador. 
        mdc = calculaMDC(numerador, denominador);
        
        //Divide os valores da fração pelo MDC. 
        numerador = numerador / mdc;
        denominador = denominador / mdc;
    }

    //Função para o cálculo do máximo divisor comum. 
    int calculaMDC(int num, int den){
        int resto = 1;
        
        //A interação irá ocorrer até o resto entre os números resultantes ser igual a 0.
        //e o valor armazenado em num será o máximo divisior comum entre os dois números.
        while(resto != 0){
            resto = num % den;
            num = den;
            den = resto;
        }

        return num;
    }
};

int main(){
    
    
    
    //Utilizando o construtor sobrecarregado e atribuindo valores diretamente a fração
    Fracao fracao1(8,4);
    std::cout << "Fração 1: ";
    fracao1.imprimir();
    fracao1.simplifica();
    std::cout << "Fração 1 simplificada: ";
    fracao1.imprimir();

    //Utilizando o construtor padrão e as funções set para atribuir valores a fração.
    Fracao fracao2;
    std::cout << "Fração 2: ";
    fracao2.setNumerador(9);
    fracao2.setDenominador(5);
    fracao2.imprimir();
    fracao2.simplifica();
    std::cout << "Fração 2 simplificada: ";
    fracao2.imprimir();

    //Testando a condição de denominador igual a zero. 
    std::cout << "Fração 3: ";
    Fracao fracao3(10,0);
    fracao2.imprimir();

    //Testando denominador maior que numerador.
    std::cout << "Fração 4: ";
    Fracao fracao4(15,3);
    fracao4.imprimir();
    fracao4.simplifica();
    std::cout << "Fração 4 simplificada: ";
    fracao4.imprimir();

    return 1;
}
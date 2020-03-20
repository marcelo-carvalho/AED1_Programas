#include <stdio.h>
#include <stdlib.h>



void somar (int n1, int n2, int &soma){
    {soma = n1 + n2;
}

int main(){
    int num1, num2, resultado;

    cout << "Digite o 1o numero: ";
    cin >> num1;
    cout << "Digite o 2o numero: ";
    cin >> num2;
    somar(num1, num2, resultado);

    cout << "O resultado eh: " << resultado;
    return 0;
}
#include <iostream>
#include <time.h> 

using namespace std;

int main(){

    time_t t;
    struct tm * infoTempo; 
    char buffer[80];
    
    time(&t);
    infoTempo=localtime(&t);

    //ctime(&t); //produz uma string com a data e hora local. 

    strftime(buffer, 80, "Data: %d/%m/%Y", infoTempo);

    cout << buffer << endl;

    return 0;
}
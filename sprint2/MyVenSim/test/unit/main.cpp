#include "../../include/Model.h"
#include <math.h>
#include <iostream>

int main(){
    std::cout << "Testes Unitarios!"<< endl;
    Flow* flowteste = new Flow();
    std::cout<<"teste flow aprovado"<< endl;
    System* sisteste1 = new System();
    std::cout<<"teste system aprovado" << endl;
    System* sisteste2 = new System();
    std::cout<<"teste system aprovado" << endl;
    Model modteste;
    std::cout << "teste model aprovado!" << endl;
    std::cout<<"todos os testes aprovados" << endl;
    return 0;
}
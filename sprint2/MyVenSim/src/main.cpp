#include "../include/Model.h"
#include <iostream>
int main(){
    std::cout << "Simulador de Sistemas Dinâmicos";

    Model Fabrica;
    System* parafusos = new System("parafusos", 1000);

    Flow* venda = new Flow("venda");
    venda->setSource(parafusos);
    venda->setTarget(NULL);
    venda->setEquation([&](double){return 10;});

    Flow* fabricacao = new Flow("fab");
    fabricacao->setSource(NULL);
    fabricacao->setTarget(parafusos);
    fabricacao->setEquation([&](double) {return 0.05 * parafusos->getValue();});

    Fabrica.add(parafusos);
    Fabrica.add(venda);
    Fabrica.add(fabricacao);

    Fabrica.run(0, 100, 1);
    std::cout << endl << parafusos->getValue() << " parafusos";
}

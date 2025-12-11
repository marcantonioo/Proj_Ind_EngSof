/**
 * @file main.cpp
 * @brief Ponto de entrada principal do programa e exemplo de simulação de modelo.
 *
 * * Este arquivo demonstra a criação de um modelo simples (Fabrica)
 * * com um sistema (parafusos) e dois fluxos (venda e fabricacao),
 * * e executa a simulação.
 */
#include "../include/Model.h"
#include "../include/flow.h"
#include <iostream>

/**
 * @brief Função principal de execução do simulador.
 *
 * * 1. Cria o objeto Model principal (Fabrica).
 * * 2. Cria e inicializa o System "parafusos" com valor inicial de 1000.
 * * 3. Cria o Flow "venda", configurando-o para subtrair 10 unidades do sistema "parafusos" a cada passo.
 * * 4. Cria o Flow "fabricacao", configurando-o para adicionar 5% do valor atual de "parafusos" a ele mesmo.
 * * 5. Adiciona todos os componentes (System e Flows) ao Model.
 * * 6. Executa a simulação de tempo t=0 a t=100 com passo (dt) de 1.
 * * 7. Imprime o valor final do System "parafusos".
 *
 * @return int Retorna 0 ao finalizar com sucesso.
 */
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
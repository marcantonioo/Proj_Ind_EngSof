/**
 * @file funcional_tests.cpp
 * @brief Implementa os testes funcionais para validar a dinâmica do simulador (Model, System, Flow).
 *
 * * Os testes funcionais verificam se o sistema se comporta conforme esperado
 * * para modelos de dinâmica de sistemas conhecidos, como Crescimento Exponencial
 * * e Crescimento Logístico, além de testar a conservação de valor em modelos complexos.
 */
#include "funcional_tests.h"
#include "../../include/flow.h"
#include "../../include/Model.h"
#include <iostream>
#include <cassert>
#include "../../include/interface/Imodel.h"

/**
 * @brief Teste Funcional de Crescimento/Decaimento Exponencial.
 *
 * * O teste configura um sistema onde o Flow de transferência é proporcional ao
 * * valor do sistema de origem (Rate = 0.01 * Source Value).
 * * O valor total (sis1 + sis2) deve ser conservado.
 * * Os valores finais são comparados com resultados analíticos conhecidos.
 */
void exponentialFuncionalTest(){
    std::cout << "Executando Teste Funcional: Exponencial..." << std::endl;

    // Criação dos objetos e adição ao Model
    Imodel* m = new Model();

    Isystem* sis1 = m->createSystem(100.0);
    Isystem* sis2 = m->createSystem(0.0);

    Iflow* exponencial = m->createFlow<Flow>(sis1, sis2, [&](double) {return 0.01 * sis1->getValue();});

    double valorInicial = sis1->getValue() + sis2->getValue();
    
    // Verificação da condição inicial
    assert(std::abs(valorInicial - 100.0) < 0.001);
    
    // Execução da simulação
    m->run(0, 100, 1);

    double valorFinal = sis1->getValue() + sis2->getValue();

    // Verificação dos valores finais (comparação com solução analítica/referência)
    assert(std::abs(sis1->getValue() - 36.6032) < 0.001); 
    assert(std::abs(sis2->getValue() - 63.3968) < 0.001); 

    
    // Verificação da conservação de valor
    assert(std::abs(valorFinal - valorInicial) < 0.001);

    std::cout << "  -> Teste Exponencial APROVADO." << std::endl;
}

/**
 * @brief Teste Funcional de Crescimento Logístico.
 *
 * * O teste simula um crescimento logístico, onde a taxa é proporcional ao
 * * valor atual e à capacidade de carga restante (Pmax).
 * * A simulação é executada por um longo período para garantir que o sistema
 * * atinja o ponto de saturação (Pmax).
 */
void logisticalFuncionalTest() {
    std::cout << "Executando Teste Funcional: Logistico..." << std::endl;

    Imodel* m = new Model();
    double pmax = 70.0;

    // Criação dos sistemas
    Isystem* sis1 = m->createSystem(); // Source
    Isystem* sis2 = m->createSystem();  // Target (população em crescimento)


    Iflow* log = m->createFlow<Flow>(sis1, sis2, [&](double) { return 0.01 * sis2->getValue() * (1.0 - sis2->getValue() / pmax);});
    // Simulação longa para atingir o equilíbrio
    m->run(0, 100000, 1);

    
    // Verificação dos valores finais: sis2 deve se aproximar de Pmax (70.0)
    assert(std::abs(sis2->getValue() - 70.0) < 0.0001);
    // sis1 deve ter perdido a diferença (70.0 - 10.0 = 60.0), ficando em 40.0
    assert(std::abs(sis1->getValue() - 40.0) < 0.0001);

    std::cout << "  -> Teste Logistico APROVADO." << std::endl;
}

/**
 * @brief Teste Funcional de Modelo Complexo (conservação de valor em múltiplos Flows).
 *
 * * O teste configura uma rede complexa de 5 sistemas e 6 fluxos interconectados.
 * * O principal objetivo é verificar se a massa/valor total do sistema é conservada
 * * ao longo da simulação, mesmo com múltiplas transferências simultâneas.
 */
void complexFuncionalTest() {
    std::cout << "Executando Teste Funcional: Complexo..." << std::endl;
    
    Imodel* m = new Model();
    
    // Criação dos 5 sistemas
    Isystem* Q1= m->createSystem(100.0);
    Isystem* Q2= m->createSystem(0.0);
    Isystem* Q3= m->createSystem(0.0);
    Isystem* Q4= m->createSystem(0.0);
    Isystem* Q5= m->createSystem(0.0);

    // Criação dos 6 fluxos
    Iflow* f= m->createFlow<Flow>(Q1, Q2, [&](double){ return 0.01 * Q1->getValue(); });
    Iflow* g= m->createFlow<Flow>(Q1, Q3, [&](double){ return 0.01 * Q1->getValue(); });
    Iflow* r= m->createFlow<Flow>(Q2, Q5, [&](double){ return 0.01 * Q2->getValue(); });
    Iflow* t= m->createFlow<Flow>(Q2, Q3, [&](double){ return 0.01 * Q2->getValue(); });
    Iflow* u= m->createFlow<Flow>(Q3, Q4, [&](double){ return 0.01 * Q3->getValue(); });
    Iflow* v= m->createFlow<Flow>(Q4, Q1, [&](double){ return 0.01 * Q4->getValue(); });


    double valorInicial = Q1->getValue() + Q2->getValue() + Q3->getValue() + Q4->getValue() + Q5->getValue();
    // Verificação do valor inicial
    assert(std::abs(valorInicial - 200.0) < 0.001);

    m->run(0, 100, 1);

    double valorFinal = Q1->getValue() + Q2->getValue() + Q3->getValue() + Q4->getValue() + Q5->getValue();

    // Verificação da conservação de valor
    assert(std::abs(valorFinal - 200.0) < 0.001);

    std::cout << "  -> Teste Complexo APROVADO." << std::endl;
}
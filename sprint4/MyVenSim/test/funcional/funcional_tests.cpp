/**
 * @file funcional_tests.cpp
 * @brief Implementa os testes funcionais para validar a dinâmica do simulador (Model, System, Flow).
 *
 * * Os testes funcionais verificam se o sistema se comporta conforme esperado
 * * para modelos de dinâmica de sistemas conhecidos, como Crescimento Exponencial
 * * e Crescimento Logístico, além de testar a conservação de valor em modelos complexos.
 */
#include "funcional_tests.h"
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

    Isystem* sis1 = new System("sis1", 100.0);
    Isystem* sis2 = new System("sis2", 0.0);
    m->add(sis1);
    m->add(sis2);
    
    Iflow* exponencial = new Flow("exp");
    exponencial->setSource(sis1);
    exponencial->setTarget(sis2);
    exponencial->setEquation([&](double) {
        return 0.01 * sis1->getValue();
    });


    m->add(exponencial);

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
    Isystem* sis1 = new System("sis1", 100.0); // Source
    Isystem* sis2 = new System("sis2", 10.0);  // Target (população em crescimento)
    m->add(sis1);
    m->add(sis2);

    Iflow* log = new Flow("log");

    // Configuração da equação logística: dP/dt = r * P * (1 - P/Pmax)
    log->setEquation([&](double) {
        return 0.01 * sis2->getValue() * (1.0 - sis2->getValue() / pmax);
    });

    log->setSource(sis1);
    log->setTarget(sis2);
    m->add(log);

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
    Isystem* Q1= new System("Q1", 100.0);
    Isystem* Q2= new System("Q2", 0.0);
    Isystem* Q3= new System("Q3", 100.0);
    Isystem* Q4= new System("Q4", 0.0);
    Isystem* Q5= new System("Q5", 0.0);
    
    m->add(Q1);
    m->add(Q2);
    m->add(Q3);
    m->add(Q4);
    m->add(Q5);

    // Criação dos 6 fluxos
    Iflow* f= new Flow("f");
    Iflow* g= new Flow("g");
    Iflow* r= new Flow("r");
    Iflow* t= new Flow("t");
    Iflow* u= new Flow("u");
    Iflow* v= new Flow("v");

    // Configuração das conexões Source/Target
    f->setSource(Q1);
    f->setTarget(Q2);
    g->setSource(Q1);
    g->setTarget(Q3);
    r->setSource(Q2);
    r->setTarget(Q5);
    t->setSource(Q2);
    t->setTarget(Q3);
    u->setSource(Q3);
    u->setTarget(Q4);
    v->setSource(Q4);
    v->setTarget(Q1);


    // Configuração das equações (simplesmente proporcionais ao Source)
    f->setEquation( [&](double){ return 0.01 * Q1->getValue(); } );
    g->setEquation( [&](double){ return 0.01 * Q1->getValue(); } );
    r->setEquation( [&](double){ return 0.01 * Q2->getValue(); } );
    t->setEquation( [&](double){ return 0.01 * Q2->getValue(); } );
    u->setEquation( [&](double){ return 0.01 * Q3->getValue(); } );
    v->setEquation( [&](double){ return 0.01 * Q4->getValue(); } );

    m->add(f);
    m->add(g);
    m->add(r);
    m->add(t);
    m->add(u);
    m->add(v);

    double valorInicial = Q1->getValue() + Q2->getValue() + Q3->getValue() + Q4->getValue() + Q5->getValue();
    // Verificação do valor inicial
    assert(std::abs(valorInicial - 200.0) < 0.001);

    m->run(0, 100, 1);

    double valorFinal = Q1->getValue() + Q2->getValue() + Q3->getValue() + Q4->getValue() + Q5->getValue();

    // Verificação da conservação de valor
    assert(std::abs(valorFinal - 200.0) < 0.001);

    std::cout << "  -> Teste Complexo APROVADO." << std::endl;
}
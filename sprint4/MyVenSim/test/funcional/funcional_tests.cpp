#include "funcional_tests.h"
#include "../../include/Model.h"
#include <iostream>
#include <cassert>


void exponentialFuncionalTest(){
    std::cout << "Executando Teste Funcional: Exponencial..." << std::endl;

    Model m;

    System* sis1 = new System("sis1", 100.0);
    System* sis2 = new System("sis2", 0.0);
    m.add(sis1);
    m.add(sis2);
    
    Flow* exponencial = new Flow("exp");
    exponencial->setSource(sis1);
    exponencial->setTarget(sis2);
    exponencial->setEquation([&](double) {
        return 0.01 * sis1->getValue();
    });


    m.add(exponencial);

    double valorInicial = sis1->getValue() + sis2->getValue();
    
    assert(std::abs(valorInicial - 100.0) < 0.001);
    
    m.run(0, 100, 1);

    double valorFinal = sis1->getValue() + sis2->getValue();

    assert(std::abs(sis1->getValue() - 36.6032) < 0.001); 
    assert(std::abs(sis2->getValue() - 63.3968) < 0.001); 

    
    assert(std::abs(valorFinal - valorInicial) < 0.001);

    std::cout << "  -> Teste Exponencial APROVADO." << std::endl;
}

void logisticalFuncionalTest() {
    std::cout << "Executando Teste Funcional: Logistico..." << std::endl;

    Model m;
    double pmax = 70.0;

    System* sis1 = new System("sis1", 100.0);
    System* sis2 = new System("sis2", 10.0);
    m.add(sis1);
    m.add(sis2);

    Flow* log = new Flow("log");

    log->setEquation([&](double) {
        return 0.01 * sis2->getValue() * (1.0 - sis2->getValue() / pmax);
    });

    log->setSource(sis1);
    log->setTarget(sis2);
    m.add(log);

    m.run(0, 100000, 1);

    
    assert(std::abs(sis2->getValue() - 70.0) < 0.0001);
    assert(std::abs(sis1->getValue() - 40.0) < 0.0001);

    std::cout << "  -> Teste Logistico APROVADO." << std::endl;
}

void complexFuncionalTest() {
    std::cout << "Executando Teste Funcional: Complexo..." << std::endl;
    
    Model m;
    
    System* Q1= new System("Q1", 100.0);
    System* Q2= new System("Q2", 0.0);
    System* Q3= new System("Q3", 100.0);
    System* Q4= new System("Q4", 0.0);
    System* Q5= new System("Q5", 0.0);
    
    m.add(Q1);
    m.add(Q2);
    m.add(Q3);
    m.add(Q4);
    m.add(Q5);

    Flow* f= new Flow("f");
    Flow* g= new Flow("g");
    Flow* r= new Flow("r");
    Flow* t= new Flow("t");
    Flow* u= new Flow("u");
    Flow* v= new Flow("v");

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


    f->setEquation( [&](double){ return 0.01 * Q1->getValue(); } );
    g->setEquation( [&](double){ return 0.01 * Q1->getValue(); } );
    r->setEquation( [&](double){ return 0.01 * Q2->getValue(); } );
    t->setEquation( [&](double){ return 0.01 * Q2->getValue(); } );
    u->setEquation( [&](double){ return 0.01 * Q3->getValue(); } );
    v->setEquation( [&](double){ return 0.01 * Q4->getValue(); } );

    m.add(f);
    m.add(g);
    m.add(r);
    m.add(t);
    m.add(u);
    m.add(v);

    double valorInicial = Q1->getValue() + Q2->getValue() + Q3->getValue() + Q4->getValue() + Q5->getValue();
    assert(std::abs(valorInicial - 200.0) < 0.001);

    m.run(0, 100, 1);

    double valorFinal = Q1->getValue() + Q2->getValue() + Q3->getValue() + Q4->getValue() + Q5->getValue();

    assert(std::abs(valorFinal - 200.0) < 0.001);

    std::cout << "  -> Teste Complexo APROVADO." << std::endl;
}
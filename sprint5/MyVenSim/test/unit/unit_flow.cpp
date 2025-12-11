/**
 * @file unit_flow.cpp
 * @brief Implementação dos testes unitários da classe Flow.
 *
 * Este arquivo contém a implementação de todos os métodos da classe UnitFlow,
 * que testam os comportamentos da classe Flow: construtores, getters, setters,
 * evaluate() e operador de atribuição.
 */

#include <cassert>
#include <iostream>

#include "unit_flow.h"               // Classe UnitFlow
#include "../../include/System.h"    // System real
#include "../../include/flow.h"      // Flow real

using namespace std;

/**
 * @brief Testa o construtor default da classe Flow.
 */
void UnitFlow::test_flow_constructor_default() {
    Flow f;
    assert(f.getSource() == nullptr);
    assert(f.getTarget() == nullptr);
    assert(f.getNome() == "");
}

/**
 * @brief Testa o construtor que recebe um nome.
 */
void UnitFlow::test_flow_constructor_nome() {
    Flow f("fluxo1");
    assert(f.getNome() == "fluxo1");
    assert(f.getSource() == nullptr);
    assert(f.getTarget() == nullptr);
}

/**
 * @brief Testa os métodos setNome e getNome.
 */
void UnitFlow::test_flow_setNome() {
    Flow f;
    f.setNome("fluxo_teste");
    assert(f.getNome() == "fluxo_teste");
}
void UnitFlow::test_flow_getNome() {
    Flow f;
    f.setNome("fluxo_exemplo");
    assert(f.nome == "fluxo_exemplo");
}

/**
 * @brief Testa os métodos setSource e getSource.
 */
void UnitFlow::test_flow_getSource() {
    System s1;
    s1.setValue(10);

    Flow* f = new Flow();
    f->setSource(&s1);
    assert(f->source == &s1);
}
void UnitFlow::test_flow_setSource() {
    System s1;
    s1.setValue(10);

    Flow* f = new Flow();
    f->source = &s1;
    assert(f->source == &s1);
}


/**
 * @brief Testa os métodos setTarget e getTarget.
 */
void UnitFlow::test_flow_setTarget() {
    System s2;
    s2.setValue(20);

    Flow* f = new Flow();
    f->setTarget(&s2);
    assert(f->target == &s2);
}

void UnitFlow::test_flow_getTarget() {
    System s2;
    s2.setValue(20);

    Flow* f = new Flow();
    f->setTarget(&s2);
    assert(f->target == &s2);
}

/**
 * @brief Testa os métodos setEquation e getEquation.
 */
void UnitFlow::test_flow_setEquation() {
    Flow* f = new Flow();
    f->setEquation([](double x){ return x * 2; });
    assert(f->equation(5) == 10);
}
void UnitFlow::test_flow_getEquation() {
    Flow* f = new Flow();
    f->setEquation([](double x){ return x + 3; });
    auto eq = f->equation;
    assert(eq(7) == 10);
}

/**
 * @brief Testa evaluate() com source definida.
 */
void UnitFlow::test_flow_evaluate_with_source() {
    System s;
    s.setValue(5);

    Flow f;
    f.setSource(&s);
    f.setEquation([](double x){ return x + 10; });

    assert(f.evaluate() == 15);
}

/**
 * @brief Testa evaluate() sem source definida.
 */
void UnitFlow::test_flow_evaluate_without_source() {
    Flow f;
    f.setEquation([](double x){ return x * 3; });
    assert(f.evaluate() == 0);
}

/**
 * @brief Testa o operador de atribuição.
 */
void UnitFlow::test_flow_operator_assignment() {
    Flow f1("original");

    System s;
    System t;

    s.setValue(30);
    t.setValue(40);

    f1.setSource(&s);
    f1.setTarget(&t);
    f1.setEquation([](double x){ return x + 1; });

    Flow f2;
    f2 = f1;

    assert(f2.getNome() == "original");
    assert(f2.getSource() == &s);
    assert(f2.getTarget() == &t);
    assert(f2.getEquation()(10) == 11);
}

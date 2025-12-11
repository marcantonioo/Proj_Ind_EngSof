/**
 * @file unit_model.cpp
 * @brief Implementação dos testes unitários da classe Model.
 *
 * Este arquivo contém a implementação dos métodos da classe UnitModel,
 * que testa os comportamentos da classe Model, incluindo adição e remoção
 * de Systems e Flows, além da execução do método run().
 */

#include <cassert>
#include <iostream>

#include "../../include/interface/Imodel.h"
#include "../../include/interface/Isystem.h"
#include "../../include/interface/Iflow.h"

#include "../../include/System.h"
#include "../../include/flow.h"
#include "../../include/Model.h"

#include "unit_model.h"

using namespace std;

void UnitModel::test_model_add_system() {
    Model m;
    System* s1 = new System();
    System* s2 = new System();

    bool ok = m.add(s1);
    assert(ok == true);

    ok = m.add(s2);
    assert(ok == true);
}

void UnitModel::test_model_add_flow() {
    Model m;
    Flow* f1 = new Flow("F1");
    f1->setEquation([](double x){ return x * 0.1; });

    bool ok = m.add(f1);
    assert(ok == true);
}

void UnitModel::test_model_add_system_flow() {
    Model m;
    System* s3 = new System();
    Flow* f2 = new Flow("F2");
    f2->setEquation([](double x){ return x + 1; });

    bool ok = m.add(s3, f2);
    assert(ok == true);
}

void UnitModel::test_model_remove_system() {
    Model m;
    System* s2 = new System();
    m.add(s2);

    bool ok = m.remove(s2);
    assert(ok == true);
}

void UnitModel::test_model_remove_flow() {
    Model m;
    Flow* f1 = new Flow("F1");
    m.add(f1);

    bool ok = m.remove(f1);
    assert(ok == true);
}

void UnitModel::test_model_run() {
    Model m;
    System* s1 = new System();
    Flow* f1 = new Flow("F1");
    f1->setEquation([](double x){ return x + 1; });

    m.add(s1);
    m.add(f1);

    // Apenas verificamos que não crasha
    m.run(0, 10, 1);
}

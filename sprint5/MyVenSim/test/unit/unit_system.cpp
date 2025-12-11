/**
 * @file unit_system.cpp
 * @brief Implementação dos testes unitários da classe System.
 *
 * Este arquivo contém a implementação dos métodos da classe UnitSystem,
 * que testam os comportamentos da classe System.
 */

#include <cassert>
#include <iostream>

#include "../../include/System.h"
#include "unit_system.h"

using namespace std;

void UnitSystem::test_system_initial() {
    System s;

    // Valor inicial deve ser 0.0
    assert(s.getValue() == 0.0);

    // Nome inicial deve ser string vazia
    assert(s.getNome() == "");
}

void UnitSystem::test_system_setValue() {
    System s;

    s.setValue(42.5);

    assert(s.getValue() == 42.5);
}

void UnitSystem::test_system_setNome() {
    System s;

    s.setNome("Deposito");

    assert(s.getNome() == "Deposito");
}

void UnitSystem::test_system_update() {
    System s("A", 10.0);

    // update deve substituir o valor, não somar
    s.update(2.5);

    assert(s.getValue() == 2.5);
}


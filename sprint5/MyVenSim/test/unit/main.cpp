/**
 * @file main.cpp
 * @brief Arquivo principal que executa todos os testes unitários de System, Flow e Model.
 *
 * Este arquivo inclui os headers de todos os testes unitários e executa
 * cada método de teste, exibindo mensagens de sucesso no console.
 */

#include <iostream>

// -----------------------------------------------------------------------------
// Includes das classes de teste
// -----------------------------------------------------------------------------
#include "unit_system.h"  /**< Declaração dos testes de System */
#include "unit_flow.h"    /**< Declaração dos testes de Flow */
#include "unit_model.h"   /**< Declaração dos testes de Model */

using namespace std;

/**
 * @brief Função principal que executa todos os testes.
 *
 * Cria instâncias das classes UnitSystem, UnitFlow e UnitModel,
 * e executa seus respectivos métodos de teste.
 *
 * @return int Retorna 0 se todos os testes forem executados com sucesso.
 */
int main() {
    // Instâncias dos módulos de teste
    UnitSystem systemTests;
    UnitFlow   flowTests;
    UnitModel  modelTests;

    /// --- Testes de System ---
    cout << "=== Iniciando testes de System ===" << endl;
    systemTests.test_system_initial();
    systemTests.test_system_setValue();
    systemTests.test_system_setNome();
    systemTests.test_system_update();
    cout << "Todos os testes de System passaram com sucesso!\n" << endl;

    /// --- Testes de Flow ---
    cout << "=== Iniciando testes de Flow ===" << endl;
    flowTests.test_flow_constructor_default();
    flowTests.test_flow_constructor_nome();
    flowTests.test_flow_setNome();
    flowTests.test_flow_getNome();
    flowTests.test_flow_setSource();
    flowTests.test_flow_getSource();
    flowTests.test_flow_setTarget();
    flowTests.test_flow_getTarget();
    flowTests.test_flow_setEquation();
    flowTests.test_flow_getEquation();
    flowTests.test_flow_evaluate_with_source();
    flowTests.test_flow_evaluate_without_source();
    flowTests.test_flow_operator_assignment();
    cout << "Todos os testes de Flow passaram com sucesso!\n" << endl;

    /// --- Testes de Model ---
    cout << "=== Iniciando testes de Model ===" << endl;
    modelTests.test_model_add_system();
    modelTests.test_model_add_flow();
    modelTests.test_model_add_system_flow();
    modelTests.test_model_remove_system();
    modelTests.test_model_remove_flow();
    modelTests.test_model_run();
    cout << "Todos os testes de Model passaram com sucesso!\n" << endl;

    cout << "=== TODOS OS TESTES PASSARAM COM SUCESSO! ===" << endl;

    return 0;
}

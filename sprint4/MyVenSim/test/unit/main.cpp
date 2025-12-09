/**
 * @file main.cpp
 * @brief Arquivo principal que executa todos os testes unitários de System, Flow e Model.
 *
 * Este arquivo inclui os headers de todos os testes unitários e executa
 * cada função de teste, exibindo mensagens de sucesso no console.
 */

#include <iostream>

// -----------------------------------------------------------------------------
// Includes dos headers de teste
// -----------------------------------------------------------------------------
#include "unit_system.h"  /**< Declaração dos testes de System */
#include "unit_flow.h"    /**< Declaração dos testes de Flow */
#include "unit_model.h"   /**< Declaração dos testes de Model */

using namespace std;

/**
 * @brief Função principal que executa todos os testes.
 *
 * Chama cada função de teste de System, Flow e Model em sequência.
 *
 * @return int Retorna 0 se todos os testes forem executados com sucesso.
 */
int main() {
    /// --- Testes de System ---
    cout << "=== Iniciando testes de System ===" << endl;
    test_system_initial();   ///< Testa o construtor default do System
    test_system_setValue();  ///< Testa o método setValue
    test_system_setNome();   ///< Testa o método setNome
    test_system_update();    ///< Testa o método update
    cout << "Todos os testes de System passaram com sucesso!\n" << endl;

    /// --- Testes de Flow ---
    cout << "=== Iniciando testes de Flow ===" << endl;
    test_flow_constructor_default();      ///< Testa o construtor default
    test_flow_constructor_nome();         ///< Testa o construtor com nome
    test_flow_setGetNome();               ///< Testa setNome/getNome
    test_flow_setGetSource();             ///< Testa setSource/getSource
    test_flow_setGetTarget();             ///< Testa setTarget/getTarget
    test_flow_setGetEquation();           ///< Testa setEquation/getEquation
    test_flow_evaluate_with_source();     ///< Testa evaluate() com source real
    test_flow_evaluate_without_source();  ///< Testa evaluate() sem source
    test_flow_operator_assignment();      ///< Testa operador de atribuição
    cout << "Todos os testes de Flow passaram com sucesso!\n" << endl;

    /// --- Testes de Model ---
    cout << "=== Iniciando testes de Model ===" << endl;
    test_model_add_system();       ///< Testa add(Isystem*)
    test_model_add_flow();         ///< Testa add(Iflow*)
    test_model_add_system_flow();  ///< Testa add(Isystem*, Iflow*)
    test_model_remove_system();    ///< Testa remove(Isystem*)
    test_model_remove_flow();      ///< Testa remove(Iflow*)
    test_model_run();              ///< Teste básico de run()
    cout << "Todos os testes de Model passaram com sucesso!\n" << endl;

    cout << "=== TODOS OS TESTES PASSARAM COM SUCESSO! ===" << endl;

    return 0;
}
    
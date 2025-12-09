/**
 * @file unit_system.cpp
 * @brief Implementação dos testes unitários da classe System.
 *
 * Este arquivo contém a implementação das funções que testam os métodos da classe
 * System, incluindo construtor, setValue, setNome e update.
 * Cada função utiliza assert() para validar o comportamento esperado.
 */

#include <cassert>
#include <iostream>

#include "../../include/interface/Isystem.h"
#include "../../include/System.h"

using namespace std;

/**
 * @brief Testa o construtor default do System.
 *
 * Verifica se o valor inicial é 0.0 e se o nome é uma string vazia.
 */
void test_system_initial() {
    System s;
    assert(s.getValue() == 0.0);
    assert(s.getNome() == "");
}

/**
 * @brief Testa o método setValue do System.
 *
 * Define um valor e verifica se ele foi armazenado corretamente.
 */
void test_system_setValue() {
    System s;
    bool ok = s.setValue(42.5);
    assert(ok == true);
    assert(s.getValue() == 42.5);
}

/**
 * @brief Testa o método setNome do System.
 *
 * Define um nome e verifica se ele foi armazenado corretamente.
 */
void test_system_setNome() {
    System s;
    bool ok = s.setNome("MeuSistema");
    assert(ok == true);
    assert(s.getNome() == "MeuSistema");
}

/**
 * @brief Testa o método update do System.
 *
 * Atualiza o valor do System e verifica se a operação foi bem-sucedida.
 */
void test_system_update() {
    System s;
    bool ok = s.update(100.0);
    assert(ok == true);
    assert(s.getValue() == 100.0);
}

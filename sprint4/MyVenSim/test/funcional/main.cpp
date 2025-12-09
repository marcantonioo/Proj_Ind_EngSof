/**
 * @file main_funcional_tests.cpp
 * @brief Ponto de entrada principal para a execução da suíte de testes funcionais.
 *
 * * Este arquivo centraliza as chamadas para os testes funcionais (Exponencial, Logístico, Complexo)
 * * garantindo que a implementação do Modelagem de Sistemas Venesianos esteja correta.
 */
#ifndef  MAIN_FUNCIONAL_TESTS

#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"

// Inclusões desnecessárias para este main, mas mantidas se for um estilo de projeto
#include "../../include/Model.h"
#include "../../include/System.h"
#include "../../include/flow.h"

/**
 * @brief Função principal que executa todos os testes funcionais.
 *
 * * O corpo desta função consiste em chamadas sequenciais para cada cenário de teste funcional.
 * @return int Retorna 0 se a execução de todos os testes for concluída.
 */
int main(){

    // Executa o teste de Crescimento Exponencial.
    exponentialFuncionalTest();

    // Executa o teste de Crescimento Logístico.
    logisticalFuncionalTest();

    // Executa o teste de Modelo Complexo (conservação de valor).
    complexFuncionalTest();
    
    return 0;

}

#endif
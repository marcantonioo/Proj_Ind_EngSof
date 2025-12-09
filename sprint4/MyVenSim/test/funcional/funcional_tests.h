/**
 * @file funcional_tests.h
 * @brief Declarações das funções de testes funcionais para o simulador VenSim.
 *
 * * Este arquivo contém as assinaturas de funções que implementam testes
 * * de ponta-a-ponta para validar a correta dinâmica do sistema (Model/System/Flow).
 */
#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H


/**
 * @brief Executa o teste funcional de Crescimento/Decaimento Exponencial.
 * * Verifica se o fluxo é proporcional ao estoque e se o valor total é conservado.
 */
void exponentialFuncionalTest();


/**
 * @brief Executa o teste funcional de Crescimento Logístico.
 * * Verifica se o sistema atinge o ponto de saturação (capacidade de carga Pmax).
 */
void logisticalFuncionalTest();


/**
 * @brief Executa o teste funcional de Modelo Complexo.
 * * Verifica a conservação de valor em uma rede de múltiplos sistemas e fluxos.
 */
void complexFuncionalTest();

#endif // FUNCIONAL_TESTS_H
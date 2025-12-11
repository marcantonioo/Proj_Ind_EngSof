/**
 * @file unit_flow.h
 * @brief Declarações da classe de testes unitários da classe Flow.
 *
 * Esta classe contém declarações de todos os métodos que testam o
 * comportamento da classe Flow. Cada método deve ser definido em
 * unit_flow.cpp.
 */

#ifndef UNIT_FLOW_H
#define UNIT_FLOW_H

/**
 * @class UnitFlow
 * @brief Classe de testes unitários para a classe Flow.
 *
 * Esta classe contém métodos que testam os comportamentos da classe Flow,
 * incluindo construtores, getters, setters, evaluate() e operador de atribuição.
 */
class UnitFlow {
public:
    /// Construtor padrão
    UnitFlow() = default;

    /// Destrutor padrão
    ~UnitFlow() = default;

    /**
     * @brief Testa o construtor default da classe Flow.
     *
     * Verifica se source e target são nullptr e nome é vazio.
     */
    void test_flow_constructor_default();

    /**
     * @brief Testa o construtor que recebe um nome.
     *
     * Verifica se o nome foi atribuído corretamente e se source e target são nullptr.
     */
    void test_flow_constructor_nome();

    /**
     * @brief Testa os métodos setNome e getNome.
     */
    void test_flow_setNome();
    void test_flow_getNome();


    /**
     * @brief Testa os métodos setSource e getSource com um System real.
     */
    void test_flow_setSource();

    void test_flow_getSource();

    /**
     * @brief Testa os métodos setTarget e getTarget com um System real.
     */
    void test_flow_setTarget();
    void test_flow_getTarget();

    /**
     * @brief Testa os métodos setEquation e getEquation.
     */
    void test_flow_setEquation();
    void test_flow_getEquation();

    /**
     * @brief Testa o método evaluate() quando source está definido.
     */
    void test_flow_evaluate_with_source();

    /**
     * @brief Testa o método evaluate() quando source não está definido.
     *
     * Deve utilizar 0 como valor de entrada para a equação.
     */
    void test_flow_evaluate_without_source();

    /**
     * @brief Testa o operador de atribuição da classe Flow.
     *
     * Verifica se todos os atributos são copiados corretamente.
     */
    void test_flow_operator_assignment();
};

#endif // UNIT_FLOW_H

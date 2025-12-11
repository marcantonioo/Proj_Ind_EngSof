/**
 * @file unit_model.h
 * @brief Declarações da classe de testes da classe Model.
 *
 * Esta classe contém as declarações dos métodos que testam o comportamento
 * da classe Model, incluindo adição e remoção de Systems e Flows, além do método run().
 */

#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

/**
 * @class UnitModel
 * @brief Classe de testes unitários para a classe Model.
 *
 * Esta classe contém métodos que testam os comportamentos da classe Model,
 * incluindo adição e remoção de Systems e Flows, além do método run().
 */
class UnitModel {
public:
    /// Construtor padrão
    UnitModel() = default;

    /// Destrutor padrão
    ~UnitModel() = default;

    /**
     * @brief Testa o método add(Isystem*) da classe Model.
     */
    void test_model_add_system();

    /**
     * @brief Testa o método add(Iflow*) da classe Model.
     */
    void test_model_add_flow();

    /**
     * @brief Testa o método add(Isystem*, Iflow*) da classe Model.
     */
    void test_model_add_system_flow();

    /**
     * @brief Testa o método remove(Isystem*) da classe Model.
     */
    void test_model_remove_system();

    /**
     * @brief Testa o método remove(Iflow*) da classe Model.
     */
    void test_model_remove_flow();

    /**
     * @brief Testa o método run() da classe Model.
     */
    void test_model_run();
};

#endif // UNIT_MODEL_H

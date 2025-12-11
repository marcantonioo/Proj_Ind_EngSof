/**
 * @file unit_system.h
 * @brief Declarações da classe de testes da classe System.
 *
 * Esta classe contém os métodos que testam os comportamentos da classe System,
 * incluindo construtor, setValue, setNome e update.
 */

#ifndef UNIT_SYSTEM_H
#define UNIT_SYSTEM_H

class UnitSystem {
public:
    /// Construtor padrão
    UnitSystem() = default;

    /// Destrutor padrão
    ~UnitSystem() = default;

    /**
     * @brief Testa o construtor default da classe System.
     *
     * Verifica se o valor inicial é 0.0 e se o nome é uma string vazia.
     */
    void test_system_initial();

    /**
     * @brief Testa o método setValue da classe System.
     *
     * Define um valor e verifica se ele foi armazenado corretamente.
     */
    void test_system_setValue();

    /**
     * @brief Testa o método getValue da classe System.
     *
     * Obtém o valor atual e verifica se ele corresponde ao valor esperado.
     */
    void test_system_getValue();

    /**
     * @brief Testa o método setNome da classe System.
     *
     * Define um nome e verifica se ele foi armazenado corretamente.
     */
    void test_system_setNome();


    /**
     * @brief Testa o método getNome da classe System.
     *
     * Obtém o nome atual e verifica se ele corresponde ao nome esperado.
     */
    void test_system_getNome();


    /**
     * @brief Testa o método update da classe System.
     *
     * Atualiza o valor do System e verifica se a operação foi bem-sucedida.
     */
    void test_system_update();
};

#endif // UNIT_SYSTEM_H

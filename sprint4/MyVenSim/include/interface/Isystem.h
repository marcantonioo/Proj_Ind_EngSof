/* @file Isystem.h
 * @brief Declaração da interface Isystem.
 */
#ifndef ISYSTEM_H
#define ISYSTEM_H

#include <string>

using namespace std;

/**
 * @class Isystem
 * @brief Interface que define o comportamento de um sistema (System).
 *
 * A interface Isystem declara métodos para definir e obter o valor e nome do sistema,
 * bem como para atualizar seu valor.
 */
class Isystem {
public:

    virtual bool setValue(double valor) = 0;
    virtual double getValue() = 0;
    virtual bool setNome(string nome) = 0;
    virtual string getNome() = 0;
    virtual bool update(double value) = 0;
};

#endif
/* @file System.h
*   @brief Declaração da classe System.
*/
#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include "interface/Isystem.h"

using namespace std;

/**
 * @class System
 * @brief Implementação da interface Isystem que representa um sistema com valor e nome.
 *
 * A classe System implementa os métodos definidos na interface Isystem, permitindo
 * definir e obter o valor e nome do sistema, bem como atualizar seu valor.
 */
class System : public Isystem {
private:
    string nome;
    double valor;
public:
    System(string nome, double valor);
    System(string nome);
    System(double valor);
    System();
    System& operator=(System& other);
    ~System();

    bool setValue(double valor);
    double getValue();
    bool setNome(string nome);
    string getNome();
    bool update(double value);
};

#endif
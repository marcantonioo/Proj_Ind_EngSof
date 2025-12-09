/* @file Iflow.h
 * @brief Declaração da interface Iflow.
 */
#ifndef IFLOW
#define IFLOW


#include <functional>
#include <string>
#include "Isystem.h"

using namespace std;

/**
 * @class Iflow
 * @brief Interface que define o comportamento de um fluxo (Flow).
 *
 * A interface Iflow declara métodos para definir e obter o sistema de origem
 * e destino, nome, equação do fluxo e para avaliar o valor do fluxo.
 */
class Iflow{
public:
    virtual bool setSource(Isystem* s1) = 0;
    virtual bool setTarget(Isystem* s2) = 0;
    virtual Isystem* getSource() = 0;
    virtual Isystem* getTarget() = 0;
    virtual string getNome() = 0;
    virtual void setNome(string nome) = 0;
    virtual void setEquation (function<double(double)> equation) = 0;
    virtual const function<double(double)>& getEquation() const = 0;
    virtual double evaluate() = 0;
};

#endif
/* @file Imodel.h
 * @brief Declaração da interface Imodel.
 */

#ifndef IMODEL_H
#define IMODEL_H
#include "Iflow.h"
#include "Isystem.h"

/**
 * @class Imodel
 * @brief Interface que define o comportamento de um modelo (Model).
 *
 * A interface Imodel declara métodos para adicionar e remover sistemas e fluxos,
 * bem como para executar a simulação do modelo ao longo do tempo.
 */
class Imodel {
public:

    virtual bool add(Isystem*, Iflow*) = 0;
    virtual bool add(Isystem*) = 0;
    virtual bool add(Iflow*) = 0;
    virtual bool remove(Isystem*) = 0;
    virtual bool remove(Iflow*) = 0;
    virtual void run(double inicio, double fim, double ritmo) = 0;
};

#endif
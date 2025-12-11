/**
 * @file Imodel.h
 * @brief Interface que define o comportamento de um modelo (Model).
 * 
 * A interface Imodel declara métodos para adicionar e remover sistemas e fluxos,
 * bem como para executar a simulação do modelo ao longo do tempo.
 * 
 * @author Marco Antonio - 24.1.9002
 * @date June 2024
 */
#ifndef IMODEL_H
#define IMODEL_H
#include "Iflow.h"
#include "Isystem.h"
#include <functional>

/**
 * @class Imodel
 * @brief Interface que define o comportamento de um modelo (Model).
 *
 * A interface Imodel declara métodos para adicionar e remover sistemas e fluxos,
 * bem como para executar a simulação do modelo ao longo do tempo.
 */
class Imodel {
protected:
    virtual bool add(Isystem*, Iflow*) = 0;
    virtual bool add(Isystem*) = 0;
    virtual bool add(Iflow*) = 0;

public:
    static Imodel* createModel();
    virtual Isystem* createSystem(double = 0.0) = 0;
    template <typename T>
    Iflow* createFlow(Isystem * source = NULL, Isystem * target = NULL, function<double(double)> equation = nullptr){
        Iflow* flow = new T(source, target);
        flow->setEquation(equation);
        add(flow);
        return flow;
    }
    virtual bool remove(Isystem*) = 0;
    virtual bool remove(Iflow*) = 0;
    virtual void run(double inicio, double fim, double ritmo) = 0;
};

#endif
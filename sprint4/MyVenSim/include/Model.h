/* @file Model.h
 * @brief Declaração da classe Model.
 */
#ifndef MODEL_H
#define MODEL_H
#include "flow.h"
#include "System.h"
#include "interface/Imodel.h"

/**
 * @class Model
 * @brief Implementação da interface Imodel que representa um modelo de sistemas e fluxos.
 *
 * A classe Model implementa os métodos definidos na interface Imodel, permitindo
 * adicionar e remover sistemas e fluxos, bem como executar a simulação do modelo
 * ao longo do tempo.
 */
class Model : public Imodel{
private:
    vector<Iflow*> Flows;
    vector<Isystem*> Systems;
public:
    Model();
    ~Model();
    Model& operator=(const Model& other);

    bool add(Isystem*, Iflow*);
    bool add(Isystem*);
    bool add(Iflow*);
    bool remove(Isystem*);
    bool remove(Iflow*);
    void run(double inicio, double fim, double ritmo);
};

#endif
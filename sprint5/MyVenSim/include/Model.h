/**
 * @file Model.h
 * @brief Declaração da classe Model que implementa a interface Imodel.
 * 
 * A classe Model representa um modelo de sistemas e fluxos, permitindo
 * adicionar e remover sistemas e fluxos, bem como executar a simulação
 * do modelo ao longo do tempo.
 * 
 * @author Marco Antonio - 24.1.9002
 * @date June 2024
 */
#ifndef MODEL_H
#define MODEL_H
#include "interface/Iflow.h"
#include "interface/Isystem.h"
#include "System.h"
#include "flow.h"
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
protected:
    vector<Iflow*> Flows;
    vector<Isystem*> Systems;
    static std::vector<Model*> models;
    bool add(Isystem*, Iflow*) override;
    bool add(Isystem*) override;
    bool add(Iflow*) override;
    bool remove(Isystem*) override;
    bool remove(Iflow*) override;
    static bool add(Model* m);
public:
    Model();
    ~Model();
    Model& operator=(const Model& other);
    Isystem* createSystem(double value = 0.0) override;
    template <typename T>
    Iflow* createFlow(Isystem * source = NULL, Isystem * target = NULL, function<double(double)> equation = nullptr){
        Iflow* flow = new T(source, target);
        add(flow);
        return flow;
    }
    void run(double inicio, double fim, double ritmo);
    friend class UnitModel;
};

#endif
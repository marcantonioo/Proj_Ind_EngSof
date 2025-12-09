/* @file flow.h
 * @brief Declaração da classe Flow.
 */
#ifndef FLOW
#define FLOW

#include "interface/Iflow.h"
#include "System.h"
#include <functional>
#include <string>
#include "interface/Isystem.h"

using namespace std;

/**
 * @class Flow
 * @brief Implementação da interface Iflow que representa um fluxo entre dois sistemas.
 *
 * A classe Flow implementa os métodos definidos na interface Iflow, permitindo
 * definir e obter o sistema de origem e destino, nome, equação do fluxo e avaliar
 * o valor do fluxo com base na equação definida.
 */    
class Flow : public Iflow{
    private:
        string nome;
        Isystem* source;
        Isystem* target;
        function<double(double)> equation;
    public:
        Flow();
        Flow(string name);
        ~Flow();
        Flow& operator=(Flow&);
        bool setSource(Isystem* s1);
        bool setTarget(Isystem* s2);
        Isystem* getSource();
        Isystem* getTarget();
        string getNome();
        void setNome(string nome);
        void setEquation (function<double(double)> equation);
        const function<double(double)>& getEquation() const;
        double evaluate();
    };

#endif
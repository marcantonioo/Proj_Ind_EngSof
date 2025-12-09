/**
 * @file Model.cpp
 * @brief Implementação da classe Model, responsável pela gestão e execução da simulação.
 *
 * * A classe Model armazena e gerencia uma coleção de ISystem e IFlow e 
 * * coordena a execução da simulação em passos de tempo definidos.
 */
#include "../include/Model.h"
#include <algorithm>

/**
 * @brief Construtor padrão da classe Model.
 */
Model::Model(){}

/**
 * @brief Destrutor da classe Model.
 * * Note: O destrutor deve idealmente ser responsável por liberar a memória 
 * * dos Sistemas e Fluxos que ele possui (se não estiver usando smart pointers).
 */
Model::~Model(){}

/**
 * @brief Operador de atribuição (cópia rasa, Shallow Copy).
 * * Copia as listas de ponteiros (Flows e Systems) da outra Model.
 * * **AVISO:** Este é um 'shallow copy' dos ponteiros. Deve-se garantir que 
 * * os objetos apontados não sejam liberados duas vezes.
 * @param other O objeto Model a ser copiado.
 * @return Model& Uma referência para o objeto Model atual (this).    
 */
Model& Model::operator=(const Model& other){
    if (this == &other) return *this;
    Flows = other.Flows;
    Systems = other.Systems;
    return *this;    
}

/**
 * @brief Remove e libera a memória de um sistema da coleção.
 * * Procura o ponteiro Isystem* na lista Systems. Se encontrado, ele é removido
 * * da lista e sua memória é liberada usando `delete`.
 * @param f O ponteiro para o sistema (Isystem*) a ser removido.
 * @return bool Retorna true se o sistema foi encontrado e removido, false caso contrário.
 */
bool Model::remove(Isystem* f){
    auto it = std::find(Systems.begin(), Systems.end(), f);
    if (it !=Systems.end()){
        Isystem* ptr = *it;
        Systems.erase(it);
        delete ptr;
        return true;
    }
    return false;

}

/**
 * @brief Remove e libera a memória de um fluxo da coleção.
 * * Procura o ponteiro Iflow* na lista Flows. Se encontrado, ele é removido
 * * da lista e sua memória é liberada usando `delete`.
 * @param f O ponteiro para o fluxo (Iflow*) a ser removido.
 * @return bool Retorna true se o fluxo foi encontrado e removido, false caso contrário.
 */
bool Model::remove(Iflow* f){
    auto it = std::find(Flows.begin(), Flows.end(), f);
    if (it !=Flows.end()){
        Iflow* ptr = *it;
        Flows.erase(it);
        delete ptr;
        return true;
    }
    return false;

}

/**
 * @brief Adiciona um novo sistema à coleção.
 * @param sistema O ponteiro para o sistema (Isystem*) a ser adicionado.
 * @return bool Retorna true se a adição foi bem-sucedida, false caso contrário.
 */
bool Model::add(Isystem* sistema){
    Systems.push_back(sistema);
    if (find(Systems.begin(), Systems.end(), sistema) != Systems.end()) return true;
    return false;
}

/**
 * @brief Adiciona um novo fluxo à coleção.
 * @param flow O ponteiro para o fluxo (Iflow*) a ser adicionado.
 * @return bool Retorna true se a adição foi bem-sucedida, false caso contrário.
 */
bool Model::add(Iflow* flow){
    Flows.push_back(flow);
    if (find(Flows.begin(), Flows.end(), flow) != Flows.end()) return true;
    return false;
}

/**
 * @brief Adiciona um sistema e um fluxo simultaneamente.
 * @param sistema O ponteiro para o sistema (Isystem*) a ser adicionado.
 * @param flow O ponteiro para o fluxo (Iflow*) a ser adicionado.
 * @return bool Retorna true se ambos foram adicionados com sucesso, false caso contrário.
 */
bool Model::add(Isystem* sistema, Iflow* flow){
    Flows.push_back(flow);
    Systems.push_back(sistema);
    if (find(Flows.begin(), Flows.end(), flow) != Flows.end() && find(Systems.begin(), Systems.end(), sistema) != Systems.end()) return true;
    return false;
}

/**
 * @brief Executa a simulação dinâmica do modelo.
 * * * O método realiza a simulação do tempo de `inicio` até `fim`, usando 
 * * `ritmo` (passo de tempo, ou dt) para cada iteração.
 * * 1. Calcula os valores de todos os fluxos na iteração atual.
 * * 2. Atualiza os valores dos Sistemas de Origem (Source) e Destino (Target) 
 * * para cada fluxo usando a diferença de Euler (integração).
 * * @param inicio O tempo inicial da simulação.
 * @param fim O tempo final da simulação (exclusivo).
 * @param ritmo O tamanho do passo de tempo (dt) para a integração.
 */
void Model::run(double inicio, double fim, double ritmo){
    

    for (double i = inicio; i< fim; i+=ritmo){
        vector<double> resultado;
        for (auto it : Flows){
            resultado.push_back(it->evaluate());
        }
        for (size_t j = 0; j < Flows.size(); j++){
            auto f = Flows[j];
            if(f->getSource())
                f->getSource()->update(f->getSource()->getValue() - resultado[j]);
            if(f->getTarget())
                f->getTarget()->update(f->getTarget()->getValue() + resultado[j]);
        }
    }
}
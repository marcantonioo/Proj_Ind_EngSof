/**
 * @file Flow.cpp
 * @brief Implementação da classe Flow para simulação de Dinâmica de Sistemas.
 *
 * * Contém a lógica para calcular a taxa de fluxo entre dois sistemas (source e target)
 * * com base em uma equação matemática fornecida.
 */
#include "../include/flow.h"
#include <math.h>

/**
 * @brief Destrutor da classe Flow.
 */
Flow::~Flow(){}

/**
 * @brief Construtor padrão.
 * Inicializa o nome como vazio e os ponteiros source, target e equation como nulos.
 */
Flow::Flow(): source(nullptr), target(nullptr), equation(nullptr){this->nome = "";}

/**
 * @brief Construtor com nome.
 * @param nome O nome atribuído a este fluxo.
 */
Flow::Flow(string nome):source(nullptr), target(nullptr), equation(nullptr) {this->nome = nome;}

/**
 * @brief Operador de atribuição (cópia).
 * * Este operador copia o nome, a equação, e os ponteiros de source e target 
 * do objeto 'other' para o objeto atual.
 * * @param other A referência para o objeto Flow a ser copiado.
 * @return Flow& Uma referência para o objeto atual (this).
 */
Flow& Flow::operator= (Flow& other){
    if (this == &other) return *this;
    this->setEquation(other.getEquation());
    setSource(other.getSource());
    setTarget(other.getTarget());
    setNome(other.getNome());
    return *this;
}

/**
 * @brief Define o sistema de origem (Source) para este fluxo.
 * @param s1 Um ponteiro para o sistema de origem (Isystem*).
 * @return bool Retorna true em caso de sucesso.
 */
bool Flow::setSource(Isystem* s1){this->source = s1; return true;}

/**
 * @brief Define o sistema de destino (Target) para este fluxo.
 * @param s2 Um ponteiro para o sistema de destino (Isystem*).
 * @return bool Retorna true em caso de sucesso.
 */
bool Flow::setTarget(Isystem* s2){this->target = s2; return true;}

/**
 * @brief Obtém o sistema de origem (Source).
 * @return Isystem* O ponteiro para o sistema de origem.
 */
Isystem* Flow::getSource(){return source;}

/**
 * @brief Obtém o sistema de destino (Target).
 * @return Isystem* O ponteiro para o sistema de destino.
 */
Isystem* Flow::getTarget(){return target;}

/**
 * @brief Obtém o nome do fluxo.
 * @return string O nome do fluxo.
 */
string Flow::getNome(){return nome;}

/**
 * @brief Define o nome do fluxo.
 * @param nome A nova string de nome para o fluxo.
 */
void Flow::setNome(string nome){this->nome = nome;}

/**
 * @brief Define a equação (função matemática) que calcula a taxa do fluxo.
 * @param equation Uma função (lambda ou std::function) que recebe um double 
 * (o valor do Source) e retorna um double (a taxa de fluxo).
 */
void Flow::setEquation (function<double(double)> equation){this->equation = equation;}

/**
 * @brief Obtém a equação de cálculo da taxa do fluxo.
 * @return const std::function<double(double)>& A referência constante para a função de equação.
 */
const function<double(double)>& Flow::getEquation() const {return equation;}

/**
 * @brief Avalia e calcula a taxa de fluxo atual.
 * * Se o sistema de origem (source) estiver definido, a equação é aplicada 
 * ao valor atual desse sistema. Caso contrário, a equação é aplicada a 0.
 * * @return double O valor calculado da taxa de fluxo.
 */
double Flow::evaluate(){
    if (source) 
        return equation(source->getValue());
    return equation(0);
}
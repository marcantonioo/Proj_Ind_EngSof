/**
 * @file System.cpp
 * @brief Implementação da classe System.
 *
 * * A classe System representa um "estoque" (stock) ou variável de estado em um modelo
 * * de Dinâmica de Sistemas, possuindo um valor numérico e um nome.
 */
#include "../include/System.h"

/**
 * @brief Construtor que inicializa o nome e o valor do sistema.
 * @param nome O nome do sistema.
 * @param valor O valor inicial do sistema.
 */
System::System(string nome, double valor): nome(nome), valor(valor){}

/**
 * @brief Construtor que inicializa apenas o nome, definindo o valor como 0.
 * @param nome O nome do sistema.
 */
System::System(string nome):nome(nome){valor = 0;}

/**
 * @brief Construtor que inicializa apenas o valor, definindo o nome como vazio.
 * @param valor O valor inicial do sistema.
 */
System::System(double valor):valor(valor){nome = "";}

/**
 * @brief Construtor padrão, inicializa nome como vazio e valor como 0.
 */
System::System():nome(""), valor(0){}

/**
 * @brief Destrutor da classe System.
 */
System::~System(){}

/**
 * @brief Operador de atribuição (cópia).
 * * Copia o nome e o valor do sistema 'other' para o sistema atual.
 * @param other A referência para o objeto System a ser copiado.
 * @return System& Uma referência para o objeto System atual (this).
 */
System& System::operator=(System& other){
    if (this == &other)
        return *this;
    this->setNome(other.getNome());
    this->setValue(other.getValue());
    return *this;
}


/**
 * @brief Define um novo valor para o sistema.
 * @param valor O novo valor a ser atribuído.
 * @return bool Retorna true se o valor foi atribuído com sucesso.
 */
bool System::setValue(double valor){
    this->valor = valor;
    return this->valor == valor;
}

/**
 * @brief Obtém o valor atual do sistema.
 * @return double O valor atual.
 */
double System::getValue(){
    return valor;
}

/**
 * @brief Obtém o nome do sistema.
 * @return string O nome do sistema.
 */
string System::getNome(){return nome;}

/**
 * @brief Define um novo nome para o sistema.
 * @param nome O novo nome a ser atribuído.
 * @return bool Retorna true se o nome foi atribuído com sucesso.
 */
bool System::setNome(string nome){this->nome = nome; return this->nome == nome;}

/**
 * @brief Atualiza o valor do sistema.
 * * Este método é um alias para setValue(value), usado tipicamente durante a simulação.
 * @param value O novo valor para atualização.
 * @return bool Retorna true se a atualização foi bem-sucedida.
 */
bool System::update(double value){return this->setValue(value);}
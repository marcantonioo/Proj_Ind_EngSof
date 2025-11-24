#include "System.h"

System::System(string nome, double valor): nome(nome), valor(valor){}
System::System(string nome):nome(nome){valor = 0;}
System::System(double valor):valor(valor){nome = "";}
System::System(){valor = 0; nome = "";}
System::~System(){}
System& System::operator=(System& other){
    if (this == &other)
        return *this;
}


bool System::setValue(double valor){
    this->valor = valor;
    return this->valor == valor;
}
double System::getValue(){
    return valor;
}

string System::getNome(){return nome;}
bool System::setNome(string nome){this->nome = nome; return this->nome == nome;}
bool System::update(double value){return this->setValue(value);}


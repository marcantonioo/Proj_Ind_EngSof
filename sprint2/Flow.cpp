#include "flow.h"


Flow::~Flow(){}

Flow::Flow(string nome){nome = nome;}
Flow& Flow::operator= (Flow& other){
    if (this == &other) return;
    if (this != &other){
        this->setEquation(other.getEquation());
        other.setSource(source);
        other.setTarget(target);
        other.setNome(nome);
    }
}

bool Flow::setSource(System* s1){this->source = s1;}
bool Flow::setTarget(System* s2){this->target = s2;}
System* Flow::getSource(){return source;}
System* Flow::getTarget(){return target;}
string Flow::getNome(){return nome;}
void Flow::setNome(string nome){this->nome = nome;}
void Flow::setEquation (function<double()> equation){this->equation = equation;}
const function<double()>& Flow::getEquation() const {return equation;}
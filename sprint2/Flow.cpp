#include "flow.h"


Flow::~Flow(){}

Flow::Flow(string nome){nome = nome;}
Flow& Flow::operator= (Flow& s1){
    if (this == &s1) return;
    if (this != &s1){
        this->setEquation(s1.getEquation());
        s1.setSource(source);
        s1.setTarget(target);
        s1.setNome(nome);
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
#include "../include/Model.h"
#include <algorithm>

Model::Model(){}
Model::~Model(){}
Model& Model::operator=(const Model& other){
    if (this == &other) return *this;
    Flows = other.Flows;
    Systems = other.Systems;
    return *this;    
}

bool Model::remove(System* f){
    auto it = std::find(Systems.begin(), Systems.end(), f);
    if (it !=Systems.end()){
        System* ptr = *it;
        Systems.erase(it);
        delete ptr;
        return true;
    }
    return false;

}
bool Model::remove(Flow* f){
    auto it = std::find(Flows.begin(), Flows.end(), f);
    if (it !=Flows.end()){
        Flow* ptr = *it;
        Flows.erase(it);
        delete ptr;
        return true;
    }
    return false;

}

bool Model::add(System* sistema){
    Systems.push_back(sistema);
    if (find(Systems.begin(), Systems.end(), sistema) != Systems.end()) return true;
    return false;
}
bool Model::add(Flow* flow){
    Flows.push_back(flow);
    if (find(Flows.begin(), Flows.end(), flow) != Flows.end()) return true;
    return false;
}

bool Model::add(System* sistema, Flow* flow){
    Flows.push_back(flow);
    Systems.push_back(sistema);
    if (find(Flows.begin(), Flows.end(), flow) != Flows.end() && find(Systems.begin(), Systems.end(), sistema) != Systems.end()) return true;
    return false;
}
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
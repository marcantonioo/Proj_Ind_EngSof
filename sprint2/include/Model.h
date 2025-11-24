#ifndef MODEL_H
#define MODEL_H
#include "flow.h"
#include "System.h"

class Model {
private:
    vector<Flow*> Flows;
    vector<System*> Systems;
public:
    Model();
    ~Model();
    Model& operator=(const Model& other);

    bool add(System*, Flow*);
    bool add(System*);
    bool add(Flow*);
    bool remove(System*, Flow*);
    bool remove(System*);
    bool remove(Flow*);
    void run(double inicio, double fim, double ritmo);
};

#endif
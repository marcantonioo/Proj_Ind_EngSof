#include "system.h"
#include <functional>
#include <string>

using namespace std;

    class Flow{
    private:
        string nome;
        System* source;
        System* target;
        function<double()> equation;
    public:
        Flow(string name);
        ~Flow();
        Flow& operator=(const Flow&);
        bool setSource(System* s1);
        bool setTarget(System* s2);
        System* getSource();
        System* getTarget();
        void setEquation (function<double()> equation);
        double evaluate();
    };
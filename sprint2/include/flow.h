#include "System.h"
#include <functional>
#include <string>

using namespace std;

    class Flow{
    private:
        string nome;
        System* source;
        System* target;
        function<double(double)> equation;
    public:
        Flow();
        Flow(string name);
        ~Flow();
        Flow& operator=(Flow&);
        bool setSource(System* s1);
        bool setTarget(System* s2);
        System* getSource();
        System* getTarget();
        string getNome();
        void setNome(string nome);
        void setEquation (function<double(double)> equation);
        const function<double(double)>& getEquation() const;
        double evaluate();
    };
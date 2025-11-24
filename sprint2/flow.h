#include "System.h"
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
        Flow& operator=(Flow&);
        bool setSource(System* s1);
        bool setTarget(System* s2);
        System* getSource();
        System* getTarget();
        string getNome();
        void setNome(string nome);
        void setEquation (function<double()> equation);
        const function<double()>& getEquation() const;
        virtual double evaluate() = 0;
    };
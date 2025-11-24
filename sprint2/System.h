#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System {
private:
    string nome;
    double valor;
public:
    System(string nome, double valor);
    System(string nome);
    System(double valor);
    System();
    System& System::operator=(System& other);
    ~System();

    bool setValue(double valor);
    double getValue();
    bool setNome(string nome);
    string getNome();
    bool update(double value);
};

#endif
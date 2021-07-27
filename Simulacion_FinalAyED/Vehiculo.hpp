#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>

using namespace std;

class Vehiculo {
    private:
        string _marca;
        string _color;
    public:
        Vehiculo(string marca, string color);
        string getMarca();
        string getColor();
        virtual void arrancar() = 0;
        virtual void parar() = 0;
        virtual void repostar() = 0;
        virtual ~Vehiculo();
};

#endif // VEHICULO_H
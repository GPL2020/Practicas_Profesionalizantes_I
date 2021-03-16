#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>

using namespace std;

class Vehiculo {
    public:
        Vehiculo();
        virtual ~Vehiculo();
        virtual void getColor() = 0;
        virtual void getMarca() = 0;
        virtual void arrancar() = 0;
        virtual void parar() = 0;
        virtual void repostar() = 0;
};

#endif // VEHICULO_H

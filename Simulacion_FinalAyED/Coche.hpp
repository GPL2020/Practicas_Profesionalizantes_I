#ifndef COCHE_H
#define COCHE_H
#include "Vehiculo.hpp"

class Coche: public Vehiculo {
    private:
        int _motor;
    public:
        Coche(int motor, std::string marca, std::string color);
        void arrancar();
        void parar();
        void repostar();
        virtual ~Coche();
};

#endif // COCHE_H
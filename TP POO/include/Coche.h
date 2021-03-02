#ifndef COCHE_H
#define COCHE_H
#include "Vehiculo.h"

class Coche: public Vehiculo {
    private:
        string m_color;
        string m_marca;
        int m_motor;
    public:
        Coche(string color, string marca, int motor);
        virtual ~Coche();
        void arrancar();
        void parar();
        void repostar();
};

#endif // COCHE_H

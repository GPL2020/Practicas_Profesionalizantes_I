#ifndef MOTO_H
#define MOTO_H
#include "Vehiculo.h"

class Moto: public Vehiculo {
    private:
        string m_color;
        string m_marca;
        int m_cilindrada;
    public:
        Moto(string color, string marca, int cilindrada);
        virtual ~Moto();
        void getColor();
        void getMarca();
        void arrancar();
        void parar();
        void repostar();
};

#endif // MOTO_H

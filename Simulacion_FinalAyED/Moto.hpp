#ifndef MOTO_H
#define MOTO_H
#include "Vehiculo.hpp"

class Moto: public Vehiculo {
    private:
        int _cilindrada;
    public:
        Moto(int cil, std::string marca, std::string color);
        void arrancar();
        void parar();
        void repostar();
        virtual ~Moto();
};

#endif // MOTO_H
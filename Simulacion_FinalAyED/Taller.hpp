#ifndef TALLER_H
#define TALLER_H
#include "Vehiculo.hpp"
#define MAX 20

class Taller {
    private:
        int max_vehiculos = MAX;
        int num_vehiculos;

        Vehiculo *vehiculosEnTaller[MAX];

    public:
        Taller();
        void meter(Vehiculo *v);
        void arreglarVehiculos();
        virtual ~Taller();
};

#endif // TALLER_H
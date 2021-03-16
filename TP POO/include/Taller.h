#ifndef TALLER_H
#define TALLER_H
#include "Vehiculo.h"
#include "ListaVehiculos.h"

class Taller {
    private:
        int num_vehiculos;
        ListaVehiculos vehiculosTaller;

    public:
        Taller();
        Taller(int numVehiculos);
        virtual ~Taller();
        void meter(Vehiculo* v);
        void arreglarVehiculos();
};

#endif // TALLER_H

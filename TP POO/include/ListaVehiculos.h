#ifndef LISTAVEHICULOS_H
#define LISTAVEHICULOS_H
#include "Vehiculo.h"


class ListaVehiculos {
    private:
        static const int MAX_VEHICULOS_TALLER = 250;
        int cont;
        Vehiculo *lista[MAX_VEHICULOS_TALLER];
    public:
        ListaVehiculos();
        void mostrarVehiculo(int pos);
        void add(Vehiculo *v);
        int cantVehiculos();
        virtual ~ListaVehiculos();
};

#endif // LISTAVEHICULOS_H

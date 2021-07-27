#include "Taller.hpp"

Taller::Taller() {
    num_vehiculos = 0;
}

void Taller::meter(Vehiculo *v) {
    if (num_vehiculos < max_vehiculos) {
        vehiculosEnTaller[num_vehiculos] = v;
        num_vehiculos++;
    }
    else
        cout << "Taller lleno" << endl;
}

void Taller::arreglarVehiculos() {
    for (int i = 0; i < num_vehiculos; i++) {
        vehiculosEnTaller[i]->arrancar();
    }
}

Taller::~Taller() {
}
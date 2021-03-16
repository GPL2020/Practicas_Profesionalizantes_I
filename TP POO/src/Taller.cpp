#include "../include/Taller.h"

Taller::Taller() {

}

Taller::Taller(int numVehiculos) {
    num_vehiculos = numVehiculos;
}

Taller::~Taller() {
    //por cada componente vehiculo invocar al operador delete...
}

void Taller::meter(Vehiculo* v) {
    //lista_de_vehiculos.add(v);
    vehiculosTaller.add(v);
    cout << "Ingreso un nuevo Vehiculo al Taller" << endl;
    num_vehiculos++;

}

void Taller::arreglarVehiculos() {
    //por cada vehículo de la lista invocar el método arrancar...
    for (int i = 0; i < vehiculosTaller.cantVehiculos(); i++) {
        cout << "Vehiculo arreglado: ";
        vehiculosTaller.mostrarVehiculo(i);
    }
}

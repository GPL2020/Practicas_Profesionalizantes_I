#include "Taller.h"

Taller::Taller() {

}

Taller::Taller(int maxVehiculos, int numVehiculos) {
    max_vehiculos = maxVehiculos;
    num_vehiculos = numVehiculos;
}

Taller::~Taller() {
    //por cada componente vehiculo invocar al operador delete...
}

void Taller::meter(Vehiculo* v) {
    //lista_de_vehiculos.add(v);
}

void Taller::arreglarVehiculos() {
    //por cada vehículo de la lista invocar el método arrancar...
}

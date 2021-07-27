#include "Taller.hpp"
#include "Moto.hpp"
#include "Coche.hpp"
#include <iostream>

using namespace std;

int main() {
    Taller tallerMecanico;

    Vehiculo *auto1 = new Coche(100, "Ford", "blanco");
    Vehiculo *auto2 = new Coche(150, "Chevrolet", "rojo");
    Vehiculo *moto1 = new Moto(149, "Honda", "negra");
    Vehiculo *moto2 = new Moto(250, "Zanella", "azul");

    tallerMecanico.meter(auto1);
    tallerMecanico.meter(moto1);
    tallerMecanico.meter(auto2);
    tallerMecanico.meter(moto2);

    tallerMecanico.arreglarVehiculos();

    delete auto1;
    delete auto2;
    delete moto1;
    delete moto2;
    
    return 0;
}

